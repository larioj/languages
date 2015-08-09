#include "point.h"

struct face {
	int size;
	struct point *points;
};

struct face *face_alloc();
struct face *face_new(int size, struct point *points);
void face_free(struct face *face);
void face_print(struct face *face);
void face_add(struct face *face, struct point *point);
