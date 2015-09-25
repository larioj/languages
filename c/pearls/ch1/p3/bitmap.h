#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stdlib.h>

/* Element definition. Unsigned chars must be a single
 * byte by default. Each byte is eight bits. */
#define WORD unsigned char
#define WORD_SIZE (sizeof(WORD)*8)

/* Bitmap Structure */
struct bitmap {
	size_t size;
	WORD *word;
};

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
struct bitmap *bitmap_allocate(size_t size);

/*
 * Frees the memory associated with the bitmap. Returns
 * zero on success and non-zero on error. 
 */
int bitmap_free(struct bitmap *bitmap);

/*
 * Sets the bitmap bit at index index to 1. Returns
 * nonzero value on failure.
 * Requires: 0 <= index < size
 */
int bitmap_set(struct bitmap *bitmap, int index);

/*
 * Sets the bitmap bit at index index to 0. Returns
 * nonzero value on failure.
 * Requires: 0 <= index < size
 */
int bitmap_clear(struct bitmap *bitmap, int index);

/*
 * Tests if the bit of bitmap at index index in 1.
 * Returns zero if the bit at index is 0, and nonzero
 * otherwise.
 * Requires: 0 <= index < size
 */
int bitmap_test(struct bitmap *bitmap, int index);

#endif
