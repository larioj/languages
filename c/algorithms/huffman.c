#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void checkargs(int argc, char **argv);

int main(int argc, char **argv) {
	FILE *in, *out;
	checkargs(argc, argv);
	in = fopen(argv[1], "r");
	if (!in) {
		printf("File not found.\n");
	}
	return 0;
}

static void checkargs(int argc, char **argv) {
	if (argc != 3 || strcmp(argv[2], "-d")
			|| strcmp(argv[2], "-e")) {
		printf("Usage: %s filename -[d,e]\n", argv[0]);
		exit(1);
	}
}
