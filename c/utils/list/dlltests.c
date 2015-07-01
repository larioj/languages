#include <stdio.h>
#include "intdll.h"

/* read
push_test
push 3 push 5 pop pop
[](0)

in general
test_name
cmd args cmd args
state */

#define T int
#define C dll
#define PRT "%d"
#define _INNER( type, classname, methodname ) \
     type ## classname ## _ ## methodname
#define _OUTER( type, classname, methodname ) \
     _INNER(type, classname, methodname)
#define _(name) \
     _OUTER(T, C, name)

void test_allocate();
void test_free();
void test_print();

struct funs {
	char *name;
	void (*fun)();
};

struct funs funs[] = {
	{"allocate", test_allocate},
	{"free", test_free},
	{"print", test_print},
	{NULL, NULL}
};

int main() {
	return 0;
}

#undef _
#undef _OUTER
#undef _INNER
#undef PRT
#undef C
#undef T
