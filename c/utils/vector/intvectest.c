#include <stdio.h>
#include "intvec.c"

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
	V(push_front)(vec, 4);
	V(push_front)(vec, 5);
	V(push_front)(vec, 6);
	V(print)(vec);
	V(insert)(vec, 7, 2);
	V(print)(vec);
	V(pop_front)(vec, &dummy);
	V(pop_front)(vec, &dummy);
	V(print)(vec);
	for (int i = 4; i < 17; i++) {
		V(push_front)(vec, 10);
	}
	V(print)(vec);
	for (int i = 2; i < 17; i++) {
		V(pop_front)(vec, &dummy);
	}
	V(print)(vec);
	V(free)(vec);
	return 0;
}
