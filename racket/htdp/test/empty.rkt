#! /usr/bin/env racket
#lang racket

(define (check-empty my-list)
	(empty? my-list))

(define not-empty
	(cons 4 empty))

(print (check-empty not-empty))
(print (check-empty empty))
