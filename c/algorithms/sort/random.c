#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pair {
	int bigger, smaller;
};

int numbers[10];
struct pair *pairs;

void fillnumbers() {
	for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
		numbers[i] = rand() % 100;
	}
}

void printnumbers() {
	for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
}

int main(int argc, char **argv) {
	time_t t; srand((unsigned) time(&t));
	fillnumbers();
	printnumbers();
	return 0;
}
