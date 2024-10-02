// Q. Write a function check(x, y, n) that returns 1 if both x and y fall between 0 and n - 1, inclusive. The function should return 0 otherwise. Assume that x, y, and n are all of type int.

#include <stdio.h>

int check (int x, int y, int n);

int main (void) {

  int num_1, num_2, n;

  int res;
  
  printf("Enter three numbers ");
  scanf("%d%d%d", &num_1, &num_2, &n);

  res = check(num_1, num_2, n);

  if (res == 1) {
    printf("%d and %d are in the range from 0 to %d", num_1, num_2, n - 1);
  } else {
    printf("%d or %d are not in the range from 0 to %d", num_1, num_2, n - 1);
  }

  return 0;
}

int check (int x, int y, int n) {
  if ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1)) {
    return 1;
  }
  return 0;
}
