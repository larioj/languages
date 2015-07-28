#include <stdio.h>

struct foo {
	int a[4];
};

struct foo f() {
	struct foo myfoo;
	myfoo.a[0] = 0;
	myfoo.a[1] = 1;
	myfoo.a[2] = 2;
	myfoo.a[3] = 3;
	return myfoo;
}

int main() {
	printf("The number is: %d\n", f().a[2]);
	return 1;
}
