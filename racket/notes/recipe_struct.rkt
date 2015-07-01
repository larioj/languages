#! /usr/bin/env racket
#lang racket

;; Data Analysis and Definitions:
(define-struct student (last first teacher))
;; A student is a structure: (make-student l f t) where l, f, and t are symbols.

;; Contract: subst-teacher : student symbol -> student

;; Purpose: to create a student structure with a new teacher
;; name if the teacher's name matches 'fritz

;; Examples:
;; (subst-teacher (make-student 'find 'mathew 'fritz) 'elize)
;; =
;; (make-student 'find 'mathew 'elize)
;; (subst-teacher (make-student 'find 'mathew 'amanda) 'elize)
;; =
;; (make-student 'find 'mathew 'amanda)

;; Template:
;; (define (process-student a-student a-teacher)
;; ... (student-last a-student) ...
;; ... (student-first a-student) ...
;; ... (student-teacher a-teacher) ...)

;; Definition:
(define (subst-teacher a-student a-teacher)
	(cond
		[(symbol=? (student-teacher a-student) 'fritz)
		 (make-student (student-last a-student)
									 (student-first a-student)
									 a-teacher)]
		[else a-student]))

;; Tests:
(subst-teacher (make-student 'find 'mathew 'fritz) 'elize)
;; expected value:
(make-student 'find 'mathew 'elize)

(subst-teacher (make-student 'find 'mathew 'amanda) 'elize)
;; expected value:
(make-student 'find 'mathew 'amanda)
