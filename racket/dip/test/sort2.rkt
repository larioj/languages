#! /usr/bin/env racket
#lang racket

(define (insert n l)
	(cond
		[(empty? l) (cons n empty)]
		[(<= n (first l)) (cons n l)]
		[else (cons (first l) (insert n (rest l)))]
	)
)

;; test
;; (print (insert 4 (list 1 2 3 4 5 6 7)))

(define (lsort l)
	(cond
		[(empty? l) empty]
		[else (insert (first l) (lsort (rest l)))]
	)
)

;; test
(print (lsort (list 5 4 3 2 1)))
