// Q. Write the following function:
//    int *find_largest(int a[], int n);
// When passed an array a of length n, the function will return a pointer to the array's largest element

#include <stdio.h>

#define N 10

int *find_largest (int a[], int n);

int main (void) {

  int arr[N] = {0};
  int *largest;

  printf("Enter %d numbers: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d",&arr[i]);
  }

  // largest stores the pointer (address) to the largest element in the array
  largest = find_largest(arr, N);

  printf("The largest element in the array is: %d\n", *largest);
  
  return 0;
}

int *find_largest (int a[], int n) {
  int largest_index = 0;

  for (int i = 1; i < n; i++) {
    if (a[i] > a[largest_index]) {
      largest_index = i;
    }
  }

  // returns the pointer (address) to the array element that is the largest in the array.
  return &a[largest_index];
}

