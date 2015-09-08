struct point {
	int x, y, z;
};

struct point *point_alloc();
struct point *point_new(int x, int y, int z);
void point_free(struct point *point);
void point_print(struct point *point);
