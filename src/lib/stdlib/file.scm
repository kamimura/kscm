(begin
  (define (call-with-input-file string proc)
    (call-with-port (open-input-file string) proc))
  (define (call-with-output-file string proc)
    (call-with-port (open-output-file string) proc))
  ;; delete-file primitive
  ;; file-exists? primitive
  ;; open-binary-input-file primitive
  ;; open-binary-output-file primitive
  ;; open-input-file primitive
  ;; open-output-file primitive
  ;; with-input-from-file
  ;; with-output-to-file
  'file-library
  )
