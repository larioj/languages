#! /usr/bin/env racket
#lang racket

;; inserts item into sorted list
(define (insert-into-sorted num my-list)
	(cond
		[(empty? my-list) (cons num empty)]
		[(< num (first my-list)) (cons num my-list)]
		[else (cons
						(first my-list)
						(insert-into-sorted num (rest my-list))
					)
		]
	)
)

;; Test example.
(define sorted-list
	(cons 1 (cons 2 (cons 4 empty)))
)
;;(print (insert-into-sorted 3 sorted-list))

;; sorts a list.
(define (sort-rand-list my-list)
	(cond
		[(empty? my-list) empty]
		[else
			(insert-into-sorted
				(first my-list)
				(sort-rand-list (rest my-list))
			)
		]
	)
)

;; Testing
;; Creates a random list of length n.
(define (rand-list n)
	(cond
		[(= n 0) empty]
		[else (cons
						(random 100)
						(rand-list (- n 1))
					)
		]
	)
)

(define a-rand-list (rand-list 10))
;; (print a-rand-list)

(print (sort-rand-list sorted-list))
