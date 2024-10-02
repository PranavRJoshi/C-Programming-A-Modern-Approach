// Q. Rewrite the following function to use pointer arithmetic instead of array subscripting. (In other words, eliminate the variable i and all uses of the [] operator.) Make as few changes as possible.
//    int sum_array (const int a[], int n) {
//      int i, sum;
//
//      sum = 0;
//      for (i = 0; i < n; i++) {
//        sum += a[i];
//      }
//      return sum;
//    }

#include <stdio.h>

#define N 10

int sum_array (const int *a, int n);

int main (void) {

  int arr[N] = {0};
  int sum = 0;

  printf("Enter the elements: ");
  
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  sum = sum_array(arr, N);

  printf("The sum of the elements is: %d\n", sum);

  return 0;
}

int sum_array (const int *a, int n) {
  int sum = 0;

  while (n > 0) {
    sum += *a++;
    n -= 1;
  }
  
  return sum;
}
