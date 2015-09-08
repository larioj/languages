#include "face.h"

struct shape {
	int size;
	struct face *faces;
};

struct shape *shape_alloc();
struct shape *shape_new(int size, struct face *faces);
void shape_free(struct shape *shape);
void shape_print(struct shape *shape);
