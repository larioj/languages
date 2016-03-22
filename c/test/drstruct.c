#include <stdio.h>

int main() {
    struct {
        int a, b;
    } s1, s2;  // s1 and s2 are variables of struct

    // struct with bitfields.
    struct allthebits {
        unsigned int valid :1;
        unsigned int :1;  // padding
        unsigned int type :6;
        unsigned int :0;
        int value;
    };

    s1.a = 5;
    s1.b = 6;
    s2.a = 7;
    s2.b = 8;
}

/* struct optional_tag {
 *   stuff
 *
 *   if you want bits you can do colons:
 *   unsigned int name :numbits;
 * } optional_vars; */

