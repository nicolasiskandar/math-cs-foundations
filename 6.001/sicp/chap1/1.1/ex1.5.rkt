#lang sicp

(define (p) (p))

(define (test x y)
  (if (= x 0) 0 y))

#|
(test 0 (p))

in applicative-order: Infinite loop since all arguments are evaluated and
 (define (p) (p)) results in an infinite loop and never returns

in normal-order: 0 since not all arguments are evaluated
|#