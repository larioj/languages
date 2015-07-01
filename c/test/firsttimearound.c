#include <stdio.h>

int main() {
	int nums[] = {1, 2, 3, 4, 5, 6};
	size_t size = sizeof(nums)/sizeof(nums[0]);
	for (int i = 0; i < size; i++) {
		static char preffix = '[';  // this is awesome.
		printf("%c%d", preffix, nums[i]);
		preffix = ',';
	}
	printf("]\n");
}
