#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Square Matrix ******************************************/
struct square_matrix {
	int size;
	unsigned char *elements;
};

#define ROW(idx, size) ((idx) / (size))
#define COL(idx, size) ((idx) % (size))
#define IDX(row, col, size) (((row) * (size)) + (col))

struct square_matrix *square_matrix_new(int size);
void square_matrix_set(struct square_matrix *mat, int row,
		int col, unsigned char val);
unsigned char square_matrix_get(struct square_matrix *mat,
		int row, int col);
void square_matrix_free(struct square_matrix *mat);
void square_matrix_print(struct square_matrix *mat);
void square_matrix_test();
/*********************************************************/


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


/* Record ************************************************/
#define EQ 7
#define GT 9
#define LT 1
#define OPP(val) (val == GT? LT : GT)

struct record {
	struct square_matrix *mat;
	struct random_generator *rg;
};

struct pair { int r, c; };
struct record *record_new(int size);
void record_free(struct record *rec);
int record_size(struct record *rec);
void record_mark(struct record *rec, int row, int col, int val);
struct pair record_pair(struct record *rec);
int record_filled(struct record *rec);
void record_positions(struct record *rec, int *positions);
void record_print(struct record *rec);
void record_test();
/*********************************************************/


/* Random Sort *******************************************/
int random_sort(const int *elements, int *sorted_elements, int size);
void random_sort_test();
/*********************************************************/

/* tests */
void tests() {
	square_matrix_test();
	random_generator_test();
	record_test();
	random_sort_test();
}


/* Main **************************************************/
void usage(char *name) {
	printf("Usage: %s [-s|-c|-d] nums\n", name);
	exit(1);
}

int main(int argc, char **argv) {
	int size = argc - 2, count;
	int unsorted[size], sorted[size];
	if (argc < 3) usage(argv[0]);
	if (strcmp(argv[1], "-s") &&
			strcmp(argv[1], "-c") &&
			strcmp(argv[1], "-d")) {
		usage(argv[0]);
	}
	for (int i = 0; i < size; i++) {
		if (!sscanf(argv[i + 2], "%d", &unsorted[i])) {
			usage(argv[0]);
		}
	}
	count = random_sort(unsorted, sorted, size);
	if (!strcmp(argv[1], "-s")) {
		for (int i = 0; i < size; i++) {
			printf("%d ", sorted[i]);
		}
		printf("\n");
	} else if (!strcmp(argv[1], "-c")) {
		printf("%d\n", count);
	} else {
		printf("%f\n", ((double) count / (double) size));
	}
	return 0;
}
/*********************************************************/


/* Square Matrix ******************************************/
struct square_matrix *square_matrix_new(int size) {
	struct square_matrix *mat;
	mat = malloc(sizeof *mat);
	if (!mat) return NULL;
	mat->size = size;
	mat->elements = calloc(size * size, sizeof(*(mat->elements)));
	if (!mat->elements) {
		free(mat);
		return NULL;
	}
	return mat;
}

void square_matrix_set(struct square_matrix *mat, int row,
		int col, unsigned char val) {
	(mat->elements)[IDX(row, col, mat->size)] = val;
}

unsigned char square_matrix_get(struct square_matrix *mat,
		int row, int col) {
	return (mat->elements)[IDX(row, col, mat->size)];
}

void square_matrix_free(struct square_matrix *mat) {
	free(mat->elements);
	free(mat);
}

void square_matrix_print(struct square_matrix *mat) {
	printf("\n");
	char *prfx = " ";
	for (int i = 0; i < mat->size; i++) {
		for (int j = 0; j < mat->size; j++) {
			printf("%s%d", prfx, square_matrix_get(mat, i, j));
		}
		printf("\n");
	}
}

void square_matrix_test() {
	struct square_matrix *mat;
	const int SIZE = 10;
	/* Creation Test */
	mat = square_matrix_new(SIZE);
	square_matrix_print(mat);

	/* Set Test */
	square_matrix_set(mat, 0, 0, EQ);
	square_matrix_set(mat, 1, 1, EQ);
	square_matrix_set(mat, 2, 2, EQ);
	square_matrix_set(mat, 3, 3, EQ);
	square_matrix_set(mat, 6, 2, GT);
	square_matrix_print(mat);

	/* Get Test */
	if (EQ != square_matrix_get(mat, 2, 2)) printf("Get Failed.\n");

	/* Free mat */
	square_matrix_free(mat);
}
/*********************************************************/


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


