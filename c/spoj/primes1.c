#include <stdio.h>
#include <stdlib.h>

void sieve (long *arr, long size) {
  if (size < 3) {
    for (long i = 0; i < size; i++)
      arr[i] = 0;
  } else {
    arr[0] = 0;
    arr[1] = 0;
    for (long i = 2; i*i < size; i++) {
      if (arr[i] != 0) {
        for (long j = 2*i; j < size; j += i) {
          arr[j] = 0;
        }
      }
    }
  }
}

int is_prime(long num) {
  if (num == 1)
    return 0;
  for (long i = 2; i*i <= num; i++) {
    if ((num % i) == 0)
      return 0;
  }
  return 1;
}

void backup (long lo, long hi) {
  for (long i = lo; i <= hi; i++) {
    if (is_prime(i)) {
      printf("%ld\n", i);
    }
    printf("\n");
  }
}

int main(void) {
  long lo, hi, *nums = NULL;
  char buf[1024];
  while (fgets(buf, sizeof(buf), stdin)) {
    if (sscanf(buf, "%ld %ld", &lo, &hi) == 2) {
      long* tmp = (long*) realloc(nums, (hi + 1) * sizeof(long));
      if (tmp == NULL) {
        backup(lo, hi);
        continue;
      }
      nums = tmp;
      for (long i = 0; i <= hi; i++) {
        nums[i] = i;
      }
      sieve(nums, hi + 1);
      for (long i = lo; i <= hi; i++) {
        if (nums[i] != 0)
          printf("%ld\n", nums[i]);
      }
      printf("\n");
    } 
  }
  free(nums);
  return 0;
}
