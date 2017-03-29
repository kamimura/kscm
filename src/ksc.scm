((lambda ()
  (define (- z1 . zs)
    (if (null? zs)
        (* -1 z1)
        ((lambda ()
           (define (iter z zs)
             (if (null? zs)
                 z
                 (iter (+ z (* -1 (car zs))) (cdr zs))))
           (iter z1 zs)))))

  (define (append . lists)
    (define (iter1 list1 list2)
      (if (null? list1)
          list2
          (iter1 (cdr list1) (cons (car list1) list2))))
    (define (iter2 list-of-list list)
      (if (null? list-of-list)
          list
          (iter2 (cdr list-of-list)
                 (iter1 (reverse (car list-of-list))
                        list))))
    (define r (reverse lists))
    (if (null? r)
        '()
        (iter2 (cdr r) (car r))))

  (define (cadr pair) (car (cdr pair)))
  (define (cddr pair) (cdr (cdr pair)))  
  (define (caadr pair) (car (cadr pair)))
  (define (cdadr pair) (cdr (cadr pair)))
  (define (cdddr pair) (cdr (cddr pair)))
  (define (cadddr pair) (car (cdddr pair)))

  (define (error message . objs)
    (define (iter objs)
      (if (not (null? objs))
          ((lambda ()
             (display (car objs) (current-error-port))
             (display " " (current-error-port))
             (iter (cdr objs))))))
    (if (not (string=? message ""))
        (begin
          (display message (current-error-port))))
    (iter objs)
    (display "\n" (current-error-port))
    (exit 1))
  
  (define (length list)
    (define (iter list n)
      (if (null? list)
          n
          (iter (cdr list) (+ n 1))))
    (iter list 0))
  
  (define (list . args) args)
  (define (list-ref list k)
     (if (= k 0)
         (car list)
         (list-ref (cdr list) (- k 1))))

  (define (map proc list)
    (define (iter list result)
      (if (null? list)
          result
          (iter (cdr list) (cons (proc (car list)) result))))
    (iter (reverse list) '()))

  (define (memq obj list)
    (cond ((null? list) '())
          ((eq? obj (car list)) list)
          (#t (memq obj (cdr list)))))

  (define (not obj) (if obj #f #t))
  
  (define (reverse list)
    (define (iter list result)
      (if (null? list)
          result
          (iter (cdr list)
                (cons (car list) result))))
    (iter list '()))
  
  (define (string-append . strings)
    (define (iter1 strings result)
      (if (null? strings)
          (reverse result)
          (iter1 (cdr strings) (cons (string->list (car strings))
                                     result))))
    (define (iter2 list-of-list)
      (if (null? list-of-list)
          '()
          (append (car list-of-list)
                  (iter2 (cdr list-of-list)))))
    (list->string (iter2 (iter1 strings '()))))

  (define (const-string s)
    (define (iter chars)
      (if (null? chars)
          "strempty_ptr"
          (string-append "strnew(" (const (car chars)) ", "
                         (iter (cdr chars)) ")")))
    (iter (string->list s)))
  (define (const-symbol->string obj)
    (define s (symbol->string obj))
    (define (iter chars)
      (cond ((null? chars) '())
            ((eqv? #\" (car chars))
             (cons #\\ (cons (car chars) (iter (cdr chars)))))
            ((eqv? #\alarm (car chars))
             (cons #\\ (cons #\a (iter (cdr chars)))))
            ((eqv? #\backspace (car chars))
             (cons #\\ (cons #\b (iter (cdr chars)))))
            ((eqv? #\newline (car chars))
             (cons #\\ (cons #\n (iter (cdr chars)))))
            ((eqv? #\return (car chars))
             (cons #\\ (cons #\r (iter (cdr chars)))))
            ((eqv? #\tab (car chars))
             (cons #\\ (cons #\t (iter (cdr chars)))))
            ((eqv? #\\ (car chars))
             (cons #\\ (cons #\\ (iter (cdr chars)))))
            (#t (cons (car chars) (iter (cdr chars))))))
    (list->string (iter (string->list s))))
  (define undef (if #f #f))
  (define (const obj)
    (cond ((number? obj)
           (if (exact? obj)
               (string-append "qnew(\"" (number->string obj) "\")")
               (string-append "znew_s_s(\"" (number->string (real-part obj)) "\",\""
                              (number->string (imag-part obj)) "\")")))
          ((pair? obj)
           (string-append "pnew(" (const (car obj)) ", " (const (cdr obj)) ")"))
          ((null? obj) "empty_ptr")
          ((symbol? obj)
           (string-append "symvnew(\"" (const-symbol->string obj) "\")"))
          ((string? obj) (const-string obj))
          ((char? obj) (string-append
                        "cnewuc(" (number->string (char->integer obj)) ")"))
          ((eq? obj undef) "undef_ptr")
          ((boolean? obj) (if obj "true_ptr" "false_ptr"))
          (#t (error "const" obj))))
  
  (define (caddr p) (car (cdr (cdr p))))
  (define (print-code code port)
    (define (iter code)
      (if (not (null? code))
          ((lambda ()
             (display (car code) port)
             (iter (cdr code))))))
    (display '|#include "obj.h"\n#include "parse.tab.h"\n| port)
    (display '|int main(int argc, char **argv) {| port)
    (display '|init();| port)
    (display '|scm_argv = empty_ptr;| port)
    (display '|for (int i = argc - 1; i >= 0; i--){| port)
    (display '|glong items_written;| port)
    (display '|gunichar *s = g_utf8_to_ucs4(argv[i], -1, NULL, &items_written, NULL);|
             port)
    (display '|ObjPtr p = strempty_ptr;| port)
    (display '|for (glong i = items_written - 1; i >= 0; i--) {| port)
    (display '|p = strnew(cnewuc(s[i]), p);| port)
    (display '|}| port)
    (display '|scm_argv = pnew(p, scm_argv);| port)
    (display '|g_free(s);| port)
    (display '|}| port)
    (display '|ObjPtr val, proc, argl, cont = NULL;| port)
    (display '|ObjPtr env = setup_environment();| port)
    (iter (caddr code))
    (display '|if (err_p(val)){| port)
    (display '|ewrite(val);} else {| port)
    (display '|printf("=> ");| port)
    (display '|cdisplay(val, oport);}| port)
    (display '|printf("\x5c;n");}| port))
  
  (define (self-evaluating? exp)
    (cond ((number? exp) #t)
          ((string? exp) #t)
          ((eq? undef exp) #t)
          ((boolean? exp) #t)
          ((char? exp) #t)
          ((null? exp) #t)
          (#t #f)))
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
  (define (lambda-parameters exp)
    ((lambda (obj)
       (define (iter o)
         (cond ((or (symbol? o) (null? o)) obj)
               ((and (pair? o) (symbol? (car o))) (iter (cdr o)))
               (#t (error "syntax error: lambda-parameters --" exp))))
       (iter obj))
     (cadr exp)))
  (define (lambda-body exp) (cddr exp))
  (define (make-lambda parameters body) (cons 'lambda (cons parameters body)))

  (define (if? exp) (tagged-list? exp 'if))
  (define (if-predicate exp) (cadr exp))
  (define (if-consequent exp) (caddr exp))
  (define (if-alternative exp)
    (if (not (null? (cdddr exp)))
        (cadddr exp)))
  (define (make-if predicate consequent alternative)
    (list 'if predicate consequent alternative))

  (define (begin? exp) (tagged-list? exp 'begin))
  (define (begin-actions exp) (cdr exp))
  
  (define (sequence->exp seq)
    (cond ((null? seq) seq)
          ((last-exp? seq) (first-exp seq))
          (#t (make-begin seq))))
  (define (make-begin seq) (cons 'begin seq))   

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
  
  (define (last-exp? seq) (null? (cdr seq)))
  (define (first-exp seq) (car seq))
  (define (rest-exps seq) (cdr seq))
  (define (application? exp) (pair? exp))
  (define (operator exp) (car exp))
  (define (operands exp) (cdr exp))
  (define (no-operands? ops) (null? ops))
  (define (first-operand ops) (car ops))
  (define (rest-operands ops) (cdr ops))
  
  (define (compile exp target linkage)
    (cond ((self-evaluating? exp)
           (compile-self-evaluating exp target linkage))
          ((quoted? exp) (compile-quoted exp target linkage))
          ((variable? exp)
           (compile-variable exp target linkage))
          ((assignment? exp)
           (compile-assignment exp target linkage))
          ((definition? exp)
           (compile-definition exp target linkage))
          ((if? exp) (compile-if exp target linkage))
          ((lambda? exp) (compile-lambda exp target linkage))
          ((begin? exp)
           (compile-sequence (begin-actions exp)
                             target
                             linkage))
          ((cond? exp) (compile (cond->if exp) target linkage))
          ((and? exp) (compile (and->if (cdr exp)) target linkage))
          ((or? exp) (compile (or->if (cdr exp)) target linkage))
          ((load? exp) (compile (load->exp exp) target linkage))
          ((application? exp)
           (compile-application exp target linkage))
          (#t
           (error "Unknown expression type -- COMPILE" exp))))
  
  (define (make-instruction-sequence needs modifies statements)
    (list needs modifies statements))

  (define (empty-instruction-sequence)
    (make-instruction-sequence '() '() '()))
  
  (define (compile-linkage linkage)
    (cond ((eq? linkage 'return)
           (make-instruction-sequence '(cont) '()
                                      '(|goto *(cont->ptr);|)))
          ((eq? linkage 'next)
           (empty-instruction-sequence))
          (#t
           (make-instruction-sequence '() '()
                                      (list '|goto | linkage '|;|)))))

  (define (end-with-linkage linkage instruction-sequence)
    (preserving '(cont)
                instruction-sequence
                (compile-linkage linkage)))

  (define (compile-self-evaluating exp target linkage)
    (end-with-linkage
     linkage
     (make-instruction-sequence '() (list target)
                                (list target '| = | (const exp) '|;|))))
  
  (define (compile-quoted exp target linkage)
    (end-with-linkage
     linkage
     (make-instruction-sequence
      '() (list target)
      (list target '| = | (const (text-of-quotation exp)) '|;|))))

  (define (compile-variable exp target linkage)
    (end-with-linkage
     linkage
     (make-instruction-sequence
      '(env) (list target)
      (list target '| = lookup_variable_value(| (const exp) '|, env);|))))


  (define (compile-assignment exp target linkage)
    (define var (assignment-variable exp))
    (define get-value-code (compile (assignment-value exp) 'val 'next))
    (end-with-linkage
     linkage
     (preserving
      '(env)
      get-value-code
      (make-instruction-sequence
       '(env val) (list target)
       (list target '| = set_variable_value(| (const var) '|, val, env);|)))))

  (define (compile-definition exp target linkage)
    (define var (definition-variable exp))
    (define get-value-code (compile (definition-value exp) 'val 'next))
    (end-with-linkage
     linkage
     (preserving '(env)
                 get-value-code
                 (make-instruction-sequence
                  '(env val) (list target)
                  (list target '| = define_variable(| (const var) '|, val, env);|)))))

  (define label-counter 0)
  (define (new-label-number)
    (set! label-counter (+ 1 label-counter))
    label-counter)
  (define (make-label name)
    (string->symbol
     (string-append (symbol->string name)
                    (number->string (new-label-number)))))
  (define (label-inst label)
    (make-instruction-sequence '() '() (list label '|:|)))

  (define (compile-if exp target linkage)
    (define f-branch (make-label 'false_branch))
    (define after-if (make-label 'after_if))
    (define consequent-linkage (if (eq? linkage 'next) after-if linkage))
    (define p-code (compile (if-predicate exp) 'val 'next))
    (define c-code (compile (if-consequent exp) target consequent-linkage))
    (define a-code (compile (if-alternative exp) target linkage))
    (preserving '(env cont)
                p-code
                (append-instruction-sequences
                 (make-instruction-sequence
                  '(val) '()
                  (list '|if (val == false_ptr) {goto | f-branch '|;}|))
                 (parallel-instruction-sequences
                  c-code
                  (append-instruction-sequences (label-inst f-branch) a-code))
                 (if (eq? linkage 'next)
                     (label-inst after-if)
                     (empty-instruction-sequence)))))
  
  (define (compile-sequence seq target linkage)
    (if (last-exp? seq)
        (compile (first-exp seq) target linkage)
        (preserving '(env cont)
                    (compile (first-exp seq) target 'next)
                    (compile-sequence (rest-exps seq) target linkage))))

  (define (compile-lambda exp target linkage)
    ((lambda (proc-entry after-lambda)
       ((lambda (lambda-linkage)
          (append-instruction-sequences
           (tack-on-instruction-sequence
            (end-with-linkage
             lambda-linkage
             (make-instruction-sequence
              '(env) (list target)
              (list target '| = cprocnew(&&| proc-entry '|, env);|)))
            (compile-lambda-body exp proc-entry))
           (label-inst after-lambda)))
        (if (eq? linkage 'next) after-lambda linkage)))
     (make-label 'entry)
     (make-label 'after_lambda)))

  (define (compile-lambda-body exp proc-entry)
    ((lambda (formals)
       (append-instruction-sequences
        (make-instruction-sequence
         '(env proc argl) '(env)
         (list proc-entry '|:|
               '|env = compiled_procedure_env(proc);|
               '|env = extend_environment(| (const formals) '|, argl, env);|))
        (compile-sequence (lambda-body exp) 'val 'return)))
     (lambda-parameters exp)))

  (define (compile-application exp target linkage)
    (define proc-code (compile (operator exp) 'proc 'next))
    (define operand-codes (map (lambda (operand) (compile operand 'val 'next))
                               (operands exp)))
    (preserving '(env cont)
                proc-code
                (preserving
                 '(proc cont)
                 (construct-arglist operand-codes)
                 (compile-procedure-call target linkage))))

  (define (construct-arglist operand-codes)
    ((lambda (operand-codes)
       (if (null? operand-codes)
           (make-instruction-sequence '() '(argl)
                                      '(|argl = empty_ptr;|))
           ((lambda (code-to-get-last-arg)
              (if (null? (cdr operand-codes))
                  code-to-get-last-arg
                  (preserving '(env)
                              code-to-get-last-arg
                              (code-to-get-rest-args
                               (cdr operand-codes)))))
            (append-instruction-sequences
             (car operand-codes)
             (make-instruction-sequence '(val) '(argl)
                                        '(|argl = pnew(val, empty_ptr);|))))))
     
     (reverse operand-codes)))

  (define (code-to-get-rest-args operand-codes)
    ((lambda (code-for-next-arg)
       (if (null? (cdr operand-codes))
           code-for-next-arg
           (preserving '(env)
                       code-for-next-arg
                       (code-to-get-rest-args (cdr operand-codes)))))
     (preserving '(argl)
                 (car operand-codes)
                 (make-instruction-sequence
                  '(val argl) '(argl)
                  '(|argl = pnew(val, argl);|)))))
  

  (define (compile-procedure-call target linkage)
    ((lambda (before-call primitive-branch after-call)
       ((lambda (compiled-linkage)
          (append-instruction-sequences
           (make-instruction-sequence
            '(proc) '()
            (list before-call '|:|
                  '|if (proc->t == PROC_APPLY) {|
                  '|proc = argl->p->l; argl = argl->p->r->p->l;|
                  '|goto | before-call '|;}|
                  '|if (proc->t == PROC) { goto | primitive-branch '|;}|
                  '|if (proc->t != CPROC) {|
                  '|fprintf(stderr, "unknown procedure type -- ");|
                  '|cdisplay(proc, eport);|
                  '|fprintf(stderr, "\x5c;n");|
                  '|exit(1);}|))
           (parallel-instruction-sequences
            (compile-proc-appl target compiled-linkage)
            (append-instruction-sequences
             (label-inst primitive-branch)
             (end-with-linkage
              linkage
              (make-instruction-sequence
               '(proc argl)
               (list target)
               (list target '| = proc->proc->fn(argl);|)))))
           (if (eq? linkage 'next)
               (label-inst after-call)
               (empty-instruction-sequence))))
        (if (eq? linkage 'next) after-call linkage)))
     (make-label 'before_call)
     (make-label 'primitive_branch)
     (make-label 'after_call)))

  (define all-regs '(env proc val argl cont))

  (define (compile-proc-appl target linkage)
    (cond ((and (eq? target 'val) (not (eq? linkage 'return)))
           (make-instruction-sequence
            '(proc) all-regs
            (list '|cont = contnew(&&| linkage '|);|
                  '|val = compiled_procedure_entry(proc);|
                  '|goto *(val->ptr);|)))
          ((and (not (eq? target 'val))
                (not (eq? linkage 'return)))
           ((lambda (proc-return)
              (make-instruction-sequence
               '(proc) all-regs
               (list '|cont = contnew(&&| proc-return '|);|
                     '|val = compiled_procedure_entry(proc);|
                     '|goto *(val->ptr);|
                     proc-return '|:|
                     target '| = val;|
                     '|goto | linkage '|;|)))
            (make-label 'proc_return)))
          ((and (eq? target 'val) (eq? linkage 'return))
           (make-instruction-sequence
            '(proc cont) all-regs
            '(|val = compiled_procedure_entry(proc);|
              |goto *(val->ptr);|)))
          ((and (not (eq? target 'val)) (eq? linkage 'return))
           (error "return linkage, target not val -- COMPILE"
                  target))))

  (define (registers-needed s)
    (if (symbol? s) '() (car s)))

  (define (registers-modified s)
    (if (symbol? s) '() (cadr s)))

  (define (statements s)
    (if (symbol? s) (list s) (caddr s)))

  (define (needs-register? seq reg)
    (memq reg (registers-needed seq)))

  (define (modifies-register? seq reg)
    (memq reg (registers-modified seq)))

  (define (append-instruction-sequences . seqs)
    (define (append-2-sequences seq1 seq2)
      (make-instruction-sequence
       (list-union (registers-needed seq1)
                   (list-difference (registers-needed seq2)
                                    (registers-modified seq1)))
       (list-union (registers-modified seq1)
                   (registers-modified seq2))
       (append (statements seq1) (statements seq2))))
    (define (append-seq-list seqs)
      (if (null? seqs)
          (empty-instruction-sequence)
          (append-2-sequences (car seqs)
                              (append-seq-list (cdr seqs)))))
    (append-seq-list seqs))

  (define (list-union s1 s2)
    (cond ((null? s1) s2)
          ((memq (car s1) s2) (list-union (cdr s1) s2))
          (#t (cons (car s1) (list-union (cdr s1) s2)))))

  (define (list-difference s1 s2)
    (cond ((null? s1) '())
          ((memq (car s1) s2) (list-difference (cdr s1) s2))
          (#t (cons (car s1)
                    (list-difference (cdr s1) s2)))))

  (define (preserving regs seq1 seq2)
    (if (null? regs)
        (append-instruction-sequences seq1 seq2)
        ((lambda (first-reg)
           (if (and (needs-register? seq2 first-reg)
                    (modifies-register? seq1 first-reg))
               (preserving (cdr regs)
                           (make-instruction-sequence
                            (list-union (list first-reg)
                                        (registers-needed seq1))
                            (list-difference (registers-modified seq1)
                                             (list first-reg))
                            (append (list '|save(| first-reg '|);|)
                                    (statements seq1)
                                    (list first-reg '| = restore();|)))
                           seq2)
               (preserving (cdr regs) seq1 seq2)))
         (car regs))))

  (define (tack-on-instruction-sequence seq body-seq)
    (make-instruction-sequence
     (registers-needed seq)
     (registers-modified seq)
     (append (statements seq) (statements body-seq))))

  (define (parallel-instruction-sequences seq1 seq2)
    (make-instruction-sequence
     (list-union (registers-needed seq1)
                 (registers-needed seq2))
     (list-union (registers-modified seq1)
                 (registers-modified seq2))
     (append (statements seq1) (statements seq2))))


  (define commands (command-line))
  (if (= (length commands) 2)
      ((lambda ()
         (define name (list-ref commands 1))
         (define output-filename (string-append name ".c"))
         (define input-file  (open-input-file (string-append name ".scm")))
         (define output-file (open-output-file output-filename))
         (define exp (read input-file))
         (define code (compile exp 'val 'next))
         (print-code code output-file)
         (flush-output-port output-file)
         (define n (system (string-append "cc -O3 `pkg-config --cflags glib-2.0` -I/opt/local/include `pkg-config --libs glib-2.0` -L/opt/local/lib -L./ -lgmp -lmpfr -lmpc -lfl -lgc -lkscm " output-filename " -o " name)))
         (if (= n 0)
             'compiled
             (error "error:" n))
         ))
      (error "usage: ksc name"))
  ))
