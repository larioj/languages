#ifndef intheap_HEAP_H_
#define intheap_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Generic Definitions */
#define T int
#define C heap
#define PRT "%d"
#define _INNER( type, classname, methodname ) \
     type ## classname ## _ ## methodname
#define _OUTER( type, classname, methodname ) \
     _INNER(type, classname, methodname)
#define _(name) \
	_OUTER(T, C, name)
#define INITIALSIZE 16

typedef struct _(heap) {
	size_t size;
	size_t maxsize;
	T *item;
} *_(heap);

/* Constructor and destructor. */
_(heap) _(allocate)();
void _(free)(_(heap) heap);

/* Comparator */
int _(comparator) (T lhs, T rhs);

/* Setters. */
bool _(insert)(_(heap) heap, T item);

/* Getters */
bool _(remove)(_(heap) heap, T *item);

/* accessors */
bool _(peek)(_(heap) heap, T *item);

/* Status. */
int _(size)(_(heap) heap);
bool _(empty)(_(heap) heap);
void _(print)(_(heap) heap);

/* Private helpers. */
bool _(grow)(_(heap) heap);
bool _(shrink)(_(heap) heap);
void _(percolateup)(_(heap) heap, int index);
void _(percolatedown)(_(heap) heap, int index);
int _(parent)(int index);
int _(lchild)(int index);
int _(rchild)(int index);
bool _(haschild)(_(heap) heap, int index);
bool _(biggerthansmallestchild)(_(heap) heap, T item, int index);
int _(schild)(_(heap) heap, int index);

/* Constructor and destructor. */
_(heap) _(allocate)() {
	_(heap) heap;
	heap = (_(heap)) malloc(sizeof(*heap));
	if (!heap) {
		return NULL;
	}
	heap->item = (T *) malloc(sizeof(T) * INITIALSIZE);
	if (!heap->item) {
		free(heap);
		return NULL;
	}
	heap->size = 0;
	heap->maxsize = INITIALSIZE;
	return heap;
}

void _(free)(_(heap) heap) {
	free(heap->item);
	free(heap);
}

/* Setters. */
bool _(insert)(_(heap) heap, T item) {
	if (heap->size == heap->maxsize && !_(grow)(heap)) {
		return false;
	}
	heap->item[heap->size] = item;
	heap->size++;
	_(percolateup)(heap, heap->size - 1);
	return true;
}

/* Getters */
bool _(remove)(_(heap) heap, T *item) {
	if (0 == heap->size || (heap->size < heap->maxsize/4 && heap->maxsize > INITIALSIZE
			&& !_(shrink)(heap))) {
		return false;
	}
	*item = heap->item[0];
	heap->item[0] = heap->item[heap->size - 1];
	heap->size--;
	_(percolatedown)(heap, 0);
	return true;
}

/* accessors */
bool _(peek)(_(heap) heap, T *item) {
	if (0 == heap->size) {
		return false;
	}
	*item = heap->item[0];
	return true;
}

/* Status. */
int _(size)(_(heap) heap) {
	return heap->size;
}

bool _(empty)(_(heap) heap) {
	return 0 == heap->size;
}

void _(print)(_(heap) heap) {
	char *prefix = "";
	printf("[");
	for (int i = 0; i < heap->size; i++) {
		printf("%s"PRT, prefix, heap->item[i]);
		prefix = ",";
	}
	printf("](%lu, %lu)\n", heap->size, heap->maxsize);
}

/* Private helpers. */
bool _(grow)(_(heap) heap) {
	T *newitem;
	newitem = (T *) realloc(heap->item, 2 * sizeof(T) * heap->maxsize);
	if (!newitem) {
		return false;
	}
	heap->item = newitem;
	heap->maxsize *= 2;
	return true;
}

bool _(shrink)(_(heap) heap) {
	T *newitem;
	newitem = (T *) realloc(heap->item, sizeof(T) * (heap->maxsize/2));
	if (!newitem) {
		return false;
	}
	heap->item = newitem;
	heap->maxsize /= 2;
	return true;
}

void _(percolateup)(_(heap) heap, int index) {
	if (0 == index) { return; }
	T item = heap->item[index];
	int pindex = _(parent)(index);
	while (0 < index &&
			0 > _(comparator)(item, heap->item[pindex])) {
		heap->item[index] = heap->item[pindex];
		index = pindex;
		pindex = _(parent)(index);
	}
	heap->item[index] = item;
}

void _(percolatedown)(_(heap) heap, int index) {
	int sindex;
	T item = heap->item[index];
	while (_(haschild)(heap, index) &&
			_(biggerthansmallestchild)(heap, item, index)) {
		sindex = _(schild)(heap, index);
		heap->item[index] = heap->item[sindex];
		index = sindex;
	}
	heap->item[index] = item;
}

int _(parent)(int index) {
	if (0 == index) {
		return 0;
	}
	return (index - 1) / 2;
}
int _(lchild)(int index) {
	return 2 * index + 1;
}

int _(rchild)(int index) {
	return 2 * index + 2;
}

bool _(haschild)(_(heap) heap, int index) {
	int rindex, lindex;
	rindex = _(rchild)(index);
	lindex = _(lchild)(index);
	return (lindex < heap->size || rindex < heap->size);
}

bool _(biggerthansmallestchild)(_(heap) heap, T item, int index) {
	int sindex = _(schild)(heap, index);
	return 0 <= _(comparator)(item, heap->item[sindex]);
}

int _(schild)(_(heap) heap, int index) {
	int rindex, lindex;
	rindex = _(rchild)(index);
	lindex = _(lchild)(index);
	if (rindex < heap->size && lindex < heap->size) {
		if (0 > _(comparator)(heap->item[rindex], heap->item[lindex])) {
			return rindex;
		}
		return lindex;
	} else if (rindex < heap->size) {
		return rindex;
	} else if (lindex < heap->size) {
		return lindex;
	} else {
		return index;
	}
}


#undef INITIALSIZE
#undef _
#undef _OUTER
#undef _INNER
#undef PRT
#undef C
#undef T

#endif
