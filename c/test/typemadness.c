#include <stdio.h>

int foo() {
	return 1;
}

int (*bar())() {  // a function that returns a function pointer.
	return &foo;
}

int main() {
	int (*fun)(); // pointer to a function of returning int.
	int (*fun2)(); // pointer to a function of returning int.
	fun = &foo;
	fun2 = bar();
	return 0;
}
