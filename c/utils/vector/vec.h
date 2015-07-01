#ifndef VEC_H_
#define VEC_H_

struct vec {
	int size;
	int element[0];
};

void vec_print(struct vec *v);
void vec_free(struct vec *v);
struct vec *vec_create(size_t size);
struct vec *vec_concat(struct vec *lhs, struct vec *rhs);
struct vec *vec_push(struct vec *v, int item);
struct vec *vec_copy(struct vec *v);
struct vec *vec_removeAtIndex(struct vec *v, int index);
struct vec *vec_removeFirstN(struct vec *v, int n);

#endif
