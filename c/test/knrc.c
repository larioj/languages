#include <stdio.h>

/* old style. */
int foo();
int bar();

int main() {
	printf("%d\n", foo(10));
	return 0;
}

int bar(a, b) int a, b; {
	printf("hello");
	return 0;
}

int foo(a) int a; {
	a = 5;
	return a;
}
