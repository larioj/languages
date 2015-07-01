#include <stdio.h>

double foo(double a, double b) {
	double square(double z) { return z*z; }
	return square(a) + square(b);
}

int main() {
	printf("%f", foo(1.0, 2.0));
}
