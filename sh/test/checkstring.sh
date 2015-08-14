#! /bin/bash

truestring="-f"
falsestring="not"

if [[ $truestring == "-"* ]]; then
	echo $truestring
fi

if [[ $falsestring == "-"* ]]; then
	echo $falsestring
fi
