// Q. Section 8.2 had a program fragment in which two nested for loops initialized the array ident for use as an identity matrix. Rewrite this code, using a single pointer to step through the array one element at a time. Hint: Since we won't be using row and col index variables, it won't be easy to tell where to store 1. Instead, we can use the fact that the first elements of the array should be 1, the next N elements should be 0, the next element should be 1, and so forth. Use a variable to keep track of how many consecutive 0s have been stored; when the count reaches N, it's time to store 1.

#include <stdio.h>

#define N 5

int main (void) {

  double ident[N][N];
  double *ident_p;
  int i = 0;

  for (ident_p = &ident[0][0]; ident_p <= &ident[N-1][N-1]; ident_p++) {
    if (i % (N + 1) == 0) {
      *ident_p = 1.0;
    } else {
      *ident_p = 0.0;
    }
    i++;
  }
  
  printf("The elements in the matrix is: \n");

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%.1lf ", ident[i][j]);
    }
    printf("\n");
  }

  return 0;
}

