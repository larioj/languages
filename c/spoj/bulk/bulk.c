#include <stdio.h>
#include <stdlib.h>

struct point {
  int x, y, z;
};

int pointCmp(struct point* l, struct point *r) {
  if (l->x == r->x && l->y == r->y
      && l->z == r->z) return 0;
}

int main(int argc, char **argv) {
	return 0;
}
