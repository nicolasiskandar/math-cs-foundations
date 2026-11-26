#lang sicp

(define (square x) (* x x))
(define (average x y) (/ (+ x y) 2))
(define (improve guess x)
    (/ (+ (/ x (square guess)) (* 2 guess)) 3))

(define (good-enough? guess next)
  (< (abs (- next guess)) (* 0.001 (abs next))))

(define (qrt-iter guess x)
  (let ((next (improve guess x)))
    (if (good-enough? guess next)
        next
        (qrt-iter next x))))

(define (qrt x)
  (qrt-iter 1.0 x))

(qrt 8)
(qrt 27)
(qrt 1000)
(qrt 0.001)
(qrt -8)