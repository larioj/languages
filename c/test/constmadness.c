#include <stdio.h>

int main()
{
    int a = 3, *c = &a, aa = 5;
    const int b = a;
    const int *d = c;
    printf("%d : %d\n", a, *c);
    printf("%d : %d\n", b, *d);
    // b = aa; // does not work
    d = &aa; // works
    // *d = aa; // does not work
    int aaa = 9, **ccc = &c;
    const int *const p = c;
    printf("%d : %d\n", *c, *p);
    const int y = 4;
    const int *x = &y;
}
