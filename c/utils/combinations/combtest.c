#include <stdio.h>
#include "comb.h"
#include "vec.h"

int main() {
	size_t elements = 9, choices = 5;
	comb(elements, choices, &vec_print);
	// perm(elements, choices, &vec_print);
}
