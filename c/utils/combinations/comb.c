#include <stdlib.h>
#include "comb.h"
#include "vec.h"

static void comb_priv(struct vec *sol,
		struct vec *chs, size_t count, void (*fun)(struct vec *));

static void perm_priv(struct vec *sol,
		struct vec *chs, size_t count, void (*fun)(struct vec *));


void comb(int elements, int choices, void (*fun)(struct vec *)) {
	struct vec *s, *c;
	c = vec_create(elements);
	s = vec_create(0);
	for (int i = 0; i < c->size; i++) {
		c->element[i] = i;
	}
	comb_priv(s, c, choices, fun);
	vec_free(s);
	vec_free(c);
}

void perm(int elements, int choices, void (*fun)(struct vec *)) {
	struct vec *s, *c;
	c = vec_create(elements);
	s = vec_create(0);
	for (int i = 0; i < c->size; i++) {
		c->element[i] = i;
	}
	perm_priv(s, c, choices, fun);
	vec_free(s);
	vec_free(c);
}

static void comb_priv(struct vec *sol,
		struct vec *chs, size_t count, void (*fun)(struct vec *)) {
	if (count == 0) {
		fun(sol);
	} else {
		struct vec *newsol, *newchs;
		for (int i = 0; i < chs->size; i++) {
			newsol = vec_push(sol, chs->element[i]);
			newchs = vec_removeFirstN(chs, i+1);
			comb_priv(newsol, newchs, count - 1, fun);
			vec_free(newchs);
			vec_free(newsol);
		}
	}
}

static void perm_priv(struct vec *sol,
		struct vec *chs, size_t count, void (*fun)(struct vec *)) {
	if (count == 0) {
		fun(sol);
	} else {
		struct vec *newsol, *newchs;
		for (int i = 0; i < chs->size; i++) {
			newsol = vec_push(sol, chs->element[i]);
			newchs = vec_removeAtIndex(chs, i);
			comb_priv(newsol, newchs, count - 1, fun);
			vec_free(newchs);
			vec_free(newsol);
		}
	}
}
