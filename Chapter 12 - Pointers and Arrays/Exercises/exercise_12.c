// Q. Write the following function:
//    void find_two_largest (const int *a, int n, int *largest, int *second_largest);
// a points to an array of length n. The function searches the array for its largest and second largest elements, storing them in the variables pointed to by largest and second_largest, respectively. Use pointer-arithmetic--not subscripting--to visit array elements.

#include <stdio.h>

#define N 10

void find_two_largest (const int *a, int n, int *largest, int *second_largest);


int main (void) {

  int arr[N] = {0};
  int largest, second_largest;

  printf("Enter %d elements: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  
  find_two_largest(arr, N, &largest, &second_largest);

  printf("The largest element in the array is %d and the second largest is: %d\n", largest, second_largest);

  return 0;
}

void find_two_largest (const int *a, int n, int *l, int *sl) {
  *l = *a;
  *sl = *a;

  int temp = n;

  while (n > 0) {
    if (*a > *l) {
      *l = *a;
    }
    a++;
    n--;
  }

  a -= temp;

  while (temp > 0) {
    if (*a > *sl && *a < *l) {
      *sl = *a;
    }
    a++;
    temp--;
  }
}

