#lang sicp

(define (f_rec n)
  (cond ((< n 3) n)
        (else (+ (f_rec (- n 1))
                 (* 2 (f_rec (- n 2)))
                 (* 3 (f_rec (- n 3)))))))

(define (f n)
  (define (iter a b c count)
    (if (= count n) a
        (iter (+ a (* 2 b) (* 3 c)) a b (+ count 1))))
  (if (< n 3) n
      (iter 2 1 0 2)))

(f_rec 6)
(f 6)