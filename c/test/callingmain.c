#include <stdio.h>

int foo();

int main() {
	static int a = 1;
	printf("In main.\n");
	if (a == 1) {
		a--;
		foo();
	}
	return 0;
}

int foo() {
	printf("Calling Main.\n");
	main();
	return 0;
}
