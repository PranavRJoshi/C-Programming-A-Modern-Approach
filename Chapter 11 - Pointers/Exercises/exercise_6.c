// Q. Write the following function:
//    void find_two_largest (int a[], int n, int *largest, int *second_largest);
// When passed an array a of length n, the function will search a for its largest and second largest elements, storing them in the variables pointed to by largest and second_largest, respectively.

#include <stdio.h>

#define N 10

void find_two_largest (int a[], int n, int *largest, int *second_largest);

int main (void) {

  int arr[N] = {0};
  int largest_element, second_largest_element;

  printf("Enter %d elements: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  find_two_largest(arr, N, &largest_element, &second_largest_element);

  printf("The largest element in the array is: %d\n", largest_element);
  printf("The second largest element in the array is: %d\n", second_largest_element);

  return 0;
}

void find_two_largest (int a[], int n, int *largest, int *second_largest) {
  *largest = a[0];
  *second_largest = a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] > *largest) {
      *largest = a[i];
    }
  }
  for (int i = 1; i < n; i++) {
    if (a[i] > *second_largest && a[i] < *largest) {
      *second_largest = a[i];
    }
  }
}

