#include <stdlib.h>
#include <stdio.h>
#include "point.h"

struct point *point_alloc() {
	struct point *newpoint;
	return malloc(sizeof *newpoint);
}

struct point *point_new(int x, int y, int z) {
	struct point *newpoint;
	newpoint = malloc(sizeof *newpoint);
	newpoint->x = x, newpoint->y = y, newpoint->z = z;
	return newpoint;
}

void point_free(struct point *point) {
	free(point);
}

void point_print(struct point *point) {
	printf("(%d, %d, %d)", point->x,
			point->y, point->z);
}
