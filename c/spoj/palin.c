#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define NUL '\0'

bool nines(char *str);
int refcmp(char *str);
void getrl(char *str, char **r, char **l);
void lol(char *str);
void reflect(char *str);
void increase(char *str);

int main() {
	int loops;
	char str[1000005];
	scanf("%i", &loops);
	while (loops--){
		scanf("%s", str);
		if (nines(str)) {
			lol(str);
		} else if (1 == strlen(str)){
			printf("%c\n", *str + 1);
		} else if (0 < refcmp(str)) {
			reflect(str);
		} else {
			increase(str);
			reflect(str);
		}
	}
}

bool nines(char *str) {
	while(*str) {
		if ('9' != *str)
			return false;
		str++;
	}
	return true;
}

void lol(char *str) {
	char c = '1';
	for (int i = 0; i < strlen(str); i++) {
		printf("%c", c);
		c = '0';
	}
	printf("%c\n", '1');
}

void getrl(char *str, char **r, char **l) {
	size_t len = strlen(str);
	*r = str + len/2;
	*l = *r - 1;
	if (len & 1)
		(*r)++;
}

int refcmp(char *str) {
	char *l, *r;
	int res = 0;
	getrl(str, &r, &l);
	while(*r && !res) {
		res = *l - *r;
		r++, l--;
	}
	return res;
}

void reflect(char *str) {
	char *r, *l;
	getrl(str, &r, &l);
	*r = NUL;
	printf("%s", str);
	while(l != str) {
		printf("%c", *l);
		l--;
	}
	printf("%c\n", *l);
}

void increase(char *str) {
	char *r, *l;
	getrl(str, &r, &l);
	r--;
	while ('9' == *r) {
		*r = '0';
		r--;
	}
	(*r)++;
}
