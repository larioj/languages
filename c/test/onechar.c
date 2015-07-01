#include <stdio.h>
#include <stdlib.h>

int main() {
	system("stty raw");
	char a;
	a = getchar();
	putchar(a);
	putchar('\n');
	system("stty cooked");
	return 0;
}
