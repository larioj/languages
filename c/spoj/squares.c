#include <stdio.h>
#include <stdlib.h>

int numsquares(int n);
struct square {
  int top, left, width;
};

#define top(sq) (sq.top)
#define bottom(sq) (sq.top + sq.width)
#define left(sq) (sq.left)
#define right(sq) (sq.left + sq.width)

int main(int argc, char **argv) {
  int n;
  scanf("%d", &n);
  while(n) {
    printf("%d\n", numsquares(n));
    scanf("%d", &n);
  }
	return 0;
}

int numsquares(int n) {
  int res = 0;
  struct square sq = {0, 0, 1};
  while(sq.width <= n) {
    res++;
    sq.left++;
    if(right(sq) > n) {
      sq.top++;
      sq.left = 0;
    }
    if(bottom(sq) > n) {
      sq.top = 0;
      sq.width++;
    }
  }
  return res;
}
