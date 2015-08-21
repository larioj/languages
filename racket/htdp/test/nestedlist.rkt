#! /usr/bin/env racket
#lang racket

(define a (list 1 2 3 4))
(define b (list 5 6 7 8 9))
(define c (list 10 11 12 13))
(define ab (cons a b))
(define bc (cons b c))
(define ac (cons a c))
(define acab (cons ac ab))
(define acbc (cons ac bc))

(print acbc)
