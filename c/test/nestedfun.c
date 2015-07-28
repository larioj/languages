#include <stdio.h>
#define def(x, name) typeof(x) name

double foo(double a, double b) {
	double square(double z) { return z*z; }
	return square(a) + square(b);
}

int main() {
	int a = 5;
	def(a, b) = 6;
	printf("%f", foo(1.0, 2.0));
	printf("type of %d is %d\n", a, b);
}
