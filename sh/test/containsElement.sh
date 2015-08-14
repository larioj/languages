#! /bin/bash

containsElement() {
	local element
	element=$1
	for other in ${@:2}; do
		if [ $other == $element ]; then
			return 1
		fi
	done
	return 0
}

containsElement $@
echo $?
