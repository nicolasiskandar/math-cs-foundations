#lang sicp

(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

#|
  This procedures calculate a + abs(b)
|#

(a-plus-abs-b 3 3)
(a-plus-abs-b 3 -3)