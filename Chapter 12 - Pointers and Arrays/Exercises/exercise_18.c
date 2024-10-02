// Q. Write the evaluate_position function described in Exercise 13 of Chapter 9. Use pointer arithmetic--not subscripting--to visit array elements. Use a single loop instead of nested loops.

#include <stdio.h>

#define LEN 8

int evaluate_position (const char *board);

int main (void) {

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

  evaluation = evaluate_position(&board[0][0]);

  printf("The board evaluation is: %d\n", evaluation);

  return 0;
}

int evaluate_position (const char *b) {
  int white_evaluation = 0;
  int black_evaluation = 0;
  int rs = LEN;
  int cs = LEN;

  while (rs > 0) {
    while (cs > 0) {
      switch (*b++) {
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
      cs--;
    }
    cs = LEN;
    rs--;
  }

  return white_evaluation - black_evaluation;
}


