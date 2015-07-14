#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* this program finds the smallest palindrome larger
 * than the given number. Works for numbers up to
 * 1,000,000 digits. */

/* There are several interesting things about this
 * program, which I will point out in comments above
 * the line in which they occur. Most of them are
 * c idioms. */

/* Everyone knows that NULL is the null pointer, but NUL
 * is the null character that terminates a string in c. */
#define NUL '\0'

/* Returns true if all charactes of str are '9', and false
 * otherwise. */
bool nines(char *str);

/* reversed-left to right compare of str. If str
 * contains an even number of characters, the reversed left
 * half of  str is compared to the right half of the
 * str returning 0 if they are the same, a positive number
 * if the reversed-left side is bigger, and a negative number
 * if it is smaller. If the str contains an odd number of
 * characters the middle character is ignored and the comparison
 * is carried out as in the even case. For example 123321 will
 * return 0 since reversed(123) eq 321. On the other hand
 * 123495321 will yield a negative number since reverse(1234)
 * lt 5321. Note that the 9 is ignored.*/
int rlrcmp(char *str);

/* get right and left pointers to str. If str contains an
 * even number of characters then r will be set to point
 * to the character to the immediate right of the middle
 * of str and l will be set to point to the character to
 * the immediate left of the middle of str. Note that in
 * the even case the middle is not a character. It is just
 * a division. If str contains an odd number of characters
 * then the middle is a character, and r and l are updated
 * in the same abstract manner as described in the even
 * case.  For example, if str is 123456, r will point to
 * 4 and l will point to 3, and if str is 12345, r will
 * point to 2 and l will point to 4. */
void getrl(char *str, char **r, char **l);

/* Prints out 10{sizeof(str) - 1}1. I maintain that this is a
 * good name for the function because it looks like what is does,
 * and it's funny cause it lols. For example, if str is 99, then
 * lol will print out 101.*/
void lol(char *str);

/* Prints out str reflected on it center. For example, if str is
 * 12345, then reflect will print out 12321, and if str is 1234
 * then reflect will print out 1221. Note that this function
 * destroys str. */
void reflect(char *str);

/* increment left. Increments by one, in place, the left side
 * of str concatenated with the center character if str is of
 * odd length. For example if str is 12345, the increment will
 * modify str to be 12445. The left part + middle character
 * increased from 123 to 124. If str is 1945, then str will
 * be modified to 2045. Note that in this case there is no
 * middle character. Note that this function does not work
 * if all characters of the left + middle parts of str are
 * nines. */
void incrementl(char *str);

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
		} else if (0 < rlrcmp(str)) {
			reflect(str);
		} else {
			incrementl(str);
			reflect(str);
		}
	}
}

bool nines(char *str) {
	/* The null character evalutates to false so the loop
	 * will terminate when str points to it. Also note
	 * that str is a local copy so it doesn't matter
	 * that we modify it. This type of while loop is
	 * a c idion and can be seen in the implementation
	 * strlen. */
	while(*str) {
		if ('9' != *str)
			return false;
		str++;
	}
	return true;
}

void lol(char *str) {
	/* Another c idiom (maybe not just in c).
	 * This is actually one of my favorites.
	 * For a long time I always felt awkward when I had to
	 * print out something different at the beginning of a
	 * range print. I always felt that there must be a more
	 * elegant way of doing it. This is it. Also it doesn't
	 * matter that we are assigning inside a loop, it'll get
	 * optimized out. */
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
	
	/* This checks if len is odd. The bitwise & will
	 * evaluate to zero if the rightmost bit is zero, which
	 * indicates that len is divisible by two and therefore
	 * even. Since zero is false this, the statement is false
	 * when len is even. The judge is still out on this one
	 * if it actually should be used, or if it's just convoluted
	 * but it's about the same as len % 2. */
	if (len & 1)
		(*r)++;
}

int rlrcmp(char *str) {
	char *l, *r;
	int res = 0;
	getrl(str, &r, &l);
	/* This is probably the most complicated
	 * function in the whole program. It may not seem like it
	 * since it's so few lines. But really this function can
	 * easily take up way more space and be way more convoluted
	 * if not done correctly. It actually demonstrates another
	 * cool c idiom, where complex indexing can be done using
	 * pointers. This function takes a lot of inspiration from
	 * the implementation of the strcmp function. */
	while(*r && !res) {
		res = *l - *r;
		r++, l--;
	}
	return res;
}

void reflect(char *str) {
	char *r, *l;
	getrl(str, &r, &l);
	/* Right here I didn't want to write two loops
	 * so I just leveraged the fact that I already had
	 * a pointer to the terminating index of the first
	 * half of the str, and that printf will only print
	 * till the NUL character. I felt it was a nifty
	 * simplification. */
	*r = NUL;
	printf("%s", str);
	while(l != str) {
		printf("%c", *l);
		l--;
	}
	printf("%c\n", *l);
}

void incrementl(char *str) {
	char *r, *l;
	getrl(str, &r, &l);
	r--;
	/* This is another example of looping based on pointers.
	 * It's really powerful. Note that throughout the program
	 * comparisons are reversed. This is also a c idiom. Since
	 * assignments are allowed within boolean expressions,
	 * "=" being used instead of "==" is a very easy mistake to
	 * make, and a very hard bug to catch. It's good to be in
	 * the habit of placing the literal first. */
	while ('9' == *r) {
		*r = '0';
		r--;
	}
	(*r)++;
}

/* A note about design: The modularity of the program is very
 * useful. The best function in the program is getrl. It confines
 * complicated indexing to a single part of the program and then
 * is reused multiple times. It makes all the other function very simple.
 * Without getrl the other parts of the code would be significantly
 * more complicated. Also there are now more comments than code =] */
