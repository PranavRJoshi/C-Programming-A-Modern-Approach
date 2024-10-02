// Q. Write the following function:
//    double inner_product (const double *a, const double *b, int n);
// a and b both points to arrays of length n. The function should return a[0] * b[0] + a[1] * b[1] + ... + a[n-1] * b[n-1]. Use pointer arithmetic--not subscripting--to visit array elements.

#include <stdio.h>

#define N 10

double inner_product (const double *a, const double *b, int n);

int main (void) {

  double arr_1[N] = {0.0};
  double arr_2[N] = {0.0};
  double sum = 0.0;

  printf("Enter %d elements for the first array: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%lf", &arr_1[i]);
  }

  printf("Enter %d elements for the second array: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%lf", &arr_2[i]);
  }

  sum = inner_product(arr_1, arr_2, N);

  printf("The sum of the product of the elements are: %.2lf\n", sum);

  return 0;
}

double inner_product (const double *a, const double *b, int n) {
  double sum = 0.0;

  while (n > 0) {
    sum += ((*a++) * (*b++));
    n--;
  }

  return sum;
}
