// Q. Modify the find_largest function so that it uses pointer arithmetic--not subscripting--to visit array elements.

#include <stdio.h>

#define N 10

int find_largest (const int *a, int n);

int main (void) {

  int arr[N] = {0};
  int max;

  printf("Enter %d elements: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  max = find_largest(arr, N);

  printf("The largest value in the array is: %d\n", max);

  return 0;
}

int find_largest (const int *a, int n) {
  int max = *a;

  while (n > 0) {
    if (*a > max) {
      max = *a;
    }
    a++;
    n--;
  }

  return max;
}

