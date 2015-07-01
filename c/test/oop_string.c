#include <stdio.h>
#include <stdlib.h>

int getSizefn(void *str) {
  int *size = (int *) str;
  return (int) *size;
}

struct struct_str {
  int size;
  int (*getSize)(void *);
  char c_str[0];
};

typedef struct struct_str oop_string;

int main() {
  oop_string str;
  str.size = 5;
  str.getSize = &getSizefn;
  int size = str.getSize(&str);
  printf("Default string size: %d\n", size);
}

// It worked!!!
