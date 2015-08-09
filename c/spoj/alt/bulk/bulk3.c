#include <stdio.h>
#include <stdlib.h>

struct point {
	int x, y, z;
};

struct face {
	int pointcount;
	struct point *points;
};

struct bulk {
	int shapecount;
	struct shape *shapes;
};

struct shape {
	int facecount;
	struct face *faces;
};

struct bulk *bulkinit();

void fillbulk(struct bulk *bulk);
void fillshape(struct shape *shape);
void fillface(struct face *face);
void fillpoint(struct point *point);

void freebulk(struct bulk *bulk);
void freeshape(struct shape *shape);
void freeface(struct face *face);

void printbulk(struct bulk *bulk);
void printshape(struct shape *shape);
void printface(struct face *face);
void printpoint(struct point *point);

int main(int argc, char **argv) {
	int bulkcount = 0;
	scanf("%d", &bulkcount);
	while(bulkcount--) {
		struct bulk *bulk = bulkinit();
		fillbulk(bulk);

		printbulk(bulk);
		freebulk(bulk);
	}
	return 0;
}

/* fills the bulk with input from stdin. */
void fillbulk(struct bulk *bulk) {
	fillshape(bulk->shapes);
}


/* creates a bulk with 1 shape. */
struct bulk *bulkinit() {
	struct bulk *newbulk = malloc(sizeof *newbulk);
	newbulk->shapecount = 1;
	newbulk->shapes = malloc(
			newbulk->shapecount *
			sizeof *(newbulk->shapes));
	return newbulk;
}

/* fills in a shape with input from stdin. */
void fillshape(struct shape *shape) {
	/* get face count */
	scanf("%d", &(shape->facecount));

	/* allocate space for the faces. */
	shape->faces = malloc(
			shape->facecount *
			sizeof *(shape->faces));

	/* fills the faces. */
	for (int i = 0; i < shape->facecount; i++) {
		fillface(shape->faces + i);
	}
}

void fillface(struct face *face) {
	/* get point count */
	scanf("%d", &(face->pointcount));

	/* allocate space for the points. */
	face->points = malloc(
			face->pointcount *
			sizeof *(face->points));

	/* fill in the points */
	for (int i = 0; i < face->pointcount; i++) {
		fillpoint(face->points + i);
	}
}

void fillpoint(struct point *point) {
	scanf("%d%d%d",
			&(point->x),
			&(point->y),
			&(point->z));
}

void freebulk(struct bulk* bulk) {
	for(int i = 0; i < bulk->shapecount; i++) {
		freeshape(bulk->shapes + i);
	}
	free(bulk->shapes);
	free(bulk);
}

void freeshape(struct shape *shape) {
	for (int i = 0; i < shape->facecount; i++) {
		freeface(shape->faces + i);
	}
	free(shape->faces);
}

void freeface(struct face *face) {
	free(face->points);
}

void printbulk(struct bulk *bulk) {
	printf("{\n");
	printf("shapecount: %d\n", bulk->shapecount);
	printf("\t[\n");
	for (int i = 0; i < bulk->shapecount; i++) {
		printshape(bulk->shapes + i);
	}
	printf("\t]\n");
	printf("}\n");
}

void printshape(struct shape *shape) {
	printf("\t{\n");
	printf("\tfacecount: %d\n", shape->facecount);
	printf("\t\t[\n");
	for (int i = 0; i < shape->facecount; i++) {
		printface(shape->faces + i);
	}
	printf("\t\t]\n");
	printf("\t}\n");
}

void printface(struct face *face) {
	printf("\t\t{\n");
	printf("\t\tfacecount: %d\n", face->pointcount);
	printf("\t\t\t[\n");
	for (int i = 0; i < face->pointcount; i++) {
		printpoint(face->points + i);
	}
	printf("\t\t\t]\n");
	printf("\t\t}\n");

}

void printpoint(struct point *point) {
	printf("\t\t\t%d %d %d\n",
			point->x,
			point->y,
			point->z);
}
