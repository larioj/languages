#! /usr/bin/env racket
#lang racket
(require net/url)

(define request (compose port->string get-pure-port string->url))
(request "http://www.google.com")

