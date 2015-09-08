#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Random Number Generator *******************************/
struct random_generator {
	int size, rcount, *elements;
};

void random_generator_seed();
struct random_generator *random_generator_new(int size);
int random_generator_get(struct random_generator *rg);
int random_generator_get_remove(struct random_generator *rg);
void random_generator_remove(struct random_generator *rg, int index);
int random_generator_remaining(struct random_generator *rg);
void random_generator_free(struct random_generator *rg);
void random_generator_print(struct random_generator *rg);
void random_generator_test();
/*********************************************************/

int main(int argc, char **argv) {
	int n;
	struct random_generator *rg;
	if (argc != 2 ||
			!sscanf(argv[1], "%d", &n)) {
		printf("Usage: %s n\n", argv[0]);
	}
	rg = random_generator_new(n);
	while (random_generator_remaining(rg)) {
		printf("%d ", random_generator_get_remove(rg));
	}
	printf("\n");
	return 0;
}

/* Random Number Generator *******************************/
void random_generator_seed() {
/* seed rand() if not already done. */
	static int random_set = 0;
	if (!random_set) {
	  time_t t; srand((unsigned) time(&t));
		random_set = 1;
	}
}

struct random_generator *random_generator_new(int size) {
	/* seed the generator. */
	random_generator_seed();

	/* allocate the random_generator. */
	struct random_generator *rg;
	rg = malloc(sizeof *rg);
	if (!rg)
		return NULL;
	rg->size = size;
	rg->rcount = size;
	rg->elements = malloc(size * sizeof *(rg->elements));
	if (!(rg->elements)) {
		free(rg);
		return NULL;
	}
	for (int i = 0; i < rg->size; i++) {
		(rg->elements)[i] = i;
	}
	return rg;
}

int random_generator_get(struct random_generator *rg) {
	int ridx, res = -1;
	if (rg->rcount) {
		ridx = rand() % rg->rcount;
		res = (rg->elements)[ridx];
	}
	return res;
}

int random_generator_get_remove(struct random_generator *rg) {
	int ridx, res = -1;
	if (rg->rcount) {
		ridx = rand() % rg->rcount;
		res = (rg->elements)[ridx];
		(rg->elements)[ridx] = (rg->elements)[--(rg->rcount)];
	}
	return res;
}

void random_generator_remove(struct random_generator *rg, int index) {
	int i;
	for (i = 0; i < rg->rcount; i++) {
		if ((rg->elements)[i] == index) break;
	}
	if (i < rg->rcount) {
		(rg->elements)[i] = (rg->elements)[--(rg->rcount)];
	}
}

int random_generator_remaining(struct random_generator *rg) {
	return rg->rcount;
}

void random_generator_free(struct random_generator *rg) {
	free(rg->elements);
	free(rg);
}

void random_generator_print(struct random_generator *rg) {
	printf("{");
	printf("size: %d\n", rg->size);
	printf("rcount: %d\n", rg->rcount);
	printf("elements: ");
	for (int i = 0; i < rg->rcount; i++) {
		printf("%d ", (rg->elements)[i]);
	}
	printf("}\n");
}

void random_generator_test() {
	struct random_generator *rg;
	int res, rem = 2;
	const int SIZE = 5;

	/* test new */
	rg = random_generator_new(SIZE);
	random_generator_print(rg);

	/* test remove. */
	random_generator_remove(rg, rem);
	printf("\nremoved: %d\n", rem);
	random_generator_print(rg);

	/* test get. */
	res = random_generator_get(rg);
	printf("\nres: %d\n", res);
	random_generator_print(rg);

	/* test get. */
	res = random_generator_get(rg);
	printf("\nres: %d\n", res);
	random_generator_print(rg);

	/* test get. */
	res = random_generator_get(rg);
	printf("\nres: %d\n", res);
	random_generator_print(rg);

	/* test get. */
	res = random_generator_get(rg);
	printf("\nres: %d\n", res);
	random_generator_print(rg);

	/* test get on empty. */
	res = random_generator_get(rg);
	printf("\nres: %d\n", res);
	random_generator_print(rg);

	/* free random generator. */
	random_generator_free(rg);
}
/*********************************************************/


