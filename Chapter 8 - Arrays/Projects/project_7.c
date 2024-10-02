// Q. Write a program that reads a 5 x 5 array of integers and then prints the row sums and the column sums:
//    Enter row 1: 8 3 9 0 10
//    Enter row 2: 3 5 17 1 1
//    Enter row 3: 2 8 6 23 1
//    Enter row 4: 15 7 3 2 9
//    Enter row 5: 6 14 2 6 0
// Row totals: 30 27 40 36 28
// Column totals: 34 37 37 32 21

#include <stdio.h>

#define COL_SIZE 5
#define ROW_SIZE 5

int main (void) {

  int arr_mat[ROW_SIZE][COL_SIZE] = {0};
  int row_total[ROW_SIZE] = {0};
  int col_total[COL_SIZE] = {0};

  // Inout the data from the user and store them in elements of arr_mat
  for (int i = 0; i < ROW_SIZE; i++) {
    printf("Enter row %d: ", i+1);
    for (int j = 0; j < COL_SIZE; j++) {
      scanf("%d", &arr_mat[i][j]);
    }
  }

  // iterate over the arr_mat to add the row total and the column total
  for (int i = 0; i < ROW_SIZE; i++) {
    for (int j = 0; j < COL_SIZE; j++) {
      row_total[i] += arr_mat[i][j];
      col_total[j] += arr_mat[i][j];
    }
  }

  // display the row total
  printf("Row totals: ");
  for (int i = 0; i < ROW_SIZE; i++) {
    printf("%d ", row_total[i]);
  }
  
  printf("\n");

  // display the column total
  printf("Column totals: ");
  for (int i = 0; i < COL_SIZE; i++) {
    printf("%d ", col_total[i]);
  }

  return 0;
}

