#! /bin/bash

gcc rsort.c -o rsort

for i in $(seq 10 10 1000); do
	count=$(./rsort -c $(shuf -i 0-$i))
	echo $count
done
