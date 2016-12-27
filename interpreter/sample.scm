((lambda ()
   (define (eval exp env) ((analyze exp) env))
   (define (analyze exp)
     (if (eof-object? exp)
         (exit)
         (if (self-evaluating? exp)
             (analyze-self-evaluating exp)
             (if (variable? exp)
                 (analyze-variable exp)
                 (if (quoted? exp)
                     (analyze-quoted exp)
                     (if (lambda? exp)
                         (analyze-lambda exp)
                         (if (definition? exp)
                             (analyze-definition exp)
                             (if (assignment? exp)
                                 (analyze-assignment exp)
                                 (if (if? exp)
                                     (analyze-if exp)
                                     (if (begin? exp)
                                         (analyze-sequence (begin-actions exp))
                                         (if (application? exp)
                                             (analyze-application exp)
                                             (error
                                              "unknown expression type -- analyze"
                                              exp))))))))))))

   (define (analyze-self-evaluating exp) (lambda (env) exp))
   (define (analyze-variable exp) (lambda (env) (lookup-variable-value exp env)))
   (define (analyze-quoted exp)
     ((lambda (qval)
        (lambda (env) qval))
      (text-of-quotation exp)))
   (define (analyze-lambda exp)
     ((lambda (vars bproc)
        (lambda (env) (make-procedure vars bproc env)))
      (lambda-parameters exp)
      (analyze-sequence (lambda-body exp))))
   (define (analyze-definition exp)
     ((lambda (var vproc)
        (lambda (env)
          (define-variable! var (vproc env) env)))
      (definition-variable exp)
      (analyze (definition-value exp))))
   (define (analyze-assignment exp)
     ((lambda (var vproc)
        (lambda (env)
          (set-variable-value! var (vproc env) env)))
      (assignment-variable exp)
      (analyze (assignment-value exp))))
   (define (analyze-if exp)
     ((lambda (pproc cproc aproc)
        (lambda (env)
          (if (pproc env)
              (cproc env)
              (aproc env))))
      (analyze (if-predicate exp))
      (analyze (if-consequent exp))
      (analyze (if-alternative exp))))
   (define (map proc list)
     (if (null? list)
         '()
         (cons (proc (car list))
               (map proc (cdr list)))))
   (define (analyze-sequence exps)
     (define (sequentially proc1 proc2)
       (lambda (env) (proc1 env) (proc2 env)))
     (define (loop first-proc rest-procs)
       (if (null? rest-procs)
           first-proc
           (loop (sequentially first-proc (car rest-procs))
                 (cdr rest-procs))))
     ((lambda (procs)
        (if (null? procs)
            (error "empty sequence -- analyze"))
        (loop (car procs) (cdr procs)))
      (map analyze exps)))

   (define (analyze-application exp)
     ((lambda (pproc aprocs)
        (lambda (env)
          (execute-application (pproc env)
                               (map (lambda (aproc) (aproc env))
                                    aprocs))))
      (analyze (operator exp))
      (map analyze (operands exp))))
   (define (execute-application proc args)
     (if (primitive-procedure? proc)
         (c-apply (primitive-implementation proc) args)
         (if (compound-procedure? proc)
             ((procedure-body proc)
              (extend-environment (procedure-parameters proc)
                                  args
                                  (procedure-environment proc)))
             (error "unknown procedure type -- execute-application" proc))))

   (define (self-evaluating? exp)
     (or (boolean? exp)
         (number? exp)
         (vector? exp)
         (char? exp)
         (string? exp)
         (bytevector? exp)
         (procedure? exp)
         (eq? exp (if #f '()))))
   (define (variable? exp) (symbol? exp))
   (define (quoted? exp) (tagged-list? exp 'quote))
   (define (text-of-quotation exp) (car (cdr exp)))
   (define (tagged-list? exp tag)
     (if (pair? exp)
         (eq? (car exp) tag)
         #f))
   
   (define (lambda? exp) (tagged-list? exp 'lambda))
   (define (lambda-parameters exp) (car (cdr exp)))
   (define (lambda-body exp) (cdr (cdr exp)))
   (define (make-lambda parameters body) (cons 'lambda (cons parameters body)))

   (define (if? exp) (tagged-list? exp 'if))
   (define (if-predicate exp) (car (cdr exp)))
   (define (if-consequent exp) (car (cdr (cdr exp))))
   (define (if-alternative exp)
     (if (not (null? (cdr (cdr (cdr exp)))))
         (car (cdr (cdr (cdr exp))))))

   (define (begin? exp) (tagged-list? exp 'begin))
   (define (begin-actions exp) (cdr exp))

   (define (application? exp) (pair? exp))
   (define (operator exp) (car exp))
   (define (operands exp) (cdr exp))
   
   (define (definition? exp) (tagged-list? exp 'define))
   (define (definition-variable exp)
     (if (symbol? (car (cdr exp)))
         (car (cdr exp))
         (car (car (cdr exp)))))
   (define (definition-value exp)
     (if (symbol? (car (cdr exp)))
         (car (cdr (cdr exp)))
         (make-lambda (cdr (car (cdr exp)))
                      (cdr (cdr exp)))))
   (define (assignment? exp) (tagged-list? exp 'set!))
   (define (assignment-variable exp) (car (cdr exp)))
   (define (assignment-value exp) (car (cdr (cdr exp))))
   (define (first-frame env) (car env))
   (define the-empty-environment '())
   (define (make-frame variables values) (cons variables values))
   (define (frame-variables frame) (car frame))
   (define (frame-values frame) (cdr frame))
   (define (add-binding-to-frame! var val frame)
     (set-car! frame (cons var (car frame)))
     (set-cdr! frame (cons val (cdr frame))))   
   (define (define-variable! var val env)
     ((lambda (frame)
        (define (scan vars vals)
          (if (null? vars)
              (add-binding-to-frame! var val frame)
              (if (eq? var (car vars))
                  (set-car! vals val)
                  (scan (cdr vars) (cdr vals)))))
        (scan (frame-variables frame)
              (frame-values frame)))
      (first-frame env)))
   (define (set-variable-value! var val env)
     (define (env-loop env)
       (define (scan vars vals)
         (if (null? vars)
             (env-loop (enclosing-environment env))
             (if (eq? var (car vars))
                 (set-car! vals val)
                 (scan (cdr vars) (cdr vals)))))
       (if (eq? env the-empty-environment)
           (error "(set!) unbound variable --" var)
           ((lambda (frame)
              (scan (frame-variables frame)
                    (frame-values frame)))
            (first-frame env))))
     (env-loop env))
   
   (define (make-procedure parameters body env)
     (list 'procedure parameters body env))
   (define (compound-procedure? p) (tagged-list? p 'procedure))
   (define (procedure-parameters p) (car (cdr p)))
   (define (procedure-body p) (car (cdr (cdr p))))
   (define (procedure-environment p) (car (cdr (cdr (cdr p)))))
   
   (define (enclosing-environment env) (cdr env))
   (define (extend-environment vars vals base-env)
     (define (iter vars-0 vals-0 vars-1 vals-1)
       (if (symbol? vars-0)
           (cons (make-frame (cons vars-0 vars-1)
                             (cons vals-0 vals-1))
                 base-env)
           (if (null? vars-0)
               (if (null? vals-0)
                   (cons (make-frame vars-1 vals-1) base-env)
                   (error "Too many arguments supplied" vars vals))
               (if (null? vals-0)
                   (error "Too few arguments supplied" vars vals)
                   (iter (cdr vars-0)
                         (cdr vals-0)
                         (cons (car vars-0) vars-1)
                         (cons (car vals-0) vals-1))))))
     (iter vars vals '() '()))
   (define (lookup-variable-value var env)
     (define (env-loop env)
       (define (scan vars vals)
         (if (null? vars)
             (env-loop (enclosing-environment env))
             (if (eq? var (car vars))
                 (car vals)
                 (scan (cdr vars) (cdr vals)))))
       (if (eq? env the-empty-environment)
           (error "unbound variable" var)
           ((lambda (frame)
              (scan (frame-variables frame)
                    (frame-values frame)))
            (first-frame env))))
     (env-loop env))

   (define (primitive-procedure? proc) (tagged-list? proc 'primitive))
   (define (primitive-implementation proc) (car (cdr proc)))
   (define primitive-procedures
     (list (list 'car car)
           (list 'cdr cdr)
           (list 'cons cons)
           ))
   (define (primitive-procedure-names) (map car primitive-procedures))
   (define (primitive-procedure-objects)
     (map (lambda (proc)
            (list 'primitive (car (cdr proc))))
          primitive-procedures))

   (define (setup-environment)
     ((lambda (initial-env)        
        (define-variable! 'quote quote initial-env)
        (define-variable! 'lambda lambda initial-env)
        (define-variable! 'define define initial-env)
        (define-variable! 'set! set! initial-env)
        (define-variable! 'if if initial-env)
        (define-variable! 'begin begin initial-env)
        initial-env)
      (extend-environment
       (primitive-procedure-names)
       (primitive-procedure-objects)
       the-empty-environment)))
   
   (define the-global-environment (setup-environment))

   (define input-prompt "> ")
   (define output-prompt "=> ")
   (define input-port (current-input-port))
   (define output-port (current-output-port))   
   (define (driver-loop)
     (prompt-for-input input-prompt)
     ((lambda (input)
        ((lambda (output)
           (announce-output output-prompt)
           (user-print output))
         (eval input the-global-environment)))
      (read input-port))
     (driver-loop))
   (define (prompt-for-input string)
     (display string output-port))
   (define (announce-output string)
     (display string output-port))
   (define (user-print object)
     (if (compound-procedure? object)
         (begin (display '|#<compound-procedure | output-port)
                (write (procedure-parameters object) output-port)
                (write '> output-port))
         (write object output-port))
     (newline output-port))   
   
   (driver-loop)
   ))
