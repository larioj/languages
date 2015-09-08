#include <stdio.h>
#include <stdlib.h>

int fibd(int n);

int main(int argc, char **argv) {
	int n = 0;
	if (2 != argc ||
			1 != sscanf(argv[1], "%d", &n)) {
		printf("usage: %s n\n", *argv);
		exit(1);
	}
	printf("%d\n", fibd(n));
	return 0;
}

int fibd(int n) {
	int one, two, res;
	if (0 == n) return 0;
	if (1 == n) return 1;
	if (2 == n) return 1;
	if (n % 2) {
		one = fibd((n/2));
		two = fibd((n/2) + 1);
		res = two*two + one*one;
	} else {
		one = fibd(n/2 - 1);
		two = fibd(n/2);
		res = two*two + 2*one*two;
	}
	return res;
}
