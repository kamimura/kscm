(begin
  (define (assoc obj alist . args)
    (define cmp (if (null? args)
                    (car args)
                    equal?))
    (define (iter alist)
      (if (null? alist)
          #f
          (if (cmp (car (car alist)) obj)
              (car alist)
              (iter (cdr alist)))))
    (iter alist))
  (define (assq obj alist) (assoc obj alist eq?))
  (define (assv obj alist) (assoc obj alist eqv?))
  
  (define (bytevector-copy! to at from . args)
    (define len (length args))
    (define start (if (= len 0) 0 (car args)))
    (define end (if (= len 2) (cadr args) (bytevector-length from)))
    (define (iter i j)
      (if (< j end)
          (begin
            (bytevector-u8-set! to i (bytevector-u8-ref from j))
            (iter (+ i 1) (+ j 1)))))
    (iter at start))
  
  (define (caar pair) (car (car pair)))
  (define (cadr pair) (car (cdr pair)))
  (define (cdar pair) (cdr (car pair)))
  (define (cddr pair) (cdr (cdr pair)))


  )
