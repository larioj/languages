#include <stdio.h>
#include "gvec.c"

#define V(NAME) intvec_ ## NAME

int main() {
	V(vec) vec;
	int dummy;
	vec = V(allocate)();
	V(push_back)(vec, 1);
	V(push_back)(vec, 2);
	V(push_back)(vec, 3);
	V(print)(vec);
	V(pop_front)(vec, &dummy);
	V(print)(vec);
	V(free)(vec);
	return 0;
}
