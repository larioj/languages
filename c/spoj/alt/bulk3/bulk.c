#include <stdio.h>
#include <stdlib.h>

struct point {
	int x, y, z;
};

struct face {
	int size;
	struct point *points;
};

struct bulk {
	int size;
	struct face *faces;
};

int io2bulk(const char *str, struct bulk **bulkptr);
int bulk2str(const struct bulk *bulk, char *str);

int main(int argc, char **argv) {
	return 0;
}

int io2bulk(const char *str, struct bulk **bulkptr) {
	struct bulk *bulk = malloc(sizeof *bulk);
	return 0;
}

int bulk2str(const struct bulk *bulk, char *str) {
	return 0;
}
