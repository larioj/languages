#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(int argc, char **argv) {
	int max = 1000000, acum = 1, idx = 2;
	for (int i = 1; idx < max; i++) {
		if (1 == gcd(acum, i)) {
			idx++;
			acum *= i;
			printf("%d ", i);
		}
	}
	return 0;
}

int gcd(int a, int b) {
	if (!a) return b;
	if (!b) return a;
	return gcd(b, a % b);
}
