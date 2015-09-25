#include <stdio.h>
#include <stdlib.h>

int binsearch(int *elements, int element, int low, int high);

int main(int argc, char **argv) {
	int size = argc - 2, element;
	int elements[size];
	sscanf(argv[1], "%d", &element);
	for (int i = 0; i < size; i++) {
		sscanf(argv[i + 2], "%d", elements + i);
	}
	printf("index: %d\n", binsearch(elements, element, 0, size - 1));
	return 0;
}

int binsearch(int *elements, int element, int low, int high) {
	int res, mid = (low + high)/2;
	if (element == elements[mid]) {
		res = mid;
	} else if (low == high) {
		res = -1;
	} else if (element < elements[mid]) {
		res = binsearch(elements, element, low, mid - 1);
	} else {
		res = binsearch(elements, element, mid + 1, high);
	}
	return res;
}
