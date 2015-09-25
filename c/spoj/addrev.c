#include <stdio.h>
#include <stdlib.h>

int revadd(int a, int b);
int revnum(int a);

int main(int argc, char **argv) {
	int c, a, b, rev;
	scanf("%d", &c);
	while (c--) {
		scanf("%d %d", &a, &b);
		rev = revadd(a, b);
		printf("%d\n", rev);
	}
	return 0;
}

int revadd(int a, int b) {
	return revnum(revnum(a) + revnum(b));
}

int revnum(int a) {
	int res = 0;
	while(a) {
		res *= 10;
		res += a % 10;
		a /= 10;
	}
	return res;
}
