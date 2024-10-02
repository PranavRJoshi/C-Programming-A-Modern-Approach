// Q. Write a loop that prints the highest temperature in the temperatures array (see Exercise 14) for each day of the week. The loop body should call the find_largest function, passing it one row of the array at a time.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 7
#define NUM_COLS 24

int find_largest (int *arr_ptr, int col_size);

int main (void) {
  
  int temperature[NUM_ROWS][NUM_COLS];
  int *temp_ptr;

  srand((unsigned int) time(NULL));
  
  // setup random temperature reading in the range of 0 to 100
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      temperature[i][j] = (rand() % 101);
    }
  }

  printf("The temperature matrix is: \n");

  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%3d ", temperature[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < NUM_ROWS; i++) {
    // similar as
    // temp_ptr = &temperature[i][0]
    temp_ptr = temperature[i];
    printf("The highest temperature in day %d is: %d\n", i + 1, find_largest(temp_ptr, NUM_COLS));
  }

  return 0;
}

int find_largest (int *ap, int cs) {
  int largest = *ap;
  int *temp = ap;

  for (; ap < temp + cs; ap++) {
    if (*ap > largest) {
      largest = *ap;
    }
  }

  return largest;
}
