#! /usr/bin/env racket
#lang racket

;; Quick Sort (Assuming random input)
(define (qsort alon)
	(cond
		[(empty? alon) empty]
		[(empty? (rest alon)) alon]
		[else
			(define pivot (first alon))
			(define higher (aboveeqp pivot (rest alon)))
			(define lower (belowp pivot (rest alon)))
			(merge (qsort lower) (cons pivot (qsort higher)))
		]
	)
)

(define (qfilter fcond pivot alon)
	(cond
		[(empty? alon) empty]
		[(fcond pivot (first alon)) (cons (first alon) (qfilter fcond pivot (rest alon)))]
		[else (qfilter fcond pivot (rest alon))]
	)
)

;; Gets all the elements that are above or equal to pivot.
(define (aboveeqp pivot alon) 
	(qfilter <= pivot alon))

;; Gets all the elements that are bellow to pivot.
(define (belowp pivot alon) 
	(qfilter > pivot alon))

(define (merge lower higher) 
	(cond
		[(empty? lower) higher]
		[(empty? higher) lower]
		[else
			(cons (first lower) (merge (rest lower) higher))]
	)
)

(define mylon (list 2 1 3 5 3 33 67 81 5 33 77 45 99 47 28 75 39 78))
(display (qsort mylon))
