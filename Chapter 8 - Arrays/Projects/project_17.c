// Q. Write a program that prints an n x n magic square (a square arrangement of the numbers 1, 2, ..., n*n in which the sums of the rows, columns, and diagonals are all the same). The user will specify the value of n:
//    This program creates a magic square of a specified size.
//    The size must be an odd number between 1 and 99.
//    Enter size of magic square: 5
//    17  24   1   8  15
//    23   5   7  14  16
//    4    6  13  20  22
//    10  12  19  21   3
//    11  18  25   2   9
// Store the magic square in a two dimensional array. Start by placing the number 1 in the middle or row 0. Place each of the remaining numbers 2, 3, ..., n*n by moving up one row and over one column. Any attempt to go outside the bounds of the array should "wrap around" to the opposite side of the array. For example, instead of storing the next number in row -1, we would store it in row n - 1 (the last row). Instead of storing the next number in column n, we would store it in column 0. If a particular array element is already occupied, put the number directly below the previously stored number. If your compiler supports variable length arrays, declare the array to have n rows and n columns. If not, declare the array to have 99 rows and 99 columns.

#include <stdio.h>
#include <stdbool.h>

int main (void) {

  int square_size;
  int current_row = 0;
  int current_col = 0;

  // keep track of when wrapping takes place, i.e., when the current_row or current_col goes out of bound of array's max/min index
  bool is_wrapped_col = false;
  bool is_wrapped_row = false;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  
  for (;;) {
    printf("Enter size of magic square: ");
    scanf("%d", &square_size);
    if (square_size > 0 && (square_size % 2) != 0) {
      break;
    }
  }

  // declare the Variable Length Array (VLA)
  int magic_square[square_size][square_size];

  // initialize the magic_square two-dimensional array with an initial value of 0
  for (int i = 0; i < square_size; i++) {
    for (int j = 0; j < square_size; j++) {
      magic_square[i][j] = 0;
    }
  }

  // this for loop is used for adding the digit in the magic square
  for (int i = 0; i < square_size * square_size; i++) {
    // initialize the first number inside the two-dimensional array as described in the question and skip the loop body
    if (i == 0) {
      current_col = (square_size / 2);
      magic_square[current_row][current_col] = i+1;
      continue;
    }

    // the code below starts for i > 0, so after the first number has been added
    // moves upward and in the right direction
    current_row = current_row - 1;
    current_col = current_col + 1;

    // [edge case] when the row is negative or outside the array's indexing
    // wrap around the last row of the array and set is_wrapped_row
    if (current_row < 0) {
      current_row = square_size - 1;
      is_wrapped_row = true;
    }

    // [edge case] when the col is greater than (which shouldn't happen) or equal to square_size (which is also out of bound since array starts at 0 and ends at square_size - 1
    // wrap around the first col of the array and set is_wrapped_col
    if (current_col >= square_size) {
      current_col = 0;
      is_wrapped_col = true;
    }

    // when the current position already has a number assigned to it
    if (magic_square[current_row][current_col] != 0) {
      // checks if the row wrapping was done, if so, then we need to revert back to the un-wrapped row position
      // else just move downward (reverting the expression current_row = current_row - 1)
      if (is_wrapped_row) {
        current_row = 0;
      } else {
        current_row = current_row + 1;
      }

      // checks if the col wrapping was done, if so, then we need to revert back to the un-wrapped col position
      // else just move to the left (reverting the expression current_col = current_col + 1)
      if (is_wrapped_col) {
        current_col = square_size - 1;
      } else {
        current_col = current_col - 1;
      }
      
      // go below the unmodified current location
      current_row += 1;
    }

    // add the number to the suitable position
    magic_square[current_row][current_col] = i+1;
    // revert the bool values to ensure the nested if-block above does not execute all the time.
    is_wrapped_row = false;
    is_wrapped_col = false;
  }

  for (int i = 0; i < square_size; i++) {
    for (int j = 0; j < square_size; j++) {
      printf("%2d ", magic_square[i][j]);
    }
    printf("\n");
  }

  return 0;
}

