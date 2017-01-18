(begin
  (define (string-ci<=? string . list-of-string)
    (define (iter string list-of-string)
      (if (null? list-of-string)
          #t
          (if (string<=? (string-foldcase string)
                         (string-foldcase (car list-of-string)))
              (iter (car list-of-string) (cdr list-of-string))
              #f)))
    (iter string list-of-string))

  (define (string-ci<? string . list-of-string)
    (define (iter string list-of-string)
      (if (null? list-of-string)
          #t
          (if (string<? (string-foldcase string)
                         (string-foldcase (car list-of-string)))
              (iter (car list-of-string) (cdr list-of-string))
              #f)))
    (iter string list-of-string))

  (define (string-ci=? string . list-of-string)
    (define (iter string list-of-string)
      (if (null? list-of-string)
          #t
          (if (string=? (string-foldcase string)
                         (string-foldcase (car list-of-string)))
              (iter (car list-of-string) (cdr list-of-string))
              #f)))
    (iter string list-of-string))

  (define (string-ci>=? string . list-of-string)
    (define (iter string list-of-string)
      (if (null? list-of-string)
          #t
          (if (string>=? (string-foldcase string)
                         (string-foldcase (car list-of-string)))
              (iter (car list-of-string) (cdr list-of-string))
              #f)))
    (iter string list-of-string))

  (define (string-ci>? string . list-of-string)
    (define (iter string list-of-string)
      (if (null? list-of-string)
          #t
          (if (string>? (string-foldcase string)
                         (string-foldcase (car list-of-string)))
              (iter (car list-of-string) (cdr list-of-string))
              #f)))
    (iter string list-of-string))

  (define (string-downcase string) (string-map char-downcase string))
  (define (string-foldcase string) (string-map char-foldcase string))
  (define (string-upcase string) (string-map char-upcase string))
  )
