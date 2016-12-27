(begin
  (define (newline port)
    (display #\newline port))
  (define (print-elements list port)
    (if (not (null? list))
        (begin
          (display (car list) port)
          (print-elements (cdr list) port))))
  (define (print-code code port)
    (display '|/** \x5c;file */| port)    
    (newline port)
    (display '|#include "kscm.h"| port)
    (newline port)
    (display '|int main (int argc,char *argv[]){init();get_command_line(argc, argv);| port)
    (print-elements (c-caddr code) port)
    (display '|printf("=> ");object_write_stdout(val);puts("");}| port))
  (define undef (if #f 0))
  (define (pair->c obj)
    (c-append '(|(|)
              (obj->c (car obj))
              '(| . |)
              (obj->c (cdr obj))
              '(|)|)))
  (define (obj->c obj)
    (if (number? obj)
        (list obj)
        (if (string? obj)
            (c-string->c obj)
            (if (symbol? obj)
                (c-symbol->c obj)
                (if (pair? obj)
                    (pair->c obj)
                    (if (null? obj)
                        '(|()|)
                        (if (boolean? obj)
                            (list obj)
                            (if (char? obj)
                                (c-char->c obj)))))))))
  (define (const obj)
    (if (eq? obj undef)
        '(undef)
        (if (eof-object? obj)
            '(eof_obj)
            (c-append '(|c_str_to_datum("|)
                      (obj->c obj)
                      '(|")|)))))
  (define (definition-value exp)
    (if (symbol? (c-cadr exp))
        (c-caddr exp)
        (c-make-lambda (c-cdadr exp)
                       (c-cddr exp))))
  (define (and->if exp)
    (if (null? exp)
        #t
        (begin          
          (define (iter o)
            (if (null? (cdr o))
                (car o)
                (list 'if
                      (car o)
                      (iter (cdr o))
                      '#f)))
          (iter exp))))
  (define (or->if exp)
    (if (null? exp)
        '#f
        (list 'if (car exp) (car exp) (cons 'or (cdr exp)))))
  (define log-port (open-output-file "compiler.log"))
  (define (compile exp target linkage)
    (display exp log-port)
    (newline log-port)
    (if (c-self-evaluating? exp)
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
  (define (compile-linkage linkage)
    (if (eq? linkage 'return)
        (c-make-instruction-sequence '(cont) '()
                                     '(|goto *cont.cont;|))
        (if (eq? linkage 'next)
            (c-empty-instruction-sequence)
            (c-make-instruction-sequence
             '() '()
             (list '|goto | linkage '|;|)))))
  (define (end-with-linkage linkage instruction-sequence)
    (preserving '(cont)
                instruction-sequence
                (compile-linkage linkage)))
  (define (compile-self-evaluating exp target linkage)
    (end-with-linkage
     linkage
     (c-make-instruction-sequence
      '() (list target)
      (c-append (list '|object_free(&| target '|);|
                      target '| = |)
                (const exp)
                '(|;|)))))
  (define (compile-variable exp target linkage)
    (end-with-linkage
     linkage
     (c-make-instruction-sequence
      '(env) (list target)
      (c-append (list '|object_free(&| target '|);|
                      target '| = lookup_var_val(c_str_to_datum("|)
                (c-symbol->c exp)
                '(|"));|)))))
  (define (compile-quoted exp target linkage)
    (end-with-linkage
     linkage
     (c-make-instruction-sequence
      '() (list target)
      (c-append (list '|object_free(&| target '|);|
                      target '| = |)
                (const (c-cadr exp))
                '(|;|)))))
  (define (compile-assignment exp target linkage)
    ((lambda (var get-value-code)
       (end-with-linkage
        linkage
        (preserving '(env)
                    get-value-code
                    (c-make-instruction-sequence
                     '(env val) (list target)
                     (c-append '(|{Object t = set_var_val(c_str_to_datum("|)
                               (c-symbol->c var)
                               (list '|"));
                                   object_free(&| target '|);|
                                   target '| = t;}|))))))
     (c-cadr exp)
     (compile (c-caddrexp) 'val 'next)))
  (define (compile-definition exp target linkage)
    ((lambda (var get-value-code)
       (end-with-linkage
        linkage
        (preserving '(env)
                    get-value-code
                    (c-make-instruction-sequence
                     '(env val) (list target)
                     (c-append '(|{Object t = def_var_val(c_str_to_datum("|)
                               (c-symbol->c var)
                               (list '|"));
                                   object_free(&| target '|);|
                                   target '| = t;}|))))))
     (c-definition-variable exp)
     (compile (definition-value exp) 'val 'next)))
  (define (compile-if exp target linkage)
    ((lambda (f-branch after-if)
       ((lambda (consequent-linkage)
          ((lambda (p-code c-code a-code)
             (preserving
              '(env cont)
              p-code
              (append-instruction-sequences
               (c-make-instruction-sequence
                '(val) '()
                (list '|if(val.type==BOOLEAN && !val.boolean){
                        goto | f-branch '|;}|))
               (parallel-instruction-sequences
                c-code
                (append-instruction-sequences
                 (c-make-instruction-sequence
                  '() '()
                  (list f-branch '|:;|))
                 a-code))
               (if (eq? linkage 'next)
                   (c-make-instruction-sequence
                    '() '()
                    (list after-if '|:;|))
                   (c-empty-instruction-sequence))
               )))
           (compile (c-cadr exp) 'val 'next)
           (compile (c-caddr exp) target consequent-linkage)
           (compile (c-if-alternative exp) target linkage)))
        (if (eq? linkage 'next) after-if linkage)))
     (make-label 'false_branch)
     (make-label 'after_if)))
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
             (c-make-instruction-sequence
              '(env) (list target)
              (list '|object_free(&| target '|);|
                    target '| = make_compiled_procedure(&&| proc-entry '|);|)
              ))
            (compile-lambda-body exp proc-entry))
           (if (eq? lambda-linkage after-lambda)
               (c-make-instruction-sequence
                '() '() (list after-lambda '|:;|))
               (c-empty-instruction-sequence))))
        (if (eq? linkage 'next) after-lambda linkage)))
     (make-label 'entry)
     (make-label 'after_lambda)))
  (define (compile-lambda-body exp proc-entry)
    ((lambda (formals)
       (append-instruction-sequences
        (c-make-instruction-sequence
         '(env proc argl) '(env)
         (c-append (list proc-entry
                         '|:env = compiled_procedure_env();
                          env = extend_environment(|)
                   (const formals)
                   '(|);|)))
        (compile-sequence (c-cddr exp) 'val 'return)))
     (c-cadr exp)))
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
           (c-make-instruction-sequence
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
             (c-make-instruction-sequence
              '(val) '(argl)
              '(|argl = cons(object_copy(val),empty);|))))))
     (c-reverse operand-codes)))
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
      (c-make-instruction-sequence
       '(val argl) '(argl)
       '(|argl = cons(object_copy(val), argl);|)))))
  (define (compile-procedure-call target linkage)
    ((lambda (primitive-branch after-call)
       ((lambda (compiled-linkage)
          (append-instruction-sequences
           (c-make-instruction-sequence
            '(proc) '()
            (list '|if (proc.type == PROC) { goto |
                  primitive-branch '|;}|))
           (parallel-instruction-sequences
            (compile-proc-appl target compiled-linkage)
            (append-instruction-sequences
             (c-make-instruction-sequence
              '() '()
              (list primitive-branch '|:;|))
             (end-with-linkage
              linkage
              (c-make-instruction-sequence
               '(proc argl)
               (list target)
               (list '|object_free(&| target '|);|
                     target '| = proc.proc(argl); |)
               ))))
           (if (eq? linkage 'next)
               (c-make-instruction-sequence
                '() '() (list after-call '|:;|))
               (c-empty-instruction-sequence))
           ))
        (if (eq? linkage 'next) after-call linkage)))
     (make-label 'primitive_branch)
     (make-label 'after_call)))
  (define (compile-proc-appl target linkage)
    (if (and (eq? target 'val) (not (eq? linkage 'return)))
        (c-make-instruction-sequence
         '(proc) all-regs
         (list '|cont.cont = &&| linkage '|;
                 object_free(&val);
                 val = compiled_procedure_entry(proc);
                 goto *val.cont;|))
        (if (and (not (eq? target 'val))
                 (not (eq? linkage 'return)))
            ((lambda (proc-return)
               (c-make-instruction-sequence
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
                (c-make-instruction-sequence
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
  (define (append-instruction-sequences . seqs)
    (define (append-2-sequences seq1 seq2)
      (c-make-instruction-sequence
       (c-list-union (c-registers-needed seq1)
                     (c-list-difference (c-registers-needed seq2)
                                        (c-registers-modified seq1)))
       (c-list-union (c-registers-modified seq1)
                     (c-registers-modified seq2))
       (c-append (c-statements seq1) (c-statements seq2))))
    (define (append-seq-list seqs)
      (if (null? seqs)
          (c-empty-instruction-sequence)
          (append-2-sequences (car seqs)
                              (append-seq-list (cdr seqs)))))
    (append-seq-list seqs))
  (define (preserving regs seq1 seq2)
    (if (null? regs)
        (append-instruction-sequences seq1 seq2)
        ((lambda (first-reg)
           (if (and (c-needs-register? seq2 first-reg)
                    (c-modifies-register? seq1 first-reg))
               (preserving (cdr regs)
                           (c-make-instruction-sequence
                            (c-list-union (list first-reg)
                                          (c-registers-needed seq1))
                            (c-list-difference
                             (c-registers-modified seq1)
                             (list first-reg))
                            (c-append
                             (list '|save(| first-reg '|);|)
                             (c-statements seq1)
                             (list '|object_free(&| first-reg '|);|
                                   first-reg '| =restore();|)))
                           seq2)
               (preserving (cdr regs) seq1 seq2)))
         (car regs))))
  (define (tack-on-instruction-sequence seq body-seq)
    (c-make-instruction-sequence
     (c-registers-needed seq)
     (c-registers-modified seq)
     (c-append (c-statements seq) (c-statements body-seq))))
  (define (parallel-instruction-sequences seq1 seq2)
    (c-make-instruction-sequence
     (c-list-union (c-registers-needed seq1)
                   (c-registers-needed seq2))
     (c-list-union (c-registers-modified seq1)
                   (c-registers-modified seq2))
     (c-append (c-statements seq1) (c-statements seq2))))

  (define input-file (open-input-file "input.scm"))
  (define output-file (open-output-file "output.c"))
  (define data (read input-file))
  (define code (compile data 'val 'next))
  (print-code code output-file)
  'compiled
  )
