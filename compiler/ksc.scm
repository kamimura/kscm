(begin
  (define (list->string list)
    (define s (make-string (length list) #\A))
    (define (iter list k s)
      (if (null? list)
          s
          (begin
            (string-set! s k (car list))
            (iter (cdr list) (+ k 1) s))))
    (iter list 0 s))
  (define (memq obj list)
    (if (null? list)
        #f
        (if (eq? obj (car list) )
            list
            (memq obj (cdr list)))))
  (define (reverse list)
    (define (iter list result)
      (if (null? list)
          result
          (iter (cdr list) (cons (car list) result))))
    (iter list '()))
  (define (append . list-of-list)
    (if (null? list-of-list)
        '()
        ((lambda (reversed)
           ((lambda (o)
              (if (or (null? o) (pair? o))
                  ((lambda ()
                     (define (iter-1 list result)
                       (if (null? list)
                           result
                           (iter-1 (cdr list)
                                   (cons (car list) result))))
                     (define (iter-2 list-of-list result)
                       (if (null? list-of-list)
                           result
                           (iter-2 (cdr list-of-list)
                                   (iter-1 (reverse (car list-of-list))
                                           result))))
                     (iter-2 (cdr reversed) o)))
                  o))
            (car reversed)))
         (reverse list-of-list))))
  (define (string->list string . rest)
    (define start (if (null? rest) 0 (car rest)))
    (define end (if (or (null? rest) (null? (cdr rest)))
                    (string-length string)
                    (car (cdr rest))))
    (define (iter i result)       
      (if (< i start)
          result
          (iter (- i 1)
                (cons (string-ref string i) result))))
    (iter (- end 1) '()))
  (define (string-append . list-of-string)     
    (define (iter list-of-string result)
      (if (null? list-of-string)
          result
          (iter (cdr list-of-string)
                (append result (string->list (car list-of-string))))))
    (list->string (iter list-of-string '())))
  (define (newline . args)
    ((lambda (port)
       (display #\newline port))
     (if (null? args) (current-output-port) (car args))))
  
  (define (print-elements list port)
    (if (not (null? list))
        (begin
          (display (car list) port)
          (print-elements (cdr list) port))))
  (define (print-code code port)
    (display '|/** \x5c;file */| port)    
    (newline port)
    (display '|#include "init.h"| port)
    (newline port)
    (display '|int main (int argc,char *argv[]){init();| port)
    (print-elements (car (cdr (cdr code))) port)
    (display '|printf("=> ");
               object_write_stdout(val);
               puts("");}| port))
  (define undef (if #f 0))
  (define (string->c s)
    (define list-of-char (string->list s))
    (if (or (memq #\" list-of-char) (memq #\null list-of-char)
            (memq #\\ list-of-char)
            (memq #\alarm list-of-char) (memq #\backspace list-of-char)
            (memq #\tab list-of-char) (memq #\newline list-of-char)
            (memq #\return list-of-char))
        ((lambda ()
           (define (iter list-of-char)
             (if (null? list-of-char)
                 '(|\x5c;"|)
                 ((lambda (c)
                    ((lambda (sym)
                       (cons sym (iter (cdr list-of-char))))
                     (if (eq? c #\")
                         '|\x5c;\x5c;x22;|
                         (if (eq? c #\null)
                             '|\x5c;\x5c;x0;|
                             (if (eq? c #\x5c)
                                 '|\x5c;\x5c;x5c;|
                                 (if (eq? c #\alarm)
                                     '|\x5c;\x5c;a|
                                     (if (eq? c #\backspace)
                                         '|\x5c;\x5c;b|
                                         (if (eq? c #\tab)
                                             '|\x5c;\x5c;t|
                                             (if (eq? c #\newline)
                                                 '|\x5c;\x5c;n|
                                                 (if (eq? c #\return)
                                                     '|\x5c;\x5c;r|
                                                     c))))))))))
                  (car list-of-char))))
           (cons '|\x5c;"|
                 (iter list-of-char))))
        (list '|\x5c;"|
              s
              '|\x5c;"|)))
  (define (symbol->c s)
    (define list-of-char (string->list (symbol->string s)))
    (if (or (memq #\" list-of-char) (memq #\null list-of-char)
            (memq #\x5c list-of-char)
            (memq #\x7c list-of-char)
            (memq #\alarm list-of-char) (memq #\backspace list-of-char)
            (memq #\tab list-of-char) (memq #\newline list-of-char)
            (memq #\return list-of-char))
        ((lambda ()
           (define (iter list-of-char)
             (if (null? list-of-char)
                 (list #\x7c)
                 ((lambda (c)
                    ((lambda (sym)
                       (cons sym (iter (cdr list-of-char))))
                     (if (eq? c #\")
                         '|\x5c;\x5c;x22;|
                         (if (eq? c #\null)
                             '|\x5c;\x5c;x0;|
                             (if (eq? c #\x5c)
                                 '|\x5c;\x5c;x5c;|
                                 (if (eq? c #\|)
                                     '|\x5c;\x5c;x7c;|
                                     (if (eq? c #\alarm)
                                         '|\x5c;\x5c;a|
                                         (if (eq? c #\backspace)
                                             '|\x5c;\x5c;b|
                                             (if (eq? c #\tab)
                                                 '|\x5c;\x5c;t|
                                                 (if (eq? c #\newline)
                                                     '|\x5c;\x5c;n|
                                                     (if (eq? c #\return)
                                                         '|\x5c;\x5c;r|
                                                         c)))))))))))
                  (car list-of-char))))
           (cons #\x7c
                 (iter list-of-char))))
        (list #\x7c s #\x7c)))
  (define (char->c c)
    (list '|#\x5c;\x5c;|
          (if (eq? c #\")
              '|x22|
              (if (eq? c #\\)
                  '|x5c|
                  (if (eq? c #\alarm)
                      '|alarm|
                      (if (eq? c #\backspace)
                          '|backspace|
                          (if (eq? c #\escape)
                              '|escape|
                              (if (eq? c #\newline)
                                  '|newline|
                                  (if (eq? c #\null)
                                      '|null|
                                      (if (eq? c #\return)
                                          '|return|
                                          (if (eq? c #\space)
                                              '|space|
                                              (if (eq? c #\tab)
                                                  '|tab|
                                                  c))))))))))))
  (define (pair->c p)
    (append (list '|(|)
            (obj->c (car p))
            (list '| . |)
            (obj->c (cdr p))
            (list '|)|)))
  (define (obj->c obj)
    (if (number? obj)
        (list (number->string obj))
        (if (string? obj)
            (string->c obj)
            (if (symbol? obj)
                (symbol->c obj)
                (if (pair? obj)
                    (pair->c obj)
                    (if (null? obj)
                        (list '|()|)
                        (if (boolean? obj)
                            (list obj)
                            (if (char? obj)
                                (char->c obj)))))))))
  
  (define (const obj)
    (if (eq? obj undef)
        '(undef)
        (if (eq? obj undef)
            '(undef)
            (if (eof-object? obj)
                '(eof_obj)
                (append (list '|c_str_to_datum("|)
                        (obj->c obj)
                        (list '|")|))))))

  (define (self-evaluating? exp)
    (or (boolean? exp)
        (number? exp)         
        (char? exp)
        (string? exp)      
        (procedure? exp)
        (vector? exp)
        (eof-object? exp)
        (eq? exp undef)))

  (define (if-alternative exp)
    (if (not (null? (cdr (cdr (cdr exp)))))
        (car (cdr (cdr (cdr exp))))
        undef))
  

  (define (definition-variable exp)
    (if (pair? (car (cdr exp)))
        (car (car (cdr exp)))
        (car (cdr exp))))
  (define (definition-value exp)
    (if (symbol? (car (cdr exp)))
        (car (cdr (cdr exp)))
        (make-lambda (cdr (car (cdr exp)))
                     (cdr (cdr exp)))))   
  (define (and->if exp)
    (if (null? exp)
        '#t
        (if (null? (cdr exp))
            (car exp)
            (list 'if
                  (car exp)
                  (cons 'and (cdr exp))
                  '#f))))

  (define (or->if exp)
    (if (null? exp)
        '#f
        (list 'if (car exp) (car exp) (cons 'or (cdr exp)))))

  (define log-port (open-output-file "compiler.log"))
  (define (compile exp target linkage)
    (display exp log-port)
    (newline log-port)
    (if (self-evaluating? exp)
        (compile-self-evaluating exp target linkage)
        (if (symbol? exp)
            (compile-variable exp target linkage)
            (if (pair? exp)
                ((lambda (o)
                   (if (symbol? o)
                       (if (eq? o 'quote)
                           (compile-quoted exp target linkage)
                           (if (eq? o 'lambda)
                               (compile-lambda exp target linkage)
                               (if (eq? o 'set!)
                                   (compile-assignment exp
                                                       target linkage)
                                   (if (eq? o 'define)
                                       (compile-definition exp
                                                           target linkage)
                                       (if (eq? o 'if)
                                           (compile-if exp
                                                       target linkage)
                                           (if (eq? o 'begin)
                                               (compile-sequence
                                                (cdr exp)
                                                target
                                                linkage)
                                               (if (eq? o 'and)
                                                   (compile
                                                    (and->if (cdr exp))
                                                    target
                                                    linkage)
                                                   (if (eq? o 'or)
                                                       (compile
                                                        (or->if (cdr exp))
                                                        target
                                                        linkage)
                                                       (compile-application
                                                        exp target linkage
                                                        )))))))))
                       (compile-application exp target linkage)))
                 (car exp))
                (error '|unknown expression type -- compile| exp)))))

  (define (make-instruction-sequence needs modifies statements)
    (list needs modifies statements))

  (define (empty-instruction-sequence)
    (make-instruction-sequence '() '() '()))

  (define (compile-linkage linkage)
    (if (eq? linkage 'return)
        (make-instruction-sequence '(cont) '()
                                   '(|goto *cont.cont;|))
        (if (eq? linkage 'next)
            (empty-instruction-sequence)
            (make-instruction-sequence
             '() '()
             (list '|goto | linkage '|;|)))))

  (define (end-with-linkage linkage instruction-sequence)
    (preserving '(cont)
                instruction-sequence
                (compile-linkage linkage)))

  (define (compile-self-evaluating exp target linkage)
    (end-with-linkage
     linkage
     (make-instruction-sequence
      '() (list target)
      (append (list '|object_free(&| target '|);|
                    target '| = |)
              (const exp)
              (list '|;|)))))
  (define (compile-variable exp target linkage)
    (end-with-linkage
     linkage
     (make-instruction-sequence
      '(env) (list target)
      (append (list '|object_free(&| target '|);|
                    target '| = lookup_var_val(|)
              (const exp)
              (list '|);|)))))
  (define (compile-quoted exp target linkage)
    (end-with-linkage
     linkage
     (make-instruction-sequence
      '() (list target)
      (append (list '|object_free(&| target '|);|
                    target '| = |)
              (const (car (cdr exp)))
              (list '|;|)))))

  (define (compile-assignment exp target linkage)
    ((lambda (var get-value-code)
       (end-with-linkage
        linkage
        (preserving '(env)
                    get-value-code
                    (make-instruction-sequence
                     '(env val) (list target)
                     (append (list '|set_var_val(|)
                             (const var)
                             (list '|);|
                                   target '| = undef;|))))))
     (car (cdr exp))
     (compile (car (cdr (cdr exp))) 'val 'next)))

  (define (make-lambda parameters body)
    (cons 'lambda (cons parameters body)))
  (define (compile-definition exp target linkage)
    ((lambda (var get-value-code)
       (end-with-linkage
        linkage
        (preserving '(env)
                    get-value-code
                    (make-instruction-sequence
                     '(env val) (list target)
                     (append (list '|def_var_val(|)
                             (const var)
                             (list '|);|
                                   target '| = undef;|))))))
     (definition-variable exp)
     (compile (definition-value exp) 'val 'next)))

  (define (compile-if exp target linkage)
    ((lambda (f-branch after-if)
       ((lambda (consequent-linkage)
          ((lambda (p-code c-code a-code)
             (preserving
              '(env cont)
              p-code
              (append-instruction-sequences
               (make-instruction-sequence
                '(val) '()
                (list '|if(val.type==BOOLEAN && !val.boolean){
                        goto | f-branch '|;}|))
               (parallel-instruction-sequences
                c-code
                (append-instruction-sequences
                 (make-instruction-sequence
                  '() '()
                  (list f-branch '|:;|))
                 a-code))
               (if (eq? linkage 'next)
                   (make-instruction-sequence
                    '() '()
                    (list after-if '|:;|))
                   (empty-instruction-sequence))
               )))
           (compile (car (cdr exp)) 'val 'next)
           (compile (car (cdr (cdr exp))) target consequent-linkage)
           (compile (if-alternative exp) target linkage)))
        (if (eq? linkage 'next) after-if linkage)))
     (make-label 'false_branch)
     (make-label 'after_if)))
  (define label-counter 0)
  (define (new-label-number)
    (set! label-counter (+ label-counter 1))
    label-counter)
  (define (make-label name)
    (string->symbol
     (string-append (symbol->string name)
                    (number->string (new-label-number)))))
  (define (compile-sequence seq target linkage)
    (if (null? (cdr  seq))
        (compile (car seq) target linkage)
        (preserving '(env cont)
                    (compile (car seq) target 'next)
                    (compile-sequence (cdr seq) target linkage))))

  (define (compile-lambda exp target linkage)
    ((lambda (proc-entry after-lambda)
       ((lambda (lambda-linkage)
          (append-instruction-sequences
           (tack-on-instruction-sequence
            (end-with-linkage
             lambda-linkage
             (make-instruction-sequence
              '(env) (list target)
              (list '|object_free(&| target '|);|
                    target '| = make_compiled_procedure(&&| proc-entry '|);|)
              ))
            (compile-lambda-body exp proc-entry))
           (make-instruction-sequence
            '() '() (list after-lambda '|:;|))))           
        (if (eq? linkage 'next) after-lambda linkage)))
     (make-label 'entry)
     (make-label 'after_lambda)))

  (define (compile-lambda-body exp proc-entry)
    ((lambda (formals)
       (append-instruction-sequences
        (make-instruction-sequence
         '(env proc argl) '(env)
         (append (list proc-entry
                       '|:env = compiled_procedure_env();
                          env = extend_environment(|)
                 (const formals)
                 '(|);|)))
        (compile-sequence (cdr (cdr exp)) 'val 'return)))
     (car (cdr exp))))

  (define (compile-application exp target linkage)
    (define (iter proc lst)
      (if (null? lst)
          '()
          (cons (proc (car lst))
                (iter proc (cdr lst)))))
    ((lambda (proc-code operand-codes)
       (preserving
        '(env cont)
        proc-code
        (preserving
         '(proc cont)
         (construct-arglist operand-codes)
         (compile-procedure-call target linkage))))
     (compile (car exp) 'proc 'next)
     (iter (lambda (operand) (compile operand 'val 'next)) (cdr exp))))
  (define (construct-arglist operand-codes)
    ((lambda (operand-codes)
       (if (null? operand-codes)
           (make-instruction-sequence
            '() '(argl)
            '(|argl = empty;|))
           ((lambda (code-to-get-last-arg)
              (if (null? (cdr operand-codes))
                  code-to-get-last-arg
                  (preserving '(env)
                              code-to-get-last-arg
                              (code-to-get-rest-args
                               (cdr operand-codes)))))
            (append-instruction-sequences
             (car operand-codes)
             (make-instruction-sequence
              '(val) '(argl)
              '(|argl = cons(val,empty);
                 val.type = NONE;|))))))
     (reverse operand-codes)))

  (define (code-to-get-rest-args operand-codes)
    ((lambda (code-for-next-arg)
       (if (null? (cdr operand-codes))
           code-for-next-arg
           (preserving '(env)
                       code-for-next-arg
                       (code-to-get-rest-args
                        (cdr operand-codes)))))
     (preserving
      '(argl)
      (car operand-codes)
      (make-instruction-sequence
       '(val argl) '(argl)
       (list '|argl = cons(val, argl);
               val.type = NONE;|)))))

  (define (compile-procedure-call target linkage)
    ((lambda (primitive-branch after-call)
       ((lambda (compiled-linkage)
          (append-instruction-sequences
           (make-instruction-sequence
            '(proc) '()
            (list '|if (proc.type == PROC) { goto |
                  primitive-branch '|;}|))
           (parallel-instruction-sequences
            (compile-proc-appl target compiled-linkage)
            (append-instruction-sequences
             (make-instruction-sequence
              '() '()
              (list primitive-branch '|:;|))
             (end-with-linkage
              linkage
              (make-instruction-sequence
               '(proc argl)
               (list target)
               (list '|object_free(&| target '|);|
                     target '| = proc.proc(argl); |)
               ))))
           (if (eq? linkage 'next)
               (make-instruction-sequence
                '() '() (list after-call '|:;|))
               (empty-instruction-sequence))
           ))
        (if (eq? linkage 'next) after-call linkage)))
     (make-label 'primitive_branch)
     (make-label 'after_call)))

  (define (compile-proc-appl target linkage)
    (if (and (eq? target 'val) (not (eq? linkage 'return)))
        (make-instruction-sequence
         '(proc) all-regs
         (list '|cont.cont = &&| linkage '|;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;|))
        (if (and (not (eq? target 'val))
                 (not (eq? linkage 'return)))
            ((lambda (proc-return)
               (make-instruction-sequence
                '(proc) all-regs
                (list '|cont.cont = &&| proc-return '|;
                        object_free(&val);
                        val = compiled_procedure_entry(proc);
                        goto *val.cont;|
                      proc-return '|:
                        object_free(&| target '|);|
                        target '| = val; val.type = NONE;
                        goto | linkage '|;|)))
             (make-label 'proc_return))
            (if (and (eq? target 'val) (eq? linkage 'return))
                (make-instruction-sequence
                 '(proc cont) all-regs
                 '(|object_free(&val);
                    val = compiled_procedure_entry(proc);
                    goto *val.cont;|)
                 )
                (if (and (not (eq? target 'val))
                         (eq? linkage 'return))
                    (error
                     '|return linkage, target not val -- compile|
                     target))))))

  (define all-regs '(env proc val argl cont))

  (define (registers-needed s)
    (if (symbol? s) '() (car s)))
  (define (registers-modified s)
    (if (symbol? s) '() (car (cdr s))))
  (define (statements s)
    (if (symbol? s) (list s) (car (cdr (cdr s)))))
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
    (if (null? s1)
        s2
        (if (memq (car s1) s2)
            (list-union (cdr s1) s2)
            (cons (car s1) (list-union (cdr s1) s2)))))
  (define (list-difference s1 s2)
    (if (null? s1)
        '()
        (if (memq (car s1) s2)
            (list-difference (cdr s1) s2)
            (cons (car s1)
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
                            (list-difference
                             (registers-modified seq1)
                             (list first-reg))
                            (append
                             (list '|save(| first-reg '|);|)
                             (statements seq1)
                             (list '|object_free(&| first-reg '|);|
                                   first-reg '| =restore();|)))
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


  (define input-file (open-input-file "input.scm"))
  (define output-file (open-output-file "output.c"))
  (define data (read input-file))
  (define code (compile data 'val 'next))
  (print-code code output-file)
  'compiled
  )
