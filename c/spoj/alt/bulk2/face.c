#include <stdio.h>
#include <stdlib.h>
#include "face.h"

struct face *face_alloc() {
	struct face *newface;
	return malloc(sizeof *newface);
}

struct face *face_new(int size, struct point *points) {
	struct face *newface;
	newface = malloc(sizeof *newface);
	newface->size = size;
	newface->points = points;
	return newface;
}

void face_free(struct face *face) {
	free(face->points);
	free(face);
}

void face_print(struct face *face) {
	char *prefx = "";
	printf("{size:%d,[", face->size);
	for (int i = 0; i < face->size; i++) {
		printf("%s", prefx);
		point_print(face->points + i);
		prefx = ",";
	}
	printf("]}");
}
