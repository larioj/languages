#include <stdbool.h>
#include <stdlib.h>

#define X 1
#define Y 2
#define Z 4

#define POS 1
#define NEG -1

#define pt(NAME) pointtb_ ## NAME
#define pl(NAME) planetb_ ## NAME
#define sh(NAME) shapetb_ ## NAME
#define ppm(NAME) ppmaptb_ ## NAME

#include "point_table.c"
#include "shape_table.c"
#include "plane_table.c"
#include "ppmap.c"

pt(table) points;
pl(table) planes;
sh(table) shapes;
ppm(table) ppmaps;

int main() {
	/* Allocate all our tables. */
	points = pt(allocate)();
	planes = pl(allocate)();
	shapes = sh(allocate)();
	ppmaps = ppm(allocate)();
}
