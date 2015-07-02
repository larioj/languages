#include <stdio.h>
#include "intheap.c"

#define h(NAME) intheap_ ## NAME

int h(comparator)(int lhs, int rhs) {
	if (lhs == rhs)
		return 0;
	else if (lhs > rhs)
		return 1;
	else
		return -1;
}

int main() {
	int dummy;
	h(heap) heap;
	heap = h(allocate)();
	h(insert)(heap, 4);
	h(insert)(heap, 2);
	h(insert)(heap, 3);
	h(insert)(heap, 1);
	h(insert)(heap, 21);
	h(insert)(heap, 211);
	h(insert)(heap, 210);
	h(insert)(heap, 1);
	h(print)(heap);
	h(free)(heap);
	return 0;
}
