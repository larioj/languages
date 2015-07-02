#ifndef intvec_VEC_H_
#define intvec_VEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Generic Definitions */
#define T int
#define C vec
#define PRT "%d"
#define _INNER( type, classname, methodname ) \
     type ## classname ## _ ## methodname
#define _OUTER( type, classname, methodname ) \
     _INNER(type, classname, methodname)
#define _(name) \
	_OUTER(T, C, name)
#define INITIALSIZE 16

typedef struct _(vec) {
	size_t size;
	size_t maxsize;
	T *item;
} *_(vec);

/* Constructor and destructor. */
_(vec) _(allocate)();
void _(free)(_(vec) vec);

/* Setters. */
bool _(push_front)(_(vec) vec, T item);
bool _(push_back)(_(vec) vec, T item);
bool _(insert)(_(vec) vec, T item, int index);

/* Getters */
bool _(pop_front)(_(vec) vec, T *item);
bool _(pop_back)(_(vec) vec, T *item);
bool _(remove)(_(vec) vec, T *item, int index);

/* accessors */
bool _(front)(_(vec) vec, T *item);
bool _(back)(_(vec) vec, T *item);
bool _(peek)(_(vec) vec, T *item, int index);

/* Status. */
int _(size)(_(vec) vec);
bool _(empty)(_(vec) vec);
void _(print)(_(vec) vec);

/* Private helpers. */
bool _(grow)(_(vec) vec);
bool _(shrink)(_(vec) vec);

/* Constructor and destructor. */
_(vec) _(allocate)() {
	_(vec) vec;
	vec = (_(vec)) malloc(sizeof(*vec));
	if (!vec) {
		return NULL;
	}
	vec->item = (T *) malloc(sizeof(T) * INITIALSIZE);
	if (!vec->item) {
		free(vec);
		return NULL;
	}
	vec->size = 0;
	vec->maxsize = INITIALSIZE;
	return vec;
}

void _(free)(_(vec) vec) {
	free(vec->item);
	free(vec);
}

/* Setters. */
bool _(push_front)(_(vec) vec, T item) {
	return _(insert)(vec, item, 0);
}

bool _(push_back)(_(vec) vec, T item) {
	if (vec->size == vec->maxsize && !_(grow)(vec)) {
		return false;
	}
	vec->item[vec->size] = item;
	vec->size++;
	return true;
}

bool _(insert)(_(vec) vec, T item, int index) {
	if (index >= vec->size) {
		return _(push_back)(vec, item);
	}
	if (0 > index || (vec->size == vec->maxsize && !_(grow)(vec))) {
		return false;
	}
	for (int i = vec->size; i > index; i--) {
		vec->item[i] = vec->item[i - 1];
	}
	vec->item[index] = item;
	vec->size++;
	return true;
}

/* Getters */
bool _(pop_front)(_(vec) vec, T *item) {
	return _(remove)(vec, item, 0);
}

bool _(pop_back)(_(vec) vec, T *item) {
	if (vec->size < vec->maxsize/4 && vec->maxsize > INITIALSIZE
			&& !_(shrink)(vec)) {
		return false;
	}
	*item = vec->item[vec->size - 1];
	vec->size--;
	return true;
}

bool _(remove)(_(vec) vec, T *item, int index) {
	if (vec->size < vec->maxsize/4 && vec->maxsize > INITIALSIZE
			&& !_(shrink)(vec)) {
		return false;
	}
	*item = vec->item[index];
	for (int i = index; i < vec->size - 1; i++) {
		vec->item[i] = vec->item[i + 1];
	}
	vec->size--;
	return true;
}

/* accessors */
bool _(front)(_(vec) vec, T *item) {
	return _(peek)(vec, item, 0);
}

bool _(back)(_(vec) vec, T *item) {
	return _(peek)(vec, item, vec->size - 1);
}

bool _(peek)(_(vec) vec, T *item, int index) {
	if (index >= vec->size || 0 > index) {
		return false;
	}
	*item = vec->item[index];
	return true;
}

/* Status. */
int _(size)(_(vec) vec) {
	return vec->size;
}

bool _(empty)(_(vec) vec) {
	return vec->size == 0;
}

void _(print)(_(vec) vec) {
	char *prefix = "";
	printf("[");
	for (int i = 0; i < vec->size; i++) {
		printf("%s"PRT, prefix, vec->item[i]);
		prefix = ",";
	}
	printf("](%lu, %lu)\n", vec->size, vec->maxsize);
}

/* Private helpers. */
bool _(grow)(_(vec) vec) {
	T *newitem;
	newitem = (T *) realloc(vec->item, 2 * sizeof(T) * vec->maxsize);
	if (!newitem) {
		return false;
	}
	vec->item = newitem;
	vec->maxsize *= 2;
	return true;
}

bool _(shrink)(_(vec) vec) {
	T *newitem;
	newitem = (T *) realloc(vec->item, sizeof(T) * (vec->maxsize/2));
	if (!newitem) {
		return false;
	}
	vec->item = newitem;
	vec->maxsize /= 2;
	return true;
}

#undef INITIALSIZE
#undef _
#undef _OUTER
#undef _INNER
#undef PRT
#undef C
#undef T

#endif
