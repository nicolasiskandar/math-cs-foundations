#lang sicp

(define tolerance 0.00001)

(define (average a b)
  (/ (+ a b) 2))

(define average-damp
  (lambda (f)
    (lambda (x) (average (f x) x))))

(define (close-enuf? a b)
  (< (abs (- a b)) tolerance))

(define (fixed-point f start)
  (define (iter old new)
    (if (close-enuf? old new)
	new
	(iter new (f new))))
  (iter start (f start)))

(define (sqrt x)
  (fixed-point
    (average-damp (lambda (y) (/ x y)))
    1))

(exact->inexact (sqrt 2))
