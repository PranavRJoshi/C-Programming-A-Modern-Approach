// Q. Rewrite the following function to use pointer arithmetic instead of array subscripting. (In other words, eliminate the variable i and all uses of the [] operator.) Make as few changes as possible.
//    void store_zeros (int a[], int n) {
//      int i;
//
//      for (i = 0; i < n; i++) {
//        a[i] = 0;
//      }
//    }

#include <stdio.h>

#define N 10

void store_zeros (int *a, int n);

int main (void) {

  int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  store_zeros(arr, N);

  printf("After clearing the array, the elements are: \n");
  
  for (int i = 0; i < N; i++) {
    printf("Element %d has value: %d\n", i, arr[i]);
  }

  return 0;
}

void store_zeros (int *a, int n) {
  while (n > 0) {
    *a++ = 0;
    n--;
  }
}
