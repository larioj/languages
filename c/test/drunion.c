#include <stdio.h>
// All types are stored in the same memory.
union name {
	int a;
	double b;
	char c;
} var1, var2;

// A nifty test.
union charorint {
	int whole;
	struct {
		char a,b,c,d;
	} bytes;
} un1;

int main() {
	var1.a = 5;
	var2.b = 2.5;
	un1.whole = 0x61626364;  // a b c d
	printf("number: %d\n"  // notice the concatenation.
			"chars: %c %c %c %c\n",
			un1.whole, un1.bytes.a, un1.bytes.b, un1.bytes.c, un1.bytes.d);
	// Little of big endian?
	// number: 1633837924
	// chars: d c b a
}
