#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLESIZE 16

#define X 1
#define Y 2
#define Z 4
#define POS 1
#define NEG -1

struct point {
	int x, y, z;
};

struct plane {
	int type, x, y, z;
};

struct ppmap {
	struct plane *plane;
	struct point *point;
};

struct table {
	int size;
	int maxsize;
	void **records;
	int (*comparator)(void *lhs, void *rhs);
};

struct shape {
	int value;
	struct table *points, *planes, *ppmaps;
};


/* Table operations. */
struct table *table_new(int (*comparator)(void *lhs, void *rhs));
void table_delete(struct table *table, void (*record_free)(void *record));
bool table_add(struct table *table, void *record);
bool table_find(struct table *table, void *record, int *location);
bool table_remove(struct table *table, void **record);
void *table_get(struct table *table, int location);

/* Record comparators. */
int point_comparator(void *lhs, void *rhs);
int plane_comparator(void *lhs, void *rhs);
int shape_comparator(void *lhs, void *rhs);
int ppmap_comparator(void *lhs, void *rhs);

/* Record destructors. */
void point_free(void *point);
void plane_free(void *plane);
void shape_free(void *shape);
void ppmap_free(void *ppmap);

/* Record constructors. */
struct point *point_alloc(int x, int y, int z);
struct plane *plane_alloc();
struct shape *shape_alloc();
struct ppmap *ppmap_alloc(struct plane *plane, struct point *point);

/* Helper methods. */
void resolve_shapes(struct table *shapes);
void resolve_planes(struct table *shapes);
void coallece_planes(struct table *shapes);

int main() {
	struct table *shapes;
	int loops, planecount, pointcount, x, y, z;

	/* Get number of bulks to process. */
	scanf("%d", &loops);
	while(loops--) {

		/* allocate the shapes table and create the
		 * initial shape. */
		shapes = table_new(shape_comparator);
		struct shape *newshape = shape_alloc();
		table_add(shapes, newshape);

		/* Get the plane count. */
		scanf("%d", &planecount);
		while(planecount--) {

			/* Create a new plane and add it to the plane table inside
			 * the shape. */
			struct plane *newplane = plane_alloc();
			table_add(newshape->planes, newplane);

			/* Get the point count. */
			scanf("%d", &pointcount);
			while(pointcount--) {

				/* Add point to the shape. */
				scanf("%d %d %d", &x, &y, &z);
				struct point *newpoint = point_alloc(x, y, z);
				if (!table_add(newshape->points, newpoint)) {
					int loc;
					table_find(newshape->points, newpoint, &loc);
					free(newpoint);
					newpoint = table_get(newshape->points, loc);
				}

				/* Add mapping between plane and point. */
				table_add(newshape->ppmaps, ppmap_alloc(newplane, newpoint));
			}

			/* Add the plane to the planes table inside shape. */
			table_add(newshape->planes, newplane);
		}
		resolve_planes(shapes);
		resolve_shapes(shapes);
		coallece_planes(shapes);
	}
}
