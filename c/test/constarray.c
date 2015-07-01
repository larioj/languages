#include <stdio.h>

int main() {
	int a = 5;
	int b = 6;
	int * const arr[50];
	arr[2] = &a;
	arr[2] = &b;
}
