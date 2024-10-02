// Q. Rewrite the following function to use pointer arithmetic instead of array subscripting. (In other words, eliminate the variables i and j and all uses of the [] operator.) Use a single loop instead of nested loops.
//    int sum_two_dimensional_array (const int a[][LEN], int n) {
//      int i, j, sum = 0;
//
//      for (i = 0; i < n; i++) {
//        for (j = 0; j < LEN; j++) {
//          sum += a[i][j];
//        }
//      }
//      return sum;
//    }

#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 6

int sum_two_dimensional_array (const int *arr_ptr, int row_size, int col_size);

int main (void) {

  int arr[NUM_ROWS][NUM_COLS] = {0};
  int sum = 0;

  for (int i = 0; i < NUM_ROWS; i++) {
    printf("Enter %d elements for row %d: ", NUM_COLS, i + 1);
    for (int j = 0; j < NUM_COLS; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  
  // same call:
  // sum = sum_two_dimensional_array (&arr[0][0], NUM_ROWS, NUM_COLS);
  // arr[0] is like saying &arr[0][0] as &(*(a[0] + 0)) is equivalent to a[0] since & and * cancels each other
  sum = sum_two_dimensional_array (arr[0], NUM_ROWS, NUM_COLS);

  printf("The sum of all the elements are: %d\n", sum);

  return 0;
}

int sum_two_dimensional_array (const int *a, int rs, int cs) {
  int sum = 0;
  int temp_col = cs;

  while (rs > 0) {
    while (cs > 0) {
      sum += *a++;
      cs--;
    }
    cs = temp_col;
    rs--;
  }

  return sum;
}
