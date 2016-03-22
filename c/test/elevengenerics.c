#include <stdio.h>

#define gen_print(x) _Generic((x), \
		char *: str_print, \
		int: int_print, \
		double: double_print)(x)

void int_print(int val)
{
    printf("This is an int: %d\n", val);
}

void double_print(double val)
{
    printf("This is a double: %f\n", val);
}

void str_print(char *val)
{
    printf("This is a string: %s\n", val);
}

int main()
{
    gen_print((char *) "hello");
    gen_print((int) 42);
    return 0;
}
