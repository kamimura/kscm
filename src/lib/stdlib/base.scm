(begin
  ;; * primitive
  ;; + primitive
  (define (- z1 . zs)
    (if (null? zs)
        (* -1 z1)
        ((lambda ()
           (define (iter z zs)
             (if (null? zs)
                 z
                 (iter (+ z (* -1 (car zs))) (cdr zs))))
           (iter z1 zs)))))
  ;; / primitive
  ;; < primitive
  (define (<= x1 x2 . xs)
    (define (cmp x1 x2) (or (= x1 x2) (< x1 x2)))
    (define (iter x xs)
      (if (null? xs)
          #t
          (if (cmp x (car xs))
              (iter (car xs) (cdr xs))
              #f)))
    (and (cmp x1 x2) (iter x2 xs)))
  ;; = primitive
  (define (> x1 x2 . xs)
    (define (iter x xs)
      (cond ((null? xs) #t)
            ((< (car xs) x) (iter (car xs) (cdr xs)))
            (#t #f)))
    (if (< x2 x1) (iter xs xs) #f))
  (define (>= x1 x2 . xs)
    (define (cmp x1 x2) (or (= x1 x2) (> x1 x2)))
    (define (iter x xs)
      (if (null? xs)
          #t
          (if (cmp x (car xs))
              (iter (car xs) (cdr xs))
              #f)))
    (and (cmp x1 x2) (iter x2 xs)))            
  (define (abs x) (if (< x 0) (- x) x))
  ;; and syntax
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
  ;; apply primitive
  (define (assoc obj alist . compare)
    (define cmp (if (null? compare) equal? (car compare)))
    (define (iter alist)
      (cond ((null? alist) #f)
            ((cmp obj (caar alist)) (car alist))
            (#t (iter (cdr alist)))))
    (iter alist))

  (define (assq obj alist) (assoc obj alist eq?))
  (define (assv obj alist) (assoc obj alist eqv?))
  ;; begin syntax
  ;; binary-port? primitive
  (define (boolean=? boolean1 boolean2 . booleans)
    (define (iter-true blns)
      (cond ((null? blns) #t)
            ((car blns) (iter-true (cdr blns)))
            (#t #f)))
    (define (iter-false blns)
      (cond ((null? blns) #t)
            ((not (car blns)) (iter-false (cdr blns)))
            (#t #f)))
    (cond ((and boolean1 boolean2) (iter-true booleans))
          ((and (not boolean1) (not boolean2)) (iter-false booleans))
          (#t #f)))
  ;; boolean? primitive
  ;; bytevector
  ;; bytevector-append
  ;; bytevector-copy
  ;; bytevector-copy!
  ;; bytevector-length
  ;; bytevector-u8-ref
  ;; bytevector-u8-set!
  ;; bytevector? 
  (define (caar pair) (car (car pair)))
  (define (cadr pair) (car (cdr pair)))
  ;; call-with-current-continuation
  (define (call-with-port port proc)
    ((lambda (obj) (close-port port) obj)
     (proc port)))
  ;; call-with-values
  ;; call/cc
  ;; car primitive
  ;; case
  (define (cdar pair) (cdr (car pair)))
  (define (cddr pair) (cdr (cdr pair)))
  ;; cdr primitive
  ;; ceiling primitive
  ;; char->integer primitive
  ;; char-ready?
  (define (char<=? char1 char2 . chars)
    (define (iter char chars)
      (cond ((null? chars) #t)
            ((<= (char->integer char) (char->integer (car chars)))
             (iter (car chars) (cdr chars)))
            (#t #f)))
    (iter char1 (cons char2 chars)))
  (define (char<? char1 char2 . chars)
    (define (iter char chars)
      (cond ((null? chars) #t)
            ((< (char->integer char) (char->integer (car chars)))
             (iter (car chars) (cdr chars)))
            (#t #f)))
    (iter char1 (cons char2 chars)))
  (define (char=? char1 char2 . chars)
    (define (iter char chars)
      (cond ((null? chars) #t)
            ((= (char->integer char) (char->integer (car chars)))
             (iter (car chars) (cdr chars)))
            (#t #f)))
    (iter char1 (cons char2 chars)))
  (define (char>=? char1 char2 . chars)
    (define (iter char chars)
      (cond ((null? chars) #t)
            ((>= (char->integer char) (char->integer (car chars)))
             (iter (car chars) (cdr chars)))
            (#t #f)))
    (iter char1 (cons char2 chars)))
  (define (char>? char1 char2 . chars)
    (define (iter char chars)
      (cond ((null? chars) #t)
            ((> (char->integer char) (char->integer (car chars)))
             (iter (car chars) (cdr chars)))
            (#t #f)))
    (iter char1 (cons char2 chars)))
  ;; char? primitive
  (define (close-input-port port) (close-port port))
  (define (close-output-port port) (close-port port))
  ;; close-port primitive
  (define complex? number?)
  ;; cond syntax
  ;; cond-expand
  ;; cons primitive
  ;; current-error-port primitive
  ;; current-input-port primitive
  ;; define syntax
  ;; define-record-type
  ;; define-syntax
  ;; define-values
  (define (denominator q) (numerator (/ q)))
  ;; do
  ;; dynamic-wind
  ;; else
  ;; eof-object primitive
  ;; eof-object? primitive
  ;; eq? primitive
  (define (equal? obj1 obj2)
    (cond ((and (pair? obj1) (pair? obj1))
           (if (equal? (car obj1) (car obj2))
               (equal? (cdr obj1) (cdr obj2))
               #f))
          ((and (vector? obj1) (vector? obj2))
           (equal? (vector->list obj1) (vector->list obj2)))
          ((and (string? obj1) (string? obj2))
           (equal? (string->list obj1) (string->list obj2)))
          ((and (bytevector? obj1) (bytevector? obj2))
           (equal? (utf8->string obj1) (uf8->string obj2)))
          ((or (and (boolean? obj1) (boolean? obj2))
               (and (symbol? obj1) (symbol? obj2))
               (and (number? obj1) (number? obj2))
               (and (char? obj1) (char? obj2))
               (and (port? obj1) (port? obj2))
               (and (null? obj1) (null? obj2)))
           (eqv? obj1 obj2))
          (#t #f)))
  ;; eqv? primitive
  ;; error primitive
  ;; error-object-irritants primitive
  ;; error-object-message primitive
  ;; error-object? primitive
  (define (even? n) (not (odd? n)))
  ;; exact primitive
  ;; exact-integer-sqrt
  (define (exact-integer? z) (and (exact? z) (integer? z)))
  ;; exact? primitive
  (define (expt z1 z2)
    (if (and (exact-integer? z2))
        (if (>= z2 0)
            ((lambda ()
               (define (iter k result)
                 (if (= k 0)
                     result
                     (iter (- k 1) (* z1 result))))
               (iter z2 1)))
            ((lambda ()
               (define (iter k result)
                 (if (= k 0)
                     result
                     (iter (+ k 1) (* (/ 1 z1) result)))))))
        (exp (* z2 (log z1)))))
  ;; features
  ;; file-error? primitive
  ;; floor primitive
  (define (floor-quotient n1 n2) (floor (/ n1 n2)))
  (define (floor-remainder n1 n2) (- n1 (* n2 (floor-quotient n1 n2))))
  ;; floor/
  ;; flush-output-port primitive
  (define (for-each proc list)
    (if (not (null? list))
        ((lambda ()
           (proc (car list))
           (for-each proc (cdr list))))))
  (define (gcd . ns)
    (define (inner m n)
      (if (= n 0)
          m
          (inner n (floor-remainder m n))))
    (define (iter n ns)
      (if (null? ns)
          n
          (iter (inner (abs n)
                       (abs (car ns)))
                (cdr ns))))
    (iter 0 ns))
  ;; get-output-bytevector
  ;; get-output-string
  ;; guard
  ;; if syntax
  ;; include
  ;; include-ci
  (define (inexact z) (* 1.0 z))
  ;; input-port-open? primitive
  ;; input-port? primitive
  ;; integer->char primitive
  (define (integer? obj) (and (number? obj) (= obj (round obj))))
  ;; lambda syntax
  (define (lcm . ns)
    (define (inner m n) (/ (* m n) (gcd m n)))
    (define (iter n ns)
      (if (null? ns)
          n
          (iter (inner (abs n) (abs (car ns)))
                (cdr ns))))
    (iter 1 ns))
  (define (length list)
    (define (iter list n)
      (if (null? list)
          n
          (iter (cdr list) (+ n 1))))
    (iter list 0))
  ;; let
  ;; let*
  ;; let*-values
  ;; let-syntax
  ;; let-values
  ;; let-rec
  ;; letrec*
  ;; letrec->syntax
  (define (list . objs) objs)
  ;; list->string primitive
  ;; list->vector primitive
  (define (list-copy obj)
    (if (pair? obj)
        (cons (car obj) (list-copy (cdr obj)))
        obj))
  (define (list-ref list k)
    (if (= k 0)
        (car list)
        (list-ref (cdr list) (- k 1))))
  (define (list-set! list k obj)
    (if (= k 0)
        (set-car! list obj)
        (list-set! (cdr list) (- k 1) obj)))
  (define (list-tail list k)
    (if (= k 0)
        list
        (list-tail (cdr list) (- k 1))))
  (define (list? obj)
    (cond ((null? obj) #t)
          ((pair? obj) (list? (cdr obj)))
          (#t #f)))
  ;; make-bytevector
  (define (make-list k . fill)
    (define f (if (null? fill) '() (car fill)))
    (define (iter k result)
      (if (= k 0)
          result
          (iter (- k 1) (cons f result))))
    (iter k '()))
  ;; make-parameter
  (define (make-string k . char)
    (define c (if (null? char) #\k (car char)))
    (list->string (make-list k c)))
  (define (make-vector k . fill)
    (list->vector (make-list k fill)))
  (define (map proc list)
    (if (null? list)
        '()
        (cons (proc (car list))
              (map proc (cdr list)))))
  (define (max x . xs)
    (define (iter x xs)
      (if (> x (car xs))
          (iter (car xs) (cdr xs))
          #f))
    (iter x xs))
  (define (member obj list . compare)
    (define cmp (if (null? compare) equal? (car compare)))
    (define (iter list)
      (cond ((null? list) #f)
            ((cmp (car list) obj) list)
            (#t (iter (cdr list)))))
    (iter list))
  (define (memq obj list) (member obj list eq?))
  (define (memv obj list) (member obj list eqv?))
  (define (min x . xs)
    (define (iter x xs)
      (if (< x (car xs))
          (iter (car xs) (cdr xs))
          #f))
    (iter x xs))
  ;; modulo
  (define (negative? x) (< x 0))
  (define (newline . port)
    (if (null? port)
        (display #\newline)
        (display #\newline (car port))))
  (define (not obj) (if obj #f #t))
  (define (null? obj) (eq? obj '()))
  ;; number->string primitive
  ;; number? primitive
  ;; numerator primitive
  (define (odd? n) (= (floor-remainder n 2) 1))
  ;; open-input-bytevector
  ;; open-input-string
  ;; open-output-bytevector
  ;; open-output-string
  ;; or syntax
  ;; output-port-open? primitive
  ;; output-port? primitive
  ;; pair? primitive
  ;; parameterize
  ;; peek-char primitive
  ;; peek-u8
  (define (port? obj)
    (or (input-port? obj)
        (output-port? obj)
        (textual-port? obj)
        (binary-port? obj)))
  (define (positive? x) (< 0 x))
  ;; procedure? primitive
  ;; quasiquote
  ;; quote syntax
  ;; quotient
  ;; raise primitive
  ;; raise-continuable
  (define (rational? obj)
    (and (real? obj)
         (or (exact? obj)
             (= obj (exact obj)))))
  (define (rationalize x y)
    (define diff (abs y))           
    (define low (- x diff))
    (define high (+ x diff))
    (define proc (if (and (exact? x) (exact? y)) exact inexact))
    (if (<= (* low high) 0)
        (proc 0)
        (if (= low high)
            (proc low)
            ((lambda ()
               (define sign (if (positive? x) 1 -1))
               (define low0 (if (positive? sign) low (abs high)))
               (define high0 (if (positive? sign) high (abs low)))
               (define (between? x) (and (<= low0 x) (<= x high0)))
               (define (stern-brocot-tree pnum pden qnum qden)
                 (define a (/ (+ pnum qnum)
                              (+ pden qden)))
                 (if (between? a)
                     a
                     ((lambda ()
                        (define num (numerator a))
                        (define den (denominator a))
                        (if (< high0 a)
                            (stern-brocot-tree pnum pden
                                               num den)
                            (stern-brocot-tree num den
                                               qnum qden))))))
               (proc (* sign (stern-brocot-tree 0 1 1 0))))))))
  ;; read-bytevector
  ;; read-bytevector!
  ;; read-char primitive
  ;; read-error? primitive
  (define (read-line . port)
    (define p (if (null? port) (current-input-port) (car port)))
    (define (iter result)
      ((lambda (c)
         (if (or (eqv? c #\newline)
                 (eqv? c #\return)
                 (eof-object? c))
             (list->string (reverse result))
             (iter (cons c result))))
       (read-char p)))
    (iter '()))
  (define (read-string k . port)
    (define p (if (null? port) (current-input-port) (car port)))
    (define (iter i result)
      (if (= i k)
          (list->string (reverse result))
          (begin
            (define c (read-char p))
            (if (eof-object? c)
                (if (null? result)
                    (eof-object)
                    (list->string (reverse result)))
                (iter (+ i 1) (cons c result))))))
    (iter 0 '()))
  ;; read-u8
  (define (real? obj) (and (number? obj) (zero? (imag-part obj))))
  ;; remainder
  (define (reverse list)
    (define (iter list result)
      (if (null? list)
          result
          (iter (cdr list) (cons (car list) result))))
    (iter list '()))
  ;; round primitive
  ;; set! syntax
  ;; set-car! primitive
  ;; set-cdr! primitive
  (define (square z) (* z z))
  (define (string . chars)
    (define (iter chars result)
      (if (null? chars)
          (list->string (reverse result))
          (iter (cdr chars) (cons (car chars) result))))
    (iter chars '()))
  ;; string->list primitive
  ;; (define (string->number
  ;; string->symbol primitive
  ;; string->utf8
  (define (string->vector string . args)
    (define start (if (null? args) 0 (car args)))
    (define end (if (or (null? args) (null? (cdr args)))
                    (string-length string)
                    (cadr args)))
    (list->vector (string->list (string-copy string start end))))
  (define (string-append . strings)
    (define (iter1 strings result)
      (if (null? strings)
          (reverse result)
          (iter1 (cdr strings) (cons (string->list (car strings)) result))))
    (define (iter2 list-of-list)
      (if (null? list-of-list)
          '()
          (append (car list-of-list)
                  (iter2 (cdr list-of-list)))))
    (list->string (iter2 (iter1 strings '()))))
  (define (string-copy string . args)
    (define start (if (null? args) 0 (car args)))
    (define end (if (or (null? args)
                        (null? (cdr args)))
                    (string-length string)
                    (cadr args)))
    (define len (- end start))
    (define list-of-char (list-tail (string->list string) start))
    (define (iter k list result)
      (if (= k 0)
          (reverse result)
          (iter (- k 1) (cdr list) (cons (car list) result))))
    (list->string (iter len list-of-char '())))

  (define (string-copy! to at from . args)
    (define start (if (null? args) 0 (car args)))
    (define end (if (or (null? args) (null? (cdr args)))
                    (string-length from)
                    (cadr args)))
    (define (iter i j)
      (if (< j end)
          ((lambda ()
             (string-set! to i (string-ref from j))
             (iter (+ i 1) (+ j 1))))))
    (iter at start))
  (define (string-fill! string fill . args)
    (define start (if (null? args) 0 (car args)))
    (define end (if (or (null? args) (null? (cdr args)))
                    (string-length string)
                    (cadr args)))
    (define (iter i)
      (if (< i end)
          ((lambda ()
             (string-set! string i fill)
             (iter (+ i 1))))))
    (iter start))
  (define (string-for-each proc string)
    (for-each (lambda (c) (proc c))
              (string->list string)))
  (define (string-length string) (length (string->list string)))
  (define (string-map proc string)
    (list->string (map proc (string->list string))))
  (define (string-ref string k) (list-ref (string->list string) k))
  ;; string-set! primitive
  (define (string<=? string1 string2 . strings)
    (define (iter string strings)
      (cond ((null? strings) #t)
            ((or (string<? string (car strings))
                 (string=? string (car strings)))
             (iter (car string) (cdr strings)))
            (#t #f)))
    (iter string1 (cons string2 strings)))
  (define (string<? string1 string2 . srrings)
    (define (cmp string1 string2)
      (define (iter list1 list2)
        (cond ((null? list1) #t)
              ((null? list2) #f)
              ((char<? (car list1) (car list2))
               (iter (cdr list1) (cdr list2)))
              (#t #f)))
      (iter string1 string2))
    (define (iter string strings)
      (cond ((null? strings) #t)
            ((cmp string (car strings))
             (iter (car strings) (cdr strings)))
            (#t #f)))
    (iter string1 (cons string2 strings)))
  (define (string=? string1 string2 . strings)
    (define (cmp string1 string2)
      (define (iter list1 list2)
        (cond ((null? list1) #t)
              ((null? list2) #f)
              ((char=? (car list1) (car list2))
               (iter (cdr list1) (cdr list2)))
              (#t #f)))
      (iter string1 string2))
    (define (iter string strings)
      (cond ((null? strings) #t)
            ((cmp string (car strings))
             (iter (car strings) (cdr strings)))
            (#t #f)))
    (iter string1 (cons string2 strings)))          
  (define (string>=? string1 string2 . strings)
    (define (iter string strings)
      (cond ((null? strings) #t)
            ((or (string>? string (car strings))
                 (string=? string (car strings)))
             (iter (car string) (cdr strings)))
            (#t #f)))
    (iter string1 (cons string2 strings)))
  (define (string>=? string1 string2 . strings)
    (define (iter string strings)
      (cond ((null? strings) #t)
            ((string<=? (car strings) string))
             (iter (car string) (cdr strings)))
            (#t #f))
    (iter string1 (cons string2 strings)))
  (define (string>=? string1 string2 . strings)
    (define (iter string strings)
      (cond ((null? strings) #t)
            ((string<? (car strings) string))
             (iter (car string) (cdr strings)))
            (#t #f))
    (iter string1 (cons string2 strings)))
  ;; string? primitive
  ;; substring
  ;; symbol->string primitive
  (define (symbol=? symbol1 symbol2 . symbols)
    (define (iter symbol symbols)
      (cond ((null? symbols) #t)
            ((eq? symbol (car symbols))
             (iter (car symbols) (cdr symbols)))
            (#t #f)))
    (iter symbol1 (cons symbol2 symbols)))
  ;; symbol? primitive
  ;; syntax-error
  ;; syntax-rules
  ;; textual-port? primitive
  ;; truncate primitive
  (define (truncate-quotient n1 n2) (truncate (/ n1 n2)))
  (define (truncate-remainder n1 n2) (- n1 (* n2 (truncate (/ n1 n2)))))
  ;; truncate/
  ;; u8-ready?
  ;; unless
  ;; unquote
  ;; unquote-splicing
  ;; utf8->string
  ;; values
  (define (vector . objs) (list->vector objs))
  ;; vector->list primitive
  (define (vector->string vector . args)
    (define start (if (null? args) 0 (car args)))
    (define end (if (or (null? args) (null? (cdr args)))
                    (vector-length vector)
                    (cadr args)))
    (list->string (vector->list vector start end)))
  (define (vector-append . vectors)
    (list->vector (apply append (map (lambda (vector) (vector->list vector))
                                     vectors))))
  (define (vector-copy vector . args)
    (define start (if (null? args) 0 (car args)))
    (define end (if (or (null? args) (null? (cdr args)))
                    (vector-length vector)
                    (cadr args)))
    (define vec (make-vector (- end start)))
    (define (iter i j)
      (if (= j end)
          vec
          (begin
            (vector-set! vec i (vector-ref vector j))
            (iter (+ i 1) (+ j 1)))))
    (iter 0 start))
  (define (vector-copy! to at from . args)
    (define start (if (null? args) 0 (car args)))
    (define end (if (or (null? args) (null? (cdr args)))
                    (vector-length from)
                    (cadr args)))
    (define (iter i j)
      (if (< j end)
          (begin
            (vector-set! to i (vector-ref from j))
            (iter (+ i 1) (+ j 1)))))
    (iter at start))
  (define (vector-fill! vector fill . args)
    (define start (if (null? args) 0 (car args)))
    (define end (if (or (null? args) (null? (cdr args)))
                    (vector-length vector)
                    (cadr args)))
    (define (iter i)
      (if (< i end)
          ((lambda ()
             (vector-set! vector i fill)
             (iter (+ i 1))))))
    (iter start))  
  (define (vector-for-each proc vector)
    (for-each proc (vector->list)))
  ;; vector-length primitive
  (define (vector-map proc vector)
    (list->vector (map proc (vector->list vector))))
  ;; vector-ref primitive
  ;; vector-set! primitive
  ;; vector? primitive
  ;; when
  ;; with-exception-handler
  ;; write-bytevector
  (define (write-char char . port)
    (define p (if (null? port) (current-output-port) (car port)))
    (display char port))
  (define (write-string string . args)
    (define port (if (null? args)
                     (current-output-port)
                     (car args)))
    (define start (if (or (null? args) (null? (cdr args)))
                      0
                      (cadr args)))
    (define end (if (or (null? args) (null? (cdr args)) (null? (cddr args)))
                    (string-length string)
                    (caddr args)))
    (display (string-copy string start end) port))
  ;; wirte-u8
  (define (zero? z) (= z 0))
  'base-library
  )
