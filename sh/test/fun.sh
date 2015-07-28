#! /bin/bash

# Does location matter?

beforefun() {
	echo before
}

beforefun

# Not found. Must be declared after.
afterfun

afterfun() {
	echo after
}
