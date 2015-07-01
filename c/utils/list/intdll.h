#ifndef intdll_LIST_H_
#define intdll_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T int
#define C dll
#define PRT "%d"
#define _INNER( type, classname, methodname ) \
     type ## classname ## _ ## methodname
#define _OUTER( type, classname, methodname ) \
     _INNER(type, classname, methodname)
#define _(name) \
	_OUTER(T, C, name)

/* struct definitons. */
struct _(node) {
	T item;
	struct _(node) *next;
	struct _(node) *prev;
};

struct _(head) {
	size_t size;
	struct _(node) *head;
	struct _(node) *tail;
};

typedef struct _(head) *_(list);

/* Constructor and destructor. */
_(list) _(allocate)();
void _(free)(_(list) list);

/* Setters. */
bool _(push_front)(_(list) list, T item);
bool _(push_back)(_(list) list, T item);
bool _(insert)(_(list) list, T item, int index);

/* Getters */
bool _(pop_front)(_(list) list, T *item);
bool _(pop_back)(_(list) list, T *item);
bool _(remove)(_(list) list, T *item, int index);

/* accessors */
bool _(front)(_(list) list, T *item);
bool _(back)(_(list) list, T *item);
bool _(peek)(_(list) list, T *item, int index);

/* Status. */
int _(size)(_(list) list);
bool _(empty)(_(list) list);
void _(print)(_(list) list);

/* helper methods. */
static struct _(node) *_(node_allocate)(T item, struct _(node) *next,
		struct _(node) *prev);
static void _(node_free)(struct _(node) *node);

/* Constructor and destructor. */
_(list) _(allocate)() {
	_(list) list = (_(list)) malloc(sizeof(*list));
	if (!list) {
		return NULL;
	}
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void _(free)(_(list) list) {
	while (!_(empty)(list)) {
		T phony;
		_(pop_back(list, &phony));
	}
	free(list);
}

/* Setters. */
bool _(push_front)(_(list) list, T item) {
	struct _(node) *newnode;
	if (0 == list->size) {
		newnode = _(node_allocate)(item, NULL, NULL);
		if (!newnode) {
			return false;
		}
		list->head = list->tail = newnode;
	} else {
		newnode = _(node_allocate)(item, list->head, NULL);
		if (!newnode) {
			return false;
		}
		list->head->prev = newnode;
		list->head = newnode;
	}
	list->size++;
	return true;
}

bool _(push_back)(_(list) list, T item) {
	if (0 == list->size) {
		return (_(push_front(list, item)));
	} else {
		struct _(node) *newnode;
		newnode = _(node_allocate)(item, NULL, list->tail);
		if (!newnode) {
			return false;
		}
		list->tail->next = newnode;
		list->tail = newnode;
		list->size++;
		return true;
	}
}

bool _(insert)(_(list) list, T item, int index) {
	if (index <= 0) {
		return (_(push_front) (list, item));
	} else if (index >= (int) list->size - 1) {
		return (_(push_back) (list, item));
	} else {
		struct _(node) *newnode, *p;
		p = list->head;
		for (int i = 0; i < index; i++) {
			p = p->next;
		}
		newnode = _(node_allocate)(item, p, p->prev);
		if (!newnode) {
			return false;
		}
		p->prev->next = newnode;
		p->prev = newnode;
		list->size++;
		return true;
	}
}

/* Getters */
bool _(pop_front)(_(list) list, T *item) {
	if (0 == list->size) {
		return false;
	}
	struct _(node) *oldnode;
	oldnode = list->head;
	if (1 == list->size) {
		list->head = list->tail = NULL;
	} else {
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	list->size--;
	*item = oldnode->item;
	_(node_free)(oldnode);
	return true;
}

bool _(pop_back)(_(list) list, T *item) {
	if (2 > list->size) {
		return _(pop_front(list, item));
	}
	struct _(node) *oldnode;
	oldnode = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	*item = oldnode->item;
	_(node_free)(oldnode);
	list->size--;
	return true;
}

bool _(remove)(_(list) list, T *item, int index) {
	if (2 > list->size || 0 >= index) {
		return _(pop_front(list, item));
	}
	if ((int) list->size - 1 <= index) {
		return _(pop_back(list, item));
	}
	struct _(node) *oldnode;
	oldnode = list->head;
	for (int i = 0; i < index; i++) {
		oldnode = oldnode->next;
	}
	oldnode->prev->next = oldnode->next;
	oldnode->next->prev = oldnode->prev;
	*item = oldnode->item;
	_(node_free)(oldnode);
	return true;
}


/* accessors */
bool _(front)(_(list) list, T *item) {
	if (list->size) {
		*item = list->head->item;
		return true;
	}
	return false;
}

bool _(back)(_(list) list, T *item) {
	if (list->size) {
		*item = list->tail->item;
		return true;
	}
	return false;
}

bool _(peek)(_(list) list, T *item, int index) {
	if (list->size) {
		if (0 >= index) {
			return _(front)(list, item);
		}
		if ((int) list->size - 1 <= index) {
			return _(back)(list, item);
		}
		struct _(node) *node;
		node = list->head;
		for (int i = 0; i < index; i++) {
			node = node->next;
		}
		*item = node->item;
	}
	return false;
}

/* Status. */
int _(size)(_(list) list) {
	return list->size;
}

bool _(empty)(_(list) list) {
	return (!list->size);
}

void _(print)(_(list) list) {
	/* [node] <-> [node] */
	printf("[");
	char *prefix = "";
	struct _(node) *p;
	p = list->head;
	while (p) {
		printf("%s"PRT, prefix, p->item);
		p = p->next;
		prefix = ",";
	}
	printf("](%d)\n", (int) list->size);
}

/* helper methods. */
static struct _(node) *_(node_allocate)(T item, struct _(node) *next,
		struct _(node) *prev) {
	struct _(node) *newnode;
	newnode = (struct _(node) *) malloc(sizeof *newnode);
	if (!newnode) {
		return NULL;
	}
	newnode->item = item;
	newnode->next = next;
	newnode->prev = prev;
	return newnode;
}

static void _(node_free)(struct _(node) *node) {
	free(node);
}

#undef _
#undef _OUTER
#undef _INNER
#undef PRT
#undef C
#undef T

#endif
