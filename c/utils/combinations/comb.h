#ifndef COMB_H_
#define COMB_H_

#include "../vector/vec.h"
void comb(int elements, int choices, void (*fun)(struct vec *));
void perm(int elements, int choices, void (*fun)(struct vec *));

#endif
