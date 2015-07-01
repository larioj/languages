// So I've been getting more familiar with
// c syntax, however I'm still a little iffy
// about a couple of things. This is to see
// what I can and can't do in c.

int main() {
  // typedefs
  // multiple assigments in the same line.
  typedef int num, *numptr;
  num i = 0;  // works
  numptr p = &i;  // works
  
  return 0;
}
