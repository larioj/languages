#include <stdio.h>
#include <string.h>

int rpn(char *exp, int size);
int check_constraints(char *exp, int size);
int get_delim(char *exp, int size);
int is_operator(char c);
int merge(char *dest, char *left, char *right, char delim);

int main (int argc, char **argv) {
  if (argc == 1) {
    int exp_num;
    char exp[512];
    if (fgets(exp, sizeof(exp), stdin) &&
        sscanf(exp, "%d", &exp_num) == 1) {
      for (int i = 0; i < exp_num; i++) {
        if (fgets(exp, sizeof(exp), stdin)) {
          exp[strlen(exp) - 1] = '\0';
          rpn(exp, strlen(exp));
          printf("%s\n", exp);
        }
      }
    }
    return 0;
  } else {
    printf("Testing:\n");
    printf("Merge:\n");
    char buf[10];
    buf[0] = '0';
    buf[1] = '1';
    buf[2] = '2';
    buf[3] = '3';
    buf[4] = '4';
    buf[5] = '\0';
    buf[6] = '6';
    buf[7] = '7';
    buf[8] = '8';
    buf[9] = '\0';
    char *left, *right, delim = '+';
    left = buf + 1;
    right = buf + 5 + 1;
    merge(buf, left, right, delim);
    printf("%s\n", buf);
  }
}

// requires: exp be a c string, with no
// spaces and only valid characters.
int rpn(char *exp, int size) {
  if (size == 1) {
    return 0;
  } else {
    if (check_constraints(exp, size)) {
      printf("%s\n", exp);
      printf("Constraints not met\n");
      return 1;
    }
    int delim_loc = get_delim(exp, size);
    char delim = exp[delim_loc];
    exp[delim_loc] = '\0';
    exp[size - 1] = '\0';
    char *left, *right;
    left = exp + 1;
    right = exp + delim_loc + 1;
    if (rpn(left, strlen(left)) ||
        rpn(right, strlen(right))) {
      return 1;
    }
    merge(exp, left, right, delim);
    return 0;
  }
}

int merge(char *dest, char *left, char *right, char delim) {
  int left_size = strlen(left);
  int right_size = strlen(right);
  for (int i = 0; i < left_size; i++) {
    dest[i] = left[i];
  }
  for (int i = 0; i < right_size; i++) {
    dest[i + left_size] = right[i];
  }
  dest[left_size + right_size] = delim;
  dest[left_size + right_size + 1] = '\0';
  return 0;
}

int check_constraints(char *exp, int size) {
  if (exp[0] == '(' &&
      exp[size - 1] == ')') {
    return 0;
  }
  return 1;
}

int get_delim(char *exp, int size) {
  int i, paren = 0;
  for (i = 0; i < size; i++) {
    switch(exp[i]) {
      case '(':
        paren++;
        break;
      case ')':
        paren--;
        break;
      default:
        if (paren == 1 &&
            is_operator(exp[i])) {
          return i;
        }
    }
  }
  return -1;
}

int is_operator(char c) {
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      return 1;
    default:
      return 0;
  }
}
