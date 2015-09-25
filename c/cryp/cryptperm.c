#include <stdio.h>
#include <stdlib.h>

/*
 * Shows the permutation formed by a cryptographic
 * hash. The hash requires that tablesize and hashvalue
 * be relatively prime. This is easily accomplished by
 * setting tablesize to a power of two and making
 * hashvalue odd.
 *
 * The hash takes the form:
 *   h2 = rem(k * h1, p)
 *
 * or equivalently
 *   h2 = (k * h1) % p
 *
 *
 * Theorem:
 *   The series rem(k1 * h1, p), rem(k2 * h1, p), ..., rem(kn * h1, p)
 *   is a permutation of the series k1, k2, ..., kn
 *
 * Proof:
 *   We prove that all terms rem(ki * h1, p) are distinct, and since
 *   there are n such terms, they form a permutation.
 *
 *   We proceed by contradiction. Let's assume that there are two terms
 *   rem(ki * h1, p) and rem(kj * h1, p), where ki != kj and
 *   rem(ki * h1, p) == rem(kj * h1, p).
 *
 *   rem(ki * h1, p) == rem(kj * h1, p) =>
 *   ki * h1 = kj * h1 (mod p) =>
 *   ki = kj (mod p) [Because h1 and p are relativelly prime]
 *
 *   since ki and kj are less than p, they must be equal. This is a
 *   contradiction, and thus all terms are distinct.
 */

int main(int argc, char **argv) {
	if (3 != argc) {
		printf("Usage: %s tablesize hashvalue\n", argv[0]);
		exit(1);
	}

	int tablesize, hashvalue;
	sscanf(argv[1], "%d", &tablesize);
	sscanf(argv[2], "%d", &hashvalue);

	char *prfx = "";
	for (int i = 0; i < tablesize; i++) {
		printf("%s%d", prfx, (i * hashvalue) % tablesize);
		prfx = ", ";
	}
	printf("\n");
	return 0;
}
