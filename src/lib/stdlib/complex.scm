(begin
  ;; angle primitive
  ;; imag-part primitive
  (define (magnitude z)
    (sqrt (+ (square (real-part z))
             (square (imag-part z)))))
  (define (make-polar x3 x4) (* x3 (exp (* +1i x4))))
  (define (make-rectangular x1 x2) (+ x1 (* +1i x2)))
  ;; real-part primitive
  'complex-library
  )
