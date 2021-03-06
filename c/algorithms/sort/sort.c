#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct pair {
	int r, c;
};

struct matrix {
	int *items;
};

void matrixAlloc();
void matrixSet(int r, int c, int val);
int matrixGet(int r, int c);

void printRecord();
void fillDiagonal();
void compare(int r, int c);
void mark(int r, int c, int val);
int opposite(int val) { return (val == 1? 9 : 1);}
void startRandom();
struct pair getRandom();
void removeRandom(int r, int c);
void printRandom();
void printSorted();
void getSorted();

void setLength();

int length;

struct matrix record;

// int record[10][10] = {0};
int elements[] = {42, 82, 74, 75, 89, 54, 3, 4, 46, 37};
int *sorted;
// int sorted[10];
int *rindeces; //[length * length];
int rcount; //  = length * length;
int comparisons = 0;

int main(int argc, char **argv) {
	struct pair rpair;
	startRandom();
	fillDiagonal();
	while (rcount) {
		rpair = getRandom();
		compare(rpair.r, rpair.c);
	}
	printRecord();
	printf("comparisons: %d\n", comparisons);
	getSorted();
	printSorted();
	return 0;
}

void printRecord() {
	for (int i = 0; i < length; i++) {
		printf("\n");
		for (int j = 0; j < length; j++)
			printf("%d ", matrixGet(i, j));
	}
	printf("\n");
}

void fillDiagonal() {
	for (int i = 0; i < length; i++) {
		matrixSet(i, i, 7);
		// record[i][i] = 7;
		removeRandom(i, i);
	}
}

void compare(int r, int c) {
	comparisons++;
	mark(r, c, (elements[r] < elements[c] ? 1 : 9));
}

void mark(int r, int c, int val) {
	if (/*record[r][c]*/ matrixGet(r, c) != val) {
		matrixSet(r, c, val);
		// record[r][c] = val;
		removeRandom(r, c);
		for (int i = 0; i < length; i++) {
			if (/*record[i][r]*/ matrixGet(i, r)  == val) {
				mark(i, c, val);
			}
		}
		mark(c, r, opposite(val));
	}
}

void startRandom() {
	for (int i = 0; i < length * length; i++) {
		rindeces[i] = i;
	}
	time_t t; srand((unsigned) time(&t));
}

void removeRandom(int r, int c) {
	int idx = length * r + c;
	int i;
	for (i = 0; i < rcount; i++) {
		if (idx == rindeces[i])
			break;
	}
	if (i < rcount) {
		rindeces[i] = rindeces[--rcount];
		rindeces[rcount] = idx;
	}
}

void printRandom() {
	char *prfx = "";
	for (int i = 0; i < rcount; i++) {
		printf("%s%d", prfx, rindeces[i]);
		prfx = ",";
	}
	printf("\n");
}

struct pair getRandom() {
	struct pair rc;
	int idx = rindeces[rand() % rcount];
	rc.r = idx / length;
	rc.c = idx % length;
	return rc;
}

void printSorted() {
	char *prfx = "";
	for (int i = 0; i < length; i++) {
		printf("%s%d", prfx, sorted[i]);
		prfx = " ";
	}
	printf("\n");
}

void getSorted() {
	int idx;
	for (int i = 0; i < length; i++) {
		idx = 0; 
		for (int j = 0; j < length; j++) {
			if (/*record[i][j]*/ matrixGet(i, j) == 9)
				idx++;
		}
		sorted[idx] = elements[i];
	}
}

void setLength(int len) {
	length = len;
}

