#ifndef point_TABLE_H
#define point_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point {
	int x, y, z;
};

/* Generic Definitions */
#define T struct point
#define _(NAME) pointtb_ ## NAME
#define INITIALSIZE 16

typedef struct _(table) {
	size_t size;
	size_t maxsize;
	T *item;
} *_(table);

/* Constructor and destructor. */
_(table) _(allocate)();
void _(free)(_(table) table);

/* Setters. */
bool _(push_front)(_(table) table, T item);
bool _(push_back)(_(table) table, T item);
bool _(insert)(_(table) table, T item, int index);

/* Getters */
bool _(pop_front)(_(table) table, T *item);
bool _(pop_back)(_(table) table, T *item);
bool _(remove)(_(table) table, T *item, int index);

/* accessors */
bool _(front)(_(table) table, T *item);
bool _(back)(_(table) table, T *item);
bool _(peek)(_(table) table, T *item, int index);

/* Status. */
int _(size)(_(table) table);
bool _(empty)(_(table) table);
void _(print)(_(table) table);

/* Private helpers. */
bool _(grow)(_(table) table);
bool _(shrink)(_(table) table);

/* Constructor and destructor. */
_(table) _(allocate)() {
	_(table) table;
	table = (_(table)) malloc(sizeof(*table));
	if (!table) {
		return NULL;
	}
	table->item = (T *) malloc(sizeof(T) * INITIALSIZE);
	if (!table->item) {
		free(table);
		return NULL;
	}
	table->size = 0;
	table->maxsize = INITIALSIZE;
	return table;
}

void _(free)(_(table) table) {
	free(table->item);
	free(table);
}

/* Setters. */
bool _(push_front)(_(table) table, T item) {
	return _(insert)(table, item, 0);
}

bool _(push_back)(_(table) table, T item) {
	if (table->size == table->maxsize && !_(grow)(table)) {
		return false;
	}
	table->item[table->size] = item;
	table->size++;
	return true;
}

bool _(insert)(_(table) table, T item, int index) {
	if (index >= table->size) {
		return _(push_back)(table, item);
	}
	if (0 > index || (table->size == table->maxsize && !_(grow)(table))) {
		return false;
	}
	for (int i = table->size; i > index; i--) {
		table->item[i] = table->item[i - 1];
	}
	table->item[index] = item;
	table->size++;
	return true;
}

/* Getters */
bool _(pop_front)(_(table) table, T *item) {
	return _(remove)(table, item, 0);
}

bool _(pop_back)(_(table) table, T *item) {
	if (table->size < table->maxsize/4 && table->maxsize > INITIALSIZE
			&& !_(shrink)(table)) {
		return false;
	}
	*item = table->item[table->size - 1];
	table->size--;
	return true;
}

bool _(remove)(_(table) table, T *item, int index) {
	if (table->size < table->maxsize/4 && table->maxsize > INITIALSIZE
			&& !_(shrink)(table)) {
		return false;
	}
	*item = table->item[index];
	for (int i = index; i < table->size - 1; i++) {
		table->item[i] = table->item[i + 1];
	}
	table->size--;
	return true;
}

/* accessors */
bool _(front)(_(table) table, T *item) {
	return _(peek)(table, item, 0);
}

bool _(back)(_(table) table, T *item) {
	return _(peek)(table, item, table->size - 1);
}

bool _(peek)(_(table) table, T *item, int index) {
	if (index >= table->size || 0 > index) {
		return false;
	}
	*item = table->item[index];
	return true;
}

/* Status. */
int _(size)(_(table) table) {
	return table->size;
}

bool _(empty)(_(table) table) {
	return table->size == 0;
}

/* Private helpers. */
bool _(grow)(_(table) table) {
	T *newitem;
	newitem = (T *) realloc(table->item, 2 * sizeof(T) * table->maxsize);
	if (!newitem) {
		return false;
	}
	table->item = newitem;
	table->maxsize *= 2;
	return true;
}

bool _(shrink)(_(table) table) {
	T *newitem;
	newitem = (T *) realloc(table->item, sizeof(T) * (table->maxsize/2));
	if (!newitem) {
		return false;
	}
	table->item = newitem;
	table->maxsize /= 2;
	return true;
}

#undef INITIALSIZE
#undef _
#undef T

#endif
