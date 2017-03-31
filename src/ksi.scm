(begin
  (load "./lib/stdlib/base.scm")
  (load "./lib/stdlib/cxr.scm")
  (define apply-in-underlying-scheme apply)
  (define error-in-underlying-scheme error)

  (define (error message . objs)
    (display "ERROR: ")
    (display message)
    (define (iter objs)
      (if (null? objs)
          (begin
            (newline)
            (driver-loop))
          (begin
            (display " ")
            (write (car objs))
            (iter (cdr objs)))))
    (iter objs))
  
  (define (eval exp env)
    (cond ((self-evaluating? exp) exp)
          ((variable? exp) (lookup-variable-value exp env))
          ((quoted? exp) (text-of-quotation exp))
          ((assignment? exp) (eval-assignment exp env))
          ((definition? exp) (eval-definition exp env))
          ((if? exp) (eval-if exp env))
          ((lambda? exp)
           (make-procedure (lambda-parameters exp)
                           (lambda-body exp)
                           env))
          ((begin? exp)
           (eval-sequence (begin-actions exp) env))
          ((cond? exp) (eval (cond->if exp) env))
          ((and? exp) (eval (and->if (cdr exp)) env))
          ((or? exp) (eval (or->if (cdr exp)) env))
          ((load? exp) (eval (load->exp exp) env))
          ((application? exp)
           (apply (eval (operator exp) env)
                  (list-of-values (operands exp) env)))
          (#t
           (error "unknown expression type -- eval" exp))))

  (define (apply procedure arguments)
    (cond ((primitive-procedure? procedure)
           (apply-primitive-procedure procedure arguments))
          ((compound-procedure? procedure)
           (eval-sequence
            (procedure-body procedure)
            (extend-environment
             (procedure-parameters procedure)
             arguments
             (procedure-environment procedure))))
          (#t
           (error
            "unknown procedure type -- apply" procedure))))

  (define (list-of-values exps env)
    (if (no-operands? exps)
        '()
        (cons (eval (first-operand exps) env)
              (list-of-values (rest-operands exps) env))))

  (define (eval-if exp env)
    (if (eval (if-predicate exp) env)
        (eval (if-consequent exp) env)
        (eval (if-alternative exp) env)))
  

  (define (eval-sequence exps env)
    (if (last-exp? exps)
        (eval (first-exp exps) env)
        ((lambda ()
           (eval (first-exp exps) env)
           (eval-sequence (rest-exps exps) env)))))
  
  (define (eval-assignment exp env)
    (set-variable-value! (assignment-variable exp)
                         (eval (assignment-value exp) env)
                         env))

  (define (eval-definition exp env)
    (define-variable!
      (definition-variable exp)
      (eval (definition-value exp) env)
      env))
  
  (define (self-evaluating? exp)
    (or (number? exp)
        (char? exp)
        (string? exp)
        (boolean? exp)
        (vector? exp)
        (eq? exp (if #f #f))))

  (define (variable? exp) (symbol? exp))

  (define (quoted? exp)
    (tagged-list? exp 'quote))

  (define (text-of-quotation exp) (cadr exp))
  
  (define (tagged-list? exp tag)
    (if (pair? exp)
        (eq? (car exp) tag)
#f))

  (define (assignment? exp)
    (tagged-list? exp 'set!))

  (define (assignment-variable exp) (cadr exp))

  (define (assignment-value exp) (caddr exp))

  (define (definition? exp)
    (tagged-list? exp 'define))

  (define (definition-variable exp)
    (if (symbol? (cadr exp))
        (cadr exp)
        (caadr exp)))

  (define (definition-value exp)
    (if (symbol? (cadr exp))
        (caddr exp)
        (make-lambda (cdadr exp)
                     (cddr exp))))

  (define (lambda? exp) (tagged-list? exp 'lambda))

  (define (lambda-parameters exp) (cadr exp))

  (define (lambda-body exp) (cddr exp))
  
  (define (make-lambda parameters body)
    (cons 'lambda (cons parameters body)))

  (define (if? exp) (tagged-list? exp 'if))

  (define (if-predicate exp) (cadr exp))

  (define (if-consequent exp) (caddr exp))

  (define (if-alternative exp)
    (if (not (null? (cdddr exp)))
        (cadddr exp)))

  (define (begin? exp) (tagged-list? exp 'begin))   
  (define (make-if predicate consequent alternative)
    (list 'if predicate consequent alternative))
  (define (begin? exp) (tagged-list? exp 'begin))
  (define (begin-actions exp) (cdr exp))
  (define (last-exp? seq) (null? (cdr seq)))
  (define (first-exp seq) (car seq))
  (define (rest-exps seq) (cdr seq))
  (define (sequence->exp seq)
    (cond ((null? seq) seq)
          ((last-exp? seq) (first-exp seq))
          (#t (make-begin seq))))
  (define (make-begin seq) (cons 'begin seq))
  (define (application? exp) (pair? exp))
  (define (operator exp) (car exp))
  (define (operands exp) (cdr exp))
  (define (no-operands? ops) (null? ops))
  (define (first-operand ops) (car ops))
  (define (rest-operands ops) (cdr ops))

  (define (cond? exp) (tagged-list? exp 'cond))
  (define (cond-clauses exp) (cdr exp))
  (define (cond-predicate clause) (car clause))
  (define (cond-actions clause) (cdr clause))
  (define (cond->if exp)
    (expand-clauses (cond-clauses exp)))
  (define (expand-clauses clauses)
    (if (not (null? clauses))
        ((lambda (first rest)
           (make-if (cond-predicate first)
                    (sequence->exp (cond-actions first))
                    (expand-clauses rest)))
         (car clauses)
         (cdr clauses))))

  (define (and? exp) (tagged-list? exp 'and))
  (define (and->if clauses)
    (if (null? clauses)
#t
        (make-if (car clauses) (and->if (cdr clauses)) #f)))

  (define (or? exp) (tagged-list? exp 'or))
  (define (or->if clauses)
    (if (null? clauses)
#f
        (make-if (car clauses) #t (or->if (cdr clauses)))))

  (define (load? exp) (tagged-list? exp 'load))
  (define (load->exp exp) (read (open-input-file (cadr exp))))
  
  (define (make-procedure parameters body env)
    (list 'procedure parameters body env))
  (define (compound-procedure? p)
    (tagged-list? p 'procedure))
  (define (procedure-parameters p) (cadr p))
  (define (procedure-body p) (caddr p))
  (define (procedure-environment p) (cadddr p))

  (define (enclosing-environment env) (cdr env))
  (define (first-frame env) (car env))
  (define the-empty-environment '())
  (define (make-frame variables values)
    (cons variables values))
  (define (frame-variables frame) (car frame))
  (define (frame-values frame) (cdr frame))
  (define (add-binding-to-frame! var val frame)
    (set-car! frame (cons var (car frame)))
    (set-cdr! frame (cons val (cdr frame))))
  (define (extend-environment vars vals base-env)
    (define (iter vars vals vars0 vals0)
      (cond ((symbol? vars) (cons (make-frame (cons vars vars0)
                                              (cons vals vals0))
                                  base-env))
            ((and (pair? vars) (pair? vals))
             (iter (cdr vars)
                   (cdr vals)
                   (cons (car vars) vars0)
                   (cons (car vals) vals0)))
            ((and (null? vars) (null? vals)) (cons (make-frame vars0 vals0)
                                                   base-env))
            ((null? vars)
             (error "too many arguments supplied" vars vals))
            (#t (error "too few arguments supplied" vars vals))))
    (iter vars vals '() '()))
  (define (lookup-variable-value var env)
    (define (env-loop env)
      (define (scan vars vals)
        (cond ((null? vars)
               (env-loop (enclosing-environment env)))
              ((eq? var (car vars))
               (car vals))
              (#t (scan (cdr vars) (cdr vals)))))
      (if (eq? env the-empty-environment)
          (error "unbound variable --" var)
          ((lambda (frame)
             (scan (frame-variables frame)
                   (frame-values frame)))
           (first-frame env))))
    (env-loop env))

  (define (set-variable-value! var val env)
    (define (env-loop env)
      (define (scan vars vals)
        (cond ((null? vars)
               (env-loop (enclosing-environment env)))
              ((eq? var (car vars))
               (set-car! vals val))
              (#t (scan (cdr vars) (cdr vals)))))
      (if (eq? env the-empty-environment)
          (error "unbound variable -- set!" var)
          ((lambda (frame)
             (scan (frame-variables frame)
                   (frame-values frame)))
           (first-frame env))))
    (env-loop env))

  (define (define-variable! var val env)
    ((lambda (frame)
       (define (scan vars vals)
         (cond ((null? vars)
                (add-binding-to-frame! var val frame))
               ((eq? var (car vars))
                (set-car! vals val))
               (#t (scan (cdr vars) (cdr vals)))))
       (scan (frame-variables frame)
             (frame-values frame)))
     (first-frame env)))

  (define (primitive-procedure? proc)
    (tagged-list? proc 'primitive))
  (define (primitive-implementation proc) (cdr proc))
  
  (define primitive-procedures
    (list (cons '* *)
          (cons '+ +)
          (cons '/ /)
          (cons '< <)
          (cons '= =)                    
          (cons 'apply apply)
          (cons 'binary-port? binary-port?)
          (cons 'boolean? boolean?)
          (cons 'car car)
          (cons 'cdr cdr)
          (cons 'ceiling ceiling)
          (cons 'char->integer char->integer)
          (cons 'char? char?)
          (cons 'close-port close-port)
          (cons 'cons cons)
          (cons 'current-error-port current-error-port)
          (cons 'current-input-port current-input-port)
          (cons 'eof-object eof-object)
          (cons 'eof-object? eof-object?)
          (cons 'eq? eq?)
          (cons 'eqv? eqv?)
          (cons 'error error-in-underlying-scheme)
          (cons 'error-object-irritants error-object-irritants)
          (cons 'error-object-message error-object-message)
          (cons 'error-object? error-object?)
          (cons 'exact exact)
          (cons 'exact? exact?)
          (cons 'file-error? file-error?)
          (cons 'floor floor)
          (cons 'flush-output-port flush-output-port)
          (cons 'input-port-open? input-port-open?)
          (cons 'input-port? input-port?)
          (cons 'integer->char integer->char)
          (cons 'list->string list->string)
          (cons 'list->vector list->vector)
          (cons 'number->string number->string)
          (cons 'number? number?)
          (cons 'numerator numerator)
          (cons 'output-port-open? output-port-open?)
          (cons 'output-port? output-port?)
          (cons 'pair? pair?)
          (cons 'peek-char peek-char)
          (cons 'procedure? procedure?)
          (cons 'raise raise)
          (cons 'read-char read-char)
          (cons 'read-error? read-error?)
          (cons 'round round)
          (cons 'set-car! set-car!)
          (cons 'set-cdr! set-cdr!)
          (cons 'string->list string->list)
          (cons 'string->symbol string->symbol)
          (cons 'string-set! string-set!)
          (cons 'string? string?)
          (cons 'symbol->string symbol->string)
          (cons 'symbol? symbol?)
          (cons 'textual-port? textual-port?)
          (cons 'truncate truncate)
          (cons 'vector vector)
          (cons 'vector->list vector->list)
          (cons 'vector-for-each vector-for-each)
          (cons 'vector-length vector-length)
          (cons 'vector-map vector-map)
          (cons 'vector-ref vector-ref)
          (cons 'vector-set! vector-set!)
          (cons 'vector? vector?)

          ;; char library
          (cons 'char-alphabetic? char-alphabetic?)
          (cons 'char-downcase char-downcase)
          (cons 'char-foldcase char-foldcase)
          (cons 'char-lower-case? char-lower-case?)
          (cons 'char-numeric? char-numeric?)
          (cons 'char-upcase char-upcase)
          (cons 'char-upper-case? char-upper-case?)
          (cons 'char-whitespace? char-whitespace?)
          (cons 'digit-value digit-value)

          ;; cxr library

          ;; eval library

          ;; file library
          (cons 'delete-file delete-file)
          (cons 'file-exists? file-exists?)
          (cons 'open-binary-input-file open-binary-input-file)
          (cons 'open-binary-output-file open-binary-output-file)
          (cons 'open-input-file open-input-file)
          (cons 'open-output-file open-output-file)

          ;; complex library
          (cons 'angle angle)
          (cons 'imag-part imag-part)
          (cons 'real-part real-part)

          ;; inexact library
          (cons 'exp exp)
          (cons 'infinite? infinite?)
          (cons 'log log)
          (cons 'nan? nan?)
          ))
  (define (primitive-procedure-names)
    (map car
         primitive-procedures))
  (define (primitive-procedure-objects)
    (map (lambda (proc) (cons 'primitive (cdr proc)))
         primitive-procedures))

  (define (setup-environment)
    ((lambda (initial-env)
       initial-env)
     (extend-environment (primitive-procedure-names)
                         (primitive-procedure-objects)
                         the-empty-environment)))
  (define the-global-environment (setup-environment))
  (define (apply-primitive-procedure proc args)
    ((lambda (obj)
       (if (error-object? obj)
           (begin
             (display "ERROR: ")
             (display (error-object-message obj))
             (define (iter objs)
               (if (null? objs)
                   (begin
                     (newline)
                     (driver-loop))
                   (begin
                     (display " ")
                     (write (car objs))
                     (iter (cdr objs)))))
             (iter (error-object-irritants obj)))
           obj))
     (apply-in-underlying-scheme
      (primitive-implementation proc) args)))


  (define (driver-loop)
    (display '|> |)
    ((lambda (input)        
       (if (eof-object? input)
           (exit)
           ((lambda (output)
              (user-print output))
            (eval input the-global-environment))))
     (read))
    (driver-loop))

  (define (repl)
    (eval '(begin
             (load "./lib/stdlib/base.scm")
             (load "./lib/stdlib/case-lambda.scm")
             (load "./lib/stdlib/char.scm")
             (load "./lib/stdlib/complex.scm")
             (load "./lib/stdlib/cxr.scm")
             (load "./lib/stdlib/file.scm")
             (load "./lib/stdlib/inexact.scm")
             (load "./lib/stdlib/lazy.scm")
             (load "./lib/stdlib/load.scm")
             (load "./lib/stdlib/process-context.scm")
             (load "./lib/stdlib/read.scm")
             (load "./lib/stdlib/repl.scm")
             (load "./lib/stdlib/time.scm")
             (load "./lib/stdlib/write.scm"))
          the-global-environment)
    (driver-loop))
  

  (define (user-print obj)
    (display '|=> |)
    (cond ((primitive-procedure? obj)
           (write (primitive-implementation obj)))
          ((compound-procedure? obj)
           (display '|#<compound-procedure: |)
           (display (procedure-parameters obj))
           (display " ")
           (display (procedure-body obj))
           (display '| (<procedure-env>)>|))
          (#t (write obj)))
    (newline))

  (repl)
  )
