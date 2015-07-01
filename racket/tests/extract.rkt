#! /usr/bin/env racket
#lang racket

(define (extract str)
	(printf "something...\n")
	(substring str 4 7))

(extract "The cat out of the bag.")

(define (reply s)
	(cond
		[(equal? "hello" (substring s 0 5))
		 "hi!"]
		[(equal? "goodbye" (substring s 0 7))
		 "bye!"]
		[(equal? "?" (substring s (- (string-length s) 1)))
		 "I don't know."]
		[else "huh?"]))

(reply "hello racket.")
(reply "goodbye racket.")
(reply "What is you favorite color?")
(reply "I like black.")

(list "hello" "how" "are" "you" "?")

(foldl (lambda (elem1 elem2 v)
				 (+ v (* elem1 elem1) elem2))
			 0 (list 1 2 3) (list 1 1 1))

(map (lambda (s n) (substring s 0 n))
		 (list "peanuts" "popcorn" "crackerjack")
		 (list 6 3 7))
