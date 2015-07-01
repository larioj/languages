#include <stdio.h>
#include <string.h>

int main () {
  char *sp = "hello world.";  // Allocated at the bottom
                              // of the heap on global not write mem.
  char s[] = "hello world.";  // Alocated on the stack.
  // Let's print them.
  printf("%s\n", sp);
  // res: hello world.
  printf("%s\n", s);
  // res: hello world.
  s[2] = 'r';
  printf("%s\n", s);
  // res: herlo world.
  sp[2] = 'r';
  // res: Bus error: 10
  // D:
  return 0;
}

// Ending remarks.
// The reason why the last assigment fails is that
// the string assigned to the pointer was allocated
// in the read only portion of memory at the bottom
// of the stack, in the data portion. This is the
// reason why the program fails when it tries to
// write. Note that the ptr itself is on the stack.
