(begin
  (define (acos z) (* +i (log (- z (* -i (sqrt (- 1 (square z))))))))
  (define (asin z)(* -i (log (+ (* +i z) (sqrt (- 1 (square z)))))))
  (define (atan z . args)
    (if (null? args)
        (/ (- (log (+ 1 (* +i z))) (log (- 1 (* +i z)))) +2i)
        (angle (make-rectangular (car args) z))))
  (define (cos z) (/ (+ (exp (* +i z)) (exp (* -i z))) 2))
  ;; exp primitive
  ;; infinite? primitive
  (define (finite? z) (and (not (infinite? z)) (not (nan? z))))
  ;; log primitive
  ;; nan? primitive
  (define (sin z) (/ (- (exp (* +i z)) (exp (* -i z))) (* 2 +i)))
  (define (sqrt z) (expt z 1/2))
  (define (tan z) (/ (sin z) (cos z)))
  'inexact-library
  )
