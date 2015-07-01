#include <stdlib.h>
#include <stdio.h>

struct proc {
	int foo;
	int *bar;
};

struct proc * volatile g_array[10];

