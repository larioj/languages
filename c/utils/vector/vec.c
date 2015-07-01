#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

void vec_print(struct vec *v) {
	char preffix = '[';
	for (int i = 0; i < v->size; i++) {
		printf("%c%d", preffix, v->element[i]);
		preffix = ',';
	}
	printf("]\n");
}

struct vec *vec_create(size_t size) {
	struct vec *v;
	v = (struct vec*) calloc((size + 1), sizeof(int));
	v->size = size;
	return v;
}

void vec_free(struct vec *v) {
	free(v);
}

struct vec *vec_concat(struct vec *lhs, struct vec *rhs) {
	size_t newsize = lhs->size + rhs->size;
	struct vec *v = vec_create(newsize);
	int i;
	for (i = 0; i < lhs->size; i++) {
		v->element[i] = lhs->element[i];
	}
	for (i = 0; i < rhs->size; i++) {
		v->element[i + lhs->size] = rhs->element[i];
	}
	return v;
}

struct vec *vec_push(struct vec *v, int item) {
	size_t newsize = v->size + 1;
	struct vec *newv = vec_create(newsize);
	for (int i = 0; i < v->size; i++) {
		newv->element[i] = v->element[i];
	}
	newv->element[v->size] = item;
	return newv;
}

struct vec *vec_copy(struct vec *v) {
	struct vec *newv = vec_create(v->size);
	for (int i = 0; i < newv->size; i++) {
		newv->element[i] = v->element[i];
	}
	return newv;
}

struct vec *vec_removeAtIndex(struct vec *v, int index) {
	struct vec *newv = vec_create(v->size - 1);
	for (int i = 0; i < newv->size; i++) {
		int oldindex = i;
		if (oldindex >= index) {
			oldindex++;
		}
		newv->element[i] = v->element[oldindex];
	}
	return newv;
}

struct vec *vec_removeFirstN(struct vec *v, int n) {
	size_t newsize = v->size - n;
	struct vec *newv = vec_create(newsize);
	for (int i = 0; i < newv->size; i++) {
		newv->element[i] = v->element[i +n];
	}
	return newv;
}
