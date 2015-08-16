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
		[else
			(define fel (first alon))
			(define rel (rest alon))
			(cond
				[(fcond fel pivot) (cons fel (aboveeqp pivot rel))]
				[else (aboveeqp pivot rel)]
			)
		]
	)
)

;; Gets all the elements that are above or equal to pivot.
(define (aboveeqp pivot alon) 
	(qfilter >= pivot alon))

;; Gets all the elements that are bellow to pivot.
(define (belowp pivot alon) 
	(qfilter < pivot alon))

(define (merge lower higher) 
	(cond
		[(empty? lower) higher]
		[(empty? higher) lower]
		[else
			(cons (first lower) (merge (rest lower) higher))]
	)
)

(define mylon (list 12 4 5 535 66 3 3 2 88 33 99 36 985))

(display (qsort mylon))
