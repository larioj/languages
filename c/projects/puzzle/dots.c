#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../utils/combinations/comb.h"
#include "../../utils/vector/vec.h"

// Not possible.
static void check(struct vec *seq);
static void printgrid(int n, int m, int *grid);
static bool complete(int *grid, struct vec *seq);
static void fillbetween(int src, int dst, int * grid);

int main() {
	perm(9, 5, &check);
}

static void check(struct vec *seq) {
	int grid[9];
	memset(grid, 0, sizeof(grid));
	for (int i = 0; i < seq->size; i++) {
		grid[seq->element[i]] = i + 1;
	}
	if (complete(grid, seq)) {
		printgrid(3, 3, grid);
	}
}

static void printgrid(int n, int m, int *grid) {
	for (int i = 0; i < n; i++) {
		char pre = '[';
		for (int j = 0; j < m; j++) {
			printf("%c%d", pre, grid[(3*i)+j]);
			pre = ',';
		}
		printf("]\n");
	}
	printf("\n");
}

static bool complete(int *grid, struct vec *seq) {
	int one, two;
	for (int i = 0; i < seq->size - 1; i++) {
		one = seq->element[i];
		two = seq->element[i + 1];
		fillbetween(one, two, grid);
	}
	for (int i = 0; i < 9; i++) {
		if (grid[i] == 0) {
			return false;
		}
	}
	return true;
}

static void fillbetween(int src, int dst, int * grid) {
	int oner, onec, twor, twoc;
	oner = src / 3;
	onec = src % 3;
	twor = dst / 3;
	twoc = dst % 3;
	if (oner == twor) {
		int diff = (twoc > onec ? twoc - onec : onec - twoc);
		if (diff == 2) {
			int threec = 1, threer = oner;
			grid[(3 *threer) + threec] = -1;
		}
	}
	if (onec == twoc) {
		int diff = (twor > oner ? twor - oner : oner - twor);
		if (diff == 2) {
			int threer = 1, threec = onec;
			grid[(3*threer) + threec] = -1;
		}
	}
	if (src == 0 && dst == 8) {
		grid[4] = -1;
	}
	if (src == 8 && dst == 0) {
		grid[4] = -1;
	}
	if (src == 6 && dst == 2) {
		grid[4] = -1;
	}
	if (src == 2 && dst == 6) {
		grid[4] = -1;
	}
}
