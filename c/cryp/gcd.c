#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(int argc, char **argv) {
	if (3 != argc) {
		printf("usage: %s a b\n", argv[0]);
		exit(1);
	}

	int a, b;
	sscanf(argv[1], "%d", &a);
	sscanf(argv[2], "%d", &b);
	printf("%d\n", gcd(a, b));
	return 0;
}

int gcd(int a, int b) {
	if (0 == a) { return b; }
	if (0 == b) { return a; }
	return gcd(b, a % b);
}
