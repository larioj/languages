#include <stdio.h>

int main() {
	int a = 5;
	int *p = &a;
	size_t b = a + sizeof a;
	printf("%lu\n", b);
	int c = sizeof (int) * *p;
}
