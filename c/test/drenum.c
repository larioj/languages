#include <stdio.h>

// enums!!
enum {
	small = 1, big, giant = 10, huge
};

int main() {
	printf("small: %d\n"
			"big: %d\n"
			"giant: %d\n"
			"huge: %d\n",
			small, big, giant, huge);
}

/* We can see that the ones not explicitly defined
 * are just one more than the last.
 * small: 1
 * big: 2
 * giant: 10
 * huge: 11 */
