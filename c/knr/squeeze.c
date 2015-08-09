#include <stdio.h>
#include <stdlib.h>

void squeeze(char *str, char *pat);

int main(int argc, char **argv) {
	return 0;
}

/* Removes any substring matching pat
 * from str. */
void squeeze(char str[], char pat[]) {
	int i, j;
	for (i = 0; str[i]; i++) {
		for (j = 0; pat[j]; j++) {
			if (pat[j] != str[i + j])
				break;
		}

	}
}
