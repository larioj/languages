#! /bin/bash

makearray() {
	echo one two three
}

array=($(makearray))
echo ${array[0]}
echo ${array[1]}
echo ${array[2]}
