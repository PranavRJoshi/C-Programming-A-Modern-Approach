// Q. Modify Programming Project 17 from Chapter 8 so that it includes the following functions:
//    void create_magic_square (int n, char magic_square[n][n]);
//    void print_magic_square (int n, char magic_square[n][n]);
// After obtaining the number n from the user, main will call create_magic_square, passing it an n*n array that is declared inside main. create_magic_square will fill the array with the numbers 1, 2, ..., n*n as described in the original project. main will then call print_magic_square, which will display the array in the format described in the original project. Note: If your compiler doesn't support variable-length arrays, declare the array in main to be 99 * 99 instead of n * n and use the following prototypes instead:
//    void create_magic_square (int n, char magic_square[99][99]);
//    void print_magic_square (int n, char magic_square[99][99]);

// using the char type for the multidimensional array has some limitation
// mainly, how do i assing two digit number as an array element?
// For this reason, i'll be using the type int instead of char

#include <stdio.h>
#include <stdbool.h>

void create_magic_square (int n, int magic_square[n][n]);
void print_magic_square (int n, int magic_square[n][n]);

int main (void) {

  int square_size = 0;

  for (;;) {
    printf("Enter size of magic square: ");
    scanf("%d", &square_size);
    if (square_size > 0 && (square_size % 2) != 0) {
      break;
    }
  }

  int magic_square[square_size][square_size];

  for (int i = 0; i < square_size; i++) {
    for (int j = 0; j < square_size; j++) {
      magic_square[i][j] = 0;
    }
  }

  // the working process is documented in the Programming Project 17 from Chapter 8
  // removed here to not have many comments
  create_magic_square(square_size, magic_square);

  print_magic_square(square_size, magic_square);

  return 0;
}

void create_magic_square (int n, int ms[n][n]) {

  int current_row = 0;
  int current_col = 0;

  bool is_wrapped_col = false;
  bool is_wrapped_row = false;
  
  for (int i = 0; i < n * n; i++) {
    if (i == 0) {
      current_col = (n / 2);
      ms[current_row][current_col] = i+1;
      continue;
    }

    current_row = current_row - 1;
    current_col = current_col + 1;

    if (current_row < 0) {
      current_row = n - 1;
      is_wrapped_row = true;
    }

    if (current_col >= n) {
      current_col = 0;
      is_wrapped_col = true;
    }

    if (ms[current_row][current_col] != 0) {
      if (is_wrapped_row) {
        current_row = 0;
      } else {
        current_row = current_row + 1;
      }

      if (is_wrapped_col) {
        current_col = n - 1;
      } else {
        current_col = current_col - 1;
      }
      
      current_row += 1;
    }

    ms[current_row][current_col] = i+1;

    is_wrapped_row = false;
    is_wrapped_col = false;
  }
}

void print_magic_square (int n, int ms[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%2d ", ms[i][j]);
    }
    printf("\n");
  }
}
