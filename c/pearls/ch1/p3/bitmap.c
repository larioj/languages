#include <stdlib.h>
#include "bitmap.h"

/* 
 * ADT: bitmap
 * Holds an array of bits that can be either zero
 * or one.
 *
 * Operations on a bitmap:
 * 	- create bitmap
 * 	- free bitmap
 * 	- set index
 * 	- clear index
 * 	- test index
 *
 * 	The bitmap does not grow dynamically.
 */

/* 
 * Creates a new bitmap of size size, where all
 * elements are zero. Returns NULL pointer on
 * error.
 */
struct bitmap *bitmap_allocate(size_t size) {
	struct bitmap *bitmap;
	bitmap = malloc(sizeof(*bitmap));
	if (!bitmap) {
		return NULL;
	}
	bitmap->word = calloc(
			size % WORD_SIZE ? (size / WORD_SIZE) + 1 : (size / WORD_SIZE),
			sizeof(*(bitmap->word))
			);
	if (!bitmap->word) {
		free(bitmap);
		return NULL;
	}
	bitmap->size = size;
	return bitmap;
}

/*
 * Frees the memory associated with the bitmap. Returns
 * zero on success and non-zero on error. 
 */
int bitmap_free(struct bitmap *bitmap) {
	if (bitmap) {
		free(bitmap->word);
	}
	free(bitmap);
	return 0;
}

/*
 * Sets the bitmap bit at index index to 1. Returns
 * nonzero value on failure.
 * Requires: 0 <= index < size
 */
int bitmap_set(struct bitmap *bitmap, int index) {
	if (!bitmap ||
			index < 0 || index >= bitmap->size) {
		return 1;
	}
	bitmap->word[index / WORD_SIZE] |= (1 << (index % WORD_SIZE));
	return 0;
}

/*
 * Sets the bitmap bit at index index to 0. Returns
 * nonzero value on failure.
 * Requires: 0 <= index < size
 */
int bitmap_clear(struct bitmap *bitmap, int index) {
	if (!bitmap ||
			index < 0 || index >= bitmap->size) {
		return 1;
	}
	bitmap->word[index / WORD_SIZE] &= ~(1 << (index % WORD_SIZE));
	return 0;
}

/*
 * Tests if the bit of bitmap at index index in 1.
 * Returns zero if the bit at index is 0, and nonzero
 * otherwise.
 * Requires: 0 <= index < size
 */
int bitmap_test(struct bitmap *bitmap, int index) {
	if (!bitmap ||
			index < 0 || index >= bitmap->size) {
		return 1;
	}
	return bitmap->word[index / WORD_SIZE] & (1 << (index % WORD_SIZE));
}
