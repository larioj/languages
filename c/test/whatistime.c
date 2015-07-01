#include <time.h>
#include <stdio.h>
#include <limits.h>

int main() {
	time_t max = ~0UL >> 33;
	time_t rawtime;
	time (&rawtime);
	char n = NUL;
	printf("%s", ctime(&rawtime));
	printf("%ld\n", rawtime);
	printf("%s", ctime(&max));
}
