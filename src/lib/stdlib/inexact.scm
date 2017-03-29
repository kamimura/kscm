(begin
  (define (acos z) (* +1i (log (- z (* -1i (sqrt (- 1 (square z))))))))
  (define (asin z)(* -1i (log (+ (* +1i z) (sqrt (- 1 (square z)))))))
  (define (atan z . args)
    (if (null? args)
        (/ (- (log (+ 1 (* +1i z))) (log (- 1 (* +1i z)))) +2i)
        (angle (make-rectangular (car args) z))))
  (define (cos z) (/ (+ (exp (* +1i z)) (exp (* -1i z))) 2))
  ;; exp primitive
  ;; infinite? primitive
  (define (finite? z) (and (not (infinite? z)) (not (nan? z))))
  ;; log primitive
  ;; nan? primitive
  (define (sin z) (/ (- (exp (* +1i z)) (exp (* -1i z))) 2))
  (define (sqrt z) (expt z 1/2))
  (define (tan z) (/ (sin z) (cos z)))
  'inexact-library
  )
