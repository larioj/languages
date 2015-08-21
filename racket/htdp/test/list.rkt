#! /usr/bin/env racket
#lang racket

;; Creating a simple list.
(define mylist-1 (cons 4 empty))
(define mylist-2 (cons 5 mylist-1))
(print mylist-2)

;; Creating a random list of length n.
(define (rand-list n)
	(cond
		[(= n 0) empty]
		[else (cons
						(random 100)
						(rand-list (- n 1))
						)]))

(print (rand-list 0))
(print (rand-list 5))
(print (rand-list 100))