/* Record ************************************************/
struct record *record_new(int size) {
	struct record *rec;
	rec = malloc(sizeof *rec);
	if (!rec) return NULL;
	rec->mat = square_matrix_new(size);
	if (!rec->mat) {
		free(rec);
		return NULL;
	}
	rec->rg = random_generator_new(size * size);
	if (!rec->rg) {
		square_matrix_free(rec->mat);
		free(rec);
		return NULL;
	}
	for (int i = 0; i < size; i++) {
		square_matrix_set(rec->mat, i, i, EQ);
		random_generator_remove(rec->rg, IDX(i, i, size));
	}
	return rec;
}

int record_size(struct record *rec) {
	return rec->mat->size;
}

void record_mark(struct record *rec, int row, int col, int val) {
	if (square_matrix_get(rec->mat, row, col) != val) {
		square_matrix_set(rec->mat, row, col, val);
		random_generator_remove(rec->rg,
				IDX(row, col, record_size(rec)));
		for (int i = 0; i < record_size(rec); i++) {
			if (square_matrix_get(rec->mat, i, row) == val) {
				record_mark(rec, i, col, val);
			}
		}
		record_mark(rec, col, row, OPP(val));
	}
}


struct pair record_pair(struct record *rec) {
	struct pair res;
	int idx = random_generator_get(rec->rg);
	res.r = ROW(idx, record_size(rec));
	res.c = COL(idx, record_size(rec));
	return res;
}

int record_filled(struct record *rec) {
	return !random_generator_remaining(rec->rg);
}

void record_positions(struct record *rec, int *positions) {
	int idx;
	for (int i = 0; i < record_size(rec); i++) {
		idx = 0;
		for (int j = 0; j < record_size(rec); j++) {
			if (GT == square_matrix_get(rec->mat, i, j)) idx++;
		}
		positions[i] = idx;
	}
}

void record_free(struct record *rec) {
	square_matrix_free(rec->mat);
	// random_generator_free(rec->rg);
	free(rec);
}

void record_print(struct record *rec) {
	printf("{");
	square_matrix_print(rec->mat);
	random_generator_print(rec->rg);
	printf("}\n");
}

void record_test() {
	struct record *rec;
	const int SIZE = 10;
	int elements[] = {42, 82, 74, 75, 89, 54, 3, 4, 46, 37};
	int expected_positions[] = {3, 8, 6, 7, 9, 5, 0, 1, 4, 2 };
	int sorted_elements[] = {3, 4, 37, 42, 46, 54, 74, 75, 82, 89};
	int positions[SIZE];

	/* test new. */
	rec = record_new(SIZE);
	record_print(rec);

	/* test rand. */
	for (int i = 0; i < SIZE - 1; i++) {
		record_mark(rec, i, i + 1,
				(elements[i] < elements[i + 1] ? LT : GT));
	}
	record_print(rec);
	record_free(rec);

	/* test split coverage. */
	rec = record_new(SIZE);
	for (int i = 0; i < SIZE - 1; i++) {
		if (i != 4) record_mark(rec, i, i + 1, LT);
	}
	record_mark(rec, 4, 5, LT);
	record_print(rec);
	record_free(rec);

	/* test full coverage. */
	rec = record_new(SIZE);
	record_mark(rec, 6, 7, LT);
	record_mark(rec, 7, 9, LT);
	record_mark(rec, 9, 0, LT);
	record_mark(rec, 0, 8, LT);
	record_mark(rec, 8, 5, LT);
	record_mark(rec, 5, 2, LT);
	record_mark(rec, 2, 3, LT);
	record_mark(rec, 3, 1, LT);
	record_mark(rec, 1, 4, LT);
	record_print(rec);


	/* test positions. */
	record_positions(rec, positions);
	for (int i = 0; i < SIZE; i++) {
		if (expected_positions[i] != positions[i])
			printf("wrong position (expected actual): %d %d\n",
					expected_positions[i], positions[i]);
	}
	record_free(rec);
}
/*********************************************************/


/* Random Sort *******************************************/
int random_sort(const int *elements, int *sorted_elements, int size) {
	struct record *rec;
	struct pair randp;
	int comparisons = 0, positions[size];
	rec = record_new(size);
	while (!record_filled(rec)) {
		randp = record_pair(rec);
		record_mark(rec, randp.r, randp.c,
				(elements[randp.r] < elements[randp.c] ? LT : GT));
		comparisons++;
	}
	record_positions(rec, positions);
	for (int i = 0; i < size; i++) {
		sorted_elements[positions[i]] = elements[i];
	}
	record_free(rec);
	return comparisons;
}

void random_sort_test() {
	const int SIZE = 10;
	int elements[] = {42, 82, 74, 75, 89, 54, 3, 4, 46, 37};
	int sorted_elements[] = {3, 4, 37, 42, 46, 54, 74, 75, 82, 89};
	int result[SIZE];

	random_sort(elements, result, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d %d\n", result[i], sorted_elements[i]);
	}
}
/*********************************************************/
