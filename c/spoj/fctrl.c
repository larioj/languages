#include <stdio.h>
#include <stdlib.h>

int zerocount(int a);

int main(int argc, char **argv) {
	int c, a, res;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &a);
		res = zerocount(a);
		printf("%d\n", res);
	}
	return 0;
}

int zerocount(int a) {
	int zeros = 0, n = 5, div;
	while ((div = a / n)) {
		zeros += div;
		n *= 5;
	}
	return zeros;
}
