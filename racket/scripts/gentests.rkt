#! /usr/bin/env racket
#lang racket

(require 2htdp/batch-io)

(define args (current-command-line-arguments))
(define file-name (vector-ref args 0))
(define folder-name (vector-ref args 1))
(define tests-raw (read-lines file-name))

(define (parse l acc)
  (cond
	[(regexp-match? #rx"^--$" l)
	 (let* ([cur (car acc)]
			[tests (cdr acc)]
			[test-name (list-ref cur 0)]
			[test-body (list-ref cur 1)]
			[test-result (list)])
	   (cons (list test-name test-body test-result) tests))]
	[(regexp-match? #rx"^--" l)
	 (let ([test-name (substring l 3)]
		   [test-body (list)])
	   (cons (list test-name test-body) acc))]
	[else
	  (let* ([cur (car acc)]
			 [tests (cdr acc)]
			 [test-name (list-ref cur 0)]
			 [test-body (list-ref cur 1)])
		(cond
		  [(equal? (length cur) 2)
		   (cons (list test-name (append test-body (list l))) tests)]
		  [else
			(let* ([test-result (append (list-ref cur 2) (list l))])
			  (cons (list test-name test-body test-result) tests))]))]))

(define tests-parsed (foldl parse (list) tests-raw))

(define (make-test-name file-name)
  (string-append folder-name file-name ".401"))

(define (make-result-name file-name)
  (string-append folder-name file-name ".401.out"))

(define (make-test test)
  (define test-name (make-test-name (list-ref test 0)))
  (define result-name (make-result-name (list-ref test 0)))
  (define test-body (string-append (string-join (list-ref test 1) "\n") "\n"))
  (define result-body (string-append (string-join (list-ref test 2) "\n") "\n"))
  (write-file test-name test-body)
  (write-file result-name result-body))

(define pr (map make-test tests-parsed))
