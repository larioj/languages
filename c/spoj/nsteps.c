#include <stdio.h>
#include <stdlib.h>

int nsteps(int x, int y);

/* Code as data */
int same[] = {0, 1, 4, 5, 8, 9};

int main(int argc, char **argv) {
  int c, x, y, res;
  scanf("%d", &c);
  while(c--) {
    scanf("%d %d", &x, &y);
    if (-1 == (res = nsteps(x, y))) {
      printf("No Number\n");
    } else {
      printf("%d\n", res);
    }
  }
	return 0;
}

int nsteps(int x, int y) {
  int mod, res = 0;
  if(y != x && y != x - 2) return -1;
  if(y == x - 2) res = 2;
  mod = y % 6;
  y -= mod;
  res += 2 * y + same[mod];
  return res;
}
