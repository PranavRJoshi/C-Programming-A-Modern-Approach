// Q. Write a declaration for an 8 x 8 char array named chess_board. Include an initializer that puts the following data into the array (one character per array element):
//    r n b q k b n r
//    p p p p p p p p
//      .   .   .   .
//    .   .   .   . 
//      .   .   .   .
//    .   .   .   .  
//    P P P P P P P P
//    R N B Q K B N R

#include <stdio.h>

#define OUTER_SIZE (int) (sizeof(chess_board) / sizeof(chess_board[0]))
#define INNER_SIZE (int) (sizeof(chess_board[0]) / sizeof(chess_board[0][0]))

int main (void) {

  char chess_board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

  for (int i = 0; i < OUTER_SIZE; i++) {
    for (int j = 0; j < INNER_SIZE; j++) {
      printf("%c ", chess_board[i][j]);
    }
    printf("\n");
  }

  return 0;
}
