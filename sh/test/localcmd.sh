#! /bin/bash

# test the properties of the local
# function. Namely I'm questioning
# whether I'm allowed to declared two
# or more variables on the same line.

makeglobals() {
	g_one=gone
	g_two=gtwo
}

makeglobals
echo $g_one
echo $g_two

makelocals() {
	# two variables on the same line.
	local l_one l_two
	l_one=lone
	l_two=ltwo
}

makelocals
echo $l_one
echo $l_two

# It works!
