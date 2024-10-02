// Q. Write a macro NELEMS(a) that computes the number of elements in a one-dimensional array a. Hint: See the discussion of the sizeof operator in Section 8.1.

#include <stdio.h>

#define NELEMS(a)               \
(sizeof (a) / sizeof (a[0]))

int main (void) {

  int n;
  // using size_t instead of int as the return type from using the sizeof operator is size_t
  size_t size;

  printf("Declare an array of size: ");
  while (scanf("%d", &n) != 1 || n <= 0) {
    if (n <= 0) {
      printf("[WARN] Attempt to create an array of size 0 or less. Try Again: ");
    }
  }

  int vlarr[n];

  size = NELEMS(vlarr);

  printf("[NELEMS OUTPUT] The length of the array as given by the NELEMS macro is: %zu\n", size);

  return 0;
}

