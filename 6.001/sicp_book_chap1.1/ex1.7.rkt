#lang sicp

; (define (good-enough? guess x)
;   (< (abs (- (square guess) x)) 0.001))

#|
The fixed tolerance of 0.001 is bigger than x if x is too small.
Also it's too small for huge x (doubles for instance)
Solution is to check if the next improvement changed a lot relative
to the last guess
|#

(define (square x) (* x x))
(define (average x y) (/ (+ x y) 2))
(define (improve guess x) (average guess (/ x guess)))

(define (good-enough? guess next)
  (< (abs (- next guess)) (* 0.001 (abs next))))

(define (sqrt-iter guess x)
  (let ((next (improve guess x)))
    (if (good-enough? guess next)
        next
        (sqrt-iter next x))))

(define (sqrt x)
  (sqrt-iter 1.0 x))

(sqrt 9)
(sqrt (+ 100 37))
(sqrt (+ (sqrt 2) (sqrt 3)))
(square (sqrt 1000))
(sqrt 0.0001)