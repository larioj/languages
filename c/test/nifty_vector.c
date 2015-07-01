#include <stdio.h>
#include <stdlib.h>

// The array vector using a 
// zero element array.
struct array_vector {
  int size;
  int component[0];
};

// A vector using a pointer.
struct ptr_vector {
  int size;
  int *component;
};

int main() {
  // What are the sizes?
  printf("Size of ptr_vecor: %lu\n", sizeof(struct ptr_vector));
  // result: Size of ptr_vecor: 16
  printf("Size of array_vector: %lu\n", sizeof(struct array_vector));
  // result: Size of array_vector: 4
  
  // We see that the array vector has 1/4 the size of the ptr vector.
  // The reason for this is that the pointer is 4 bytes for the size
  // 4 bytes of padding (components have to line up) and 8 bytes for
  // the ptr. The array vector on the other hand only needs the 4 bytes
  // for the size field since it has a zero length int array. 
  
  // So what?
  // Well we can actually use these vectors as variable length vectors.

  // creating a 5 element ptr vector.
  struct ptr_vector *p_vec = malloc(sizeof(struct ptr_vector));
  p_vec->component = malloc(5 * sizeof(int));
  
  // creating a 5 element array vector.
  struct array_vector *a_vec =
    malloc(sizeof(struct array_vector) + 5 * sizeof(int));

  // Let's add some elements.
  for (int i = 0; i < 5; i++) {
    p_vec->component[i] = i;
    a_vec->component[i] = i;
  }

  // Let's print the elements.
  for (int i = 0; i < 5; i++) {
    printf("ptr: %d\t arr: %d\n",
        p_vec->component[i], a_vec->component[i]);
  }

  // The two vectors work exactly the same, except that
  // the array vector uses less space, and can take advantage
  // of locality. The ptr vector has to hold padding and the ptr
  // and it's components are stored in two possibly different
  // parts of memory. Overall the ptr vector is better for
  // perfomace and space.
}
