// Q. Write the following function:
//    double inner_product (double a[], double b[], int n);
// The function should return a[0] * b[0] + a[1] * b[1] + ... a[n-1] * b[n-1].

#include <stdio.h>

#define LEN 5

double inner_product (double arr_1[], double arr_2[], int n);

int main (void) {

  double arr_1[LEN] = {0.0};
  double arr_2[LEN] = {0.0};
  double in_prod = 0.0;

  printf("Enter %d elements to store in the first array: ", LEN);
  
  for (int i = 0; i < LEN; i++) {
    scanf("%lf", &arr_1[i]);
  }

  printf("Enter %d elements to store in the second array: ", LEN);
  
  for (int i = 0; i < LEN; i++) {
    scanf("%lf", &arr_2[i]);
  }

  in_prod = inner_product(arr_1, arr_2, LEN);

  printf("The inner product is: %.2lf\n", in_prod);

  return 0;
}

double inner_product (double a[], double b[], int n) {
  double result = 0.0;

  for (int i = 0; i < n; i++) {
    result += (a[i] * b[i]);
  }

  return result;
}

