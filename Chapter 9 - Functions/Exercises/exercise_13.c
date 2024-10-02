// Q. Write the following function, which evaluates a chess position:
//    int evaluate_position (char board[8][8]);
// board represents a configuration of pieces on a chessboard, where the letters K, Q, R, B, N, P represent White pieces, and the letters k, q, r, b, n, and p represent Black pieces. evaluate_position should sum the values of the White pieces (Q = 9, R = 5, B = 3, N = 3, P = 1). It should also sum the values of the Black pieces (done in a similar way). The function will return the difference between the two numbers. This value will be positive if White has an advantage in material and negative if Black has an advantage.

#include <stdio.h>

#define LEN 8

// it is not illegal to define the row length in the funtion prototype (see #67 of Chapter's notes)
// it essentially does not have any meaning, as the compiler doesn't know how many rows will the arrary board has
// but it is essential to provide the column length which helps calculate the row size of the array (see #68 of Chapter's notes)
int evaluate_position (char board[LEN][LEN]);

int main (void) {

  // this is the intial configuration (the evaluation will be 0)
  // if you want different result, change the configuration as needed
  char board[LEN][LEN] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                          {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                          {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                          {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

  int evaluation = 0;

  printf("The given configuration is: \n");

  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  evaluation = evaluate_position(board);

  printf("The board evaluation is: %d\n", evaluation);

  return 0;
}

int evaluate_position (char b[LEN][LEN]) {
  int white_evaluation = 0;
  int black_evaluation = 0;

  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      switch (b[i][j]) {
        case 'Q':
          white_evaluation += 9;
          break;
        case 'R':
          white_evaluation += 5;
          break;
        case 'B':
          white_evaluation += 3;
          break;
        case 'N':
          white_evaluation += 3;
          break;
        case 'P':
          white_evaluation += 1;
          break;
        case 'q':
          black_evaluation += 9;
          break;
        case 'r':
          black_evaluation += 5;
          break;
        case 'b':
          black_evaluation += 3;
          break;
        case 'n':
          black_evaluation += 3;
          break;
        case 'p':
          black_evaluation += 1;
          break;
        default:
          break;
      }
    }
  }
  return white_evaluation - black_evaluation;
}

