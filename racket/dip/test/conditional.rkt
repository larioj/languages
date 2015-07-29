#! /usr/bin/env racket
#lang racket

;; How to do conditional evaluation.
(define (my-conditional value)
	(cond
		[(= value 4) "four"]
		[(= value 5) "five"]
		[else "somethin else"]))

(print (my-conditional 4))
(print (my-conditional 5))
(print (my-conditional 14))
