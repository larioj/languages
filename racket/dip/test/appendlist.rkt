#! /usr/bin/env racket
#lang racket

(define la (list 1 2 3 4 5))
(define lb (list 6 7 8 9 0))

(define (join l1 l2)
	(cond
		[(empty? l2) l1]
		[(empty? l1) l2]
		[else (cons (first l1) (join (rest l1) l2))]
	)
)

(display (join la lb))
