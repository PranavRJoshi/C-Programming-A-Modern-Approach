// Q. Assume that the following array contains a week's worth of hourly temperature readings, with each row containing the readings for one day:
//    int temperature[7][24];
// Write a statement that uses the search function (see Exercise 7) to search the entire temperatures array for the value 32.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_ROWS 7
#define NUM_COLS 24

bool search_temp (int *temp_ptr, int row_size, int col_size, int temp_key);

int main (void) {

  int temperature[NUM_ROWS][NUM_COLS];
  int *temp_ptr = &temperature[0][0];
  int temp_key;
  bool is_temp_found = false;

  srand((unsigned int) time(NULL));

  // setup random temperature reading in the range of 0 to 100
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      temperature[i][j] = (rand() % 101);
    }
  }

  printf("Enter a temperature to search for: ");
  scanf("%d", &temp_key);
  
  printf("The temperature matrix is: \n");

  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%3d ", temperature[i][j]);
    }
    printf("\n");
  }

  is_temp_found = search_temp(temp_ptr, NUM_ROWS, NUM_COLS, temp_key);

  if (is_temp_found) {
    printf("%d is recorded.\n", temp_key);
  } else {
    printf("%d is not found.\n", temp_key);
  }

  return 0;
}

bool search_temp (int *tp, int rs, int cs, int tk) {
  int *temp = tp;
  for (; tp < temp + (rs * cs); tp++) {
    if (*tp == tk) {
      return true;
    }
  }
  return false;
}

