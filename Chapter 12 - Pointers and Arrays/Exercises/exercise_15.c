// Q. Write a loop that prints all temperature readings stored in row i of the temperatures array (see Exercise 14). Use a pointer to visit each element of the row.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 7
#define NUM_COLS 24

void print_row (int *temp_ptr, int row_index, int col_size);

int main (void) {

  int temperature[NUM_ROWS][NUM_COLS];
  int *temp_ptr = temperature[0];
  int row_index;

  srand((unsigned int) time(NULL));

  // setup random temperature reading in the range of 0 to 100
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      temperature[i][j] = (rand() % 101);
    }
  }

  printf("Enter the row size (1 to %d): ", NUM_ROWS);
  scanf("%d", &row_index);

  printf("The temperature matrix is: \n");

  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%3d ", temperature[i][j]);
    }
    printf("\n");
  }

  printf("The temperature on row %d is as follows: \n", row_index);

  print_row(temp_ptr, row_index - 1, NUM_COLS);
  
  return 0;
}

void print_row (int *tr, int ri, int cs) {
  tr = tr + (ri * cs);
  int *temp = tr;

  for (; tr < temp + cs; tr++) {
    printf("%3d ", *tr);
  }
  printf("\n");
}

