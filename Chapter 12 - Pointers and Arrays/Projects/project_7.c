// Q. Modify the maxmin.c program of Section 11.4 so that the max_min function uses a pointer instead of an integer to keep track of the current position in the array.

#include <stdio.h>

#define N 10

void max_min (int *a, int n, int *max, int *min);

int main (void) {

  int b[N] = {0};
  int max, min;

  printf("Enter %d numbers: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }

  max_min(b, N-1, &max, &min);

  printf("The largest number is: %d\n", max);
  printf("The smallest number is: %d\n", min);

  return 0;
}

void max_min (int *a, int n, int *max, int *min) {
  *max = *min = *a;

  while (n >= 0) {
    if (*(a + n) > *max) {
      *max = *(a + n);
    }
    if (*(a + n) < *min) {
      *min = *(a + n);
    }
    n--;
  }
}

