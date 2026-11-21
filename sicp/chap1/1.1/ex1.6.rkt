#lang sicp

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
    (else else-clause)))

(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
    guess
    (sqrt-iter (improve guess x) x)))

#|
An infinite loop happens since new-if is an ordinary procedure so it uses applicative-order
meaning all arguments are evaluated before the procedure is called, since the third argument 
triggers a recursive call again and again

using the original if works because it evaluates the predicate first and then the corresponsing
expression (true -> then-clause, false -> else-clause)
|#