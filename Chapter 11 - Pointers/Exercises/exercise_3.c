// Q. The following function supposedly computes the sum and average of the numbers in the array a, which has length n, avg and sum point to variables that the function should modify. Unfortunately, the function contains several errors; find and correct then.
//    void avg_sum (double a[], int n, double *avg. double *sum) {
//      int i;
//
//      sum = 0.0;
//      for (i = 0; i < n; i++) {
//        sum += a[i];
//      }
//      avg = sum / n;
//    }

#include <stdio.h>

#define N 5

void avg_sum (int a[], int n, double *avg, double *sum);

int main (void) {

  int arr[N] = {0};
  double average, sum;


  printf("Enter %d numbers: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  avg_sum(arr, N, &average, &sum);

  printf("The average of the numbers is: %.2lf\n", average);
  printf("The sum of the numbers is: %.2lf\n", sum);

  return 0;
}

void avg_sum (int a[], int n, double *avg, double *sum) {
  int i;

  // sum and address are pointer to double variable, we need the object stored
  // in the pointer and modify it, so we use the indirection operator.
  *sum = 0.0;
  for (i = 0; i < n; i++) {
    *sum += a[i];
  }
  
  *avg = *sum / n;
}
