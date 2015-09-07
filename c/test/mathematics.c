#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);
int lgcd(int a, int b);

int main(int argc, char **argv) {
	int max = 100, val;
	for (int i = 1; i < max; i++) {
		val = (2 * i) - 1;
		if (3 == lgcd(val, 3)) printf("%d ", val/3);
	}
	printf("\n");
	return 0;
}

int gcd(int a, int b) {
	if (!a) return b;
	if (!b) return a;
	return gcd(b, a % b);
}

int lgcd(int a, int b) {
	int ap;
	while (b) {
		ap = a;
		a = b;
		b = ap % b;
	}
	return a;
}
