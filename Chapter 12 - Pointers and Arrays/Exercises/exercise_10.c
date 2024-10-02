// Q. Modify the find_middle function of Section 11.5 so that it uses pointer arithmetic to calculate the return value.

#include <stdio.h>

#define N 10

int *find_middle (int *a, int n); 

int main (void) {

  int arr[10] = {0};
  int *middle_pointer;

  printf("Enter %d elements: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  middle_pointer = find_middle(arr, N);

  printf("The middle element of the array is: %d\n", *middle_pointer);

  return 0;
}

int *find_middle (int *a, int n) {
  return a+(n/2);
}
