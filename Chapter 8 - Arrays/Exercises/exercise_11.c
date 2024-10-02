// Q. Write a program fragment that declares an 8 x 8 char array named checker_board and then uses a loop to store the following data into the array (one character per array element):
//    B R B R B R B R
//    R B R B R B R B
//    B R B R B R B R
//    R B R B R B R B
//    B R B R B R B R
//    R B R B R B R B
//    B R B R B R B R
//    R B R B R B R B
// Hint: The element in row i, column j, should be the letter B if i + j is an even number.

#include <stdio.h>

#define OUTER_SIZE (int) (sizeof(checker_board) / sizeof(checker_board[0]))
#define INNER_SIZE (int) (sizeof(checker_board[0]) / sizeof(checker_board[0][0]))

int main (void) {

  char checker_board[8][8];
  
  for (int i = 0; i < OUTER_SIZE; i++) {
    for (int j = 0; j < INNER_SIZE; j++) {
      if ((i + j) % 2 == 0) {
        checker_board[i][j] = 'B';
      } else {
        checker_board[i][j] = 'R';
      }
    }
  }

  for (int i = 0; i < OUTER_SIZE; i++) {
    for (int j = 0; j < INNER_SIZE; j++) {
      printf("%c ", checker_board[i][j]);
    }
    printf("\n");
  }

  return 0;
}

