#! /usr/bin/env racket
#lang racket
;; Contract: area-of-disk : number -> number

;; Purpose: To compute the area of a disk whose radius is
;; radius.

;; Example: (area-of-disk 5) should produce 78.5

;; Definition: [refines the header]
(define (area-of-disk radius)
	(* pi radius radius))

;; Tests:
(area-of-disk 5)
;; Expected value
78.5

;; Contract: area-of-ring : number number -> number

;; Purpose: To compute the area of a ring whose radius is
;; outer and whose hole has a radius of inner.

;; Example: (area-of-ring 5 3) should produce 50.24

;; Definition: [refines the header]
(define (area-of-ring outer-radius inner-radius)
	(- (area-of-disk outer-radius)
		 (area-of-disk inner-radius)))

;; Tests:
(area-of-ring 5 3)
;; Expected value
50.24
