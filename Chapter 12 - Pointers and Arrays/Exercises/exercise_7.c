// Q. Write the following function:
//    bool search (const int a[], int n, int key);
// a is an array to be searched, n is the number of elements in the array, and key is the search key. search should return true if key matches some element of a, and false if it doesn't. Use pointer arithmetic--not subscripting--to visit array elements.

#include <stdio.h>
#include <stdbool.h>

#define N 10

bool search (const int *a, int n, int key);

int main (void) {

  int arr[N] = {0};
  int search_key;
  bool is_key_found = false;

  printf("Enter %d elements: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the value to search in array: ");
  scanf("%d", &search_key);

  is_key_found = search(arr, N, search_key);

  if (is_key_found) {
    printf("The value is in the array.\n");
  } else {
    printf("The value is not in the array.\n");
  }

  return 0;
}

bool search (const int *a, int n, int key) {
  while (n > 0) {
    if (*a++ == key) {
      return true;
    }
    n--;
  }
  return false;
}

