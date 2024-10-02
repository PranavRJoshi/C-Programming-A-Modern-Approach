// Q. (a) Each square of a chessboard can hold one piece--a pawn, knight, bishop, rook, queen, or king--or it may be empty. Each piece is either black or white. Define two enumerated types: Piece, which has seven possible values (one of which is "empty"), and Color, which has two. 
//    (b) Using the types from part (a), define a structure type named Square that can store both the types of a piece and its color.
//    (c) Using the Square type from part (b), declare an 8 x 8 array named board that can store the entire contents of a chessboard.
//    (d) Add an initializer to the declaration in part (c) so that board's initial value corresponds to the usual arrangement of pieces at the start of a chess game. A square that's not occupied by a piece should have an "empty" piece value and the color black.

#include <stdio.h>

int main (void) {


  enum Piece { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, EMPTY };
  enum Color { BLACK, WHITE };

  struct Square {
    enum Piece piece;
    enum Color color;
  };

  struct Square board[8][8] = { [0][0].piece = ROOK,    [0][0].color = WHITE, [0][1].piece = KNIGHT,  [0][1].color = WHITE,
                                [0][2].piece = BISHOP,  [0][2].color = WHITE, [0][3].piece = QUEEN,   [0][3].color = WHITE,
                                [0][4].piece = KING,    [0][4].color = WHITE, [0][5].piece = BISHOP,  [0][5].color = WHITE,
                                [0][6].piece = KNIGHT,  [0][6].color = WHITE, [0][7].piece = ROOK,    [0][7].color = WHITE,
                                [1][0].piece = PAWN,    [1][0].color = WHITE, [1][1].piece = PAWN,    [1][1].color = WHITE, 
                                [1][2].piece = PAWN,    [1][2].color = WHITE, [1][3].piece = PAWN,    [1][3].color = WHITE,
                                [1][4].piece = PAWN,    [1][4].color = WHITE, [1][5].piece = PAWN,    [1][5].color = WHITE, 
                                [1][6].piece = PAWN,    [1][6].color = WHITE, [1][7].piece = PAWN,    [1][7].color = WHITE,
                                [2][0].piece = EMPTY,   [2][0].color = BLACK, [2][1].piece = EMPTY,   [2][1].color = BLACK, 
                                [2][2].piece = EMPTY,   [2][2].color = BLACK, [2][3].piece = EMPTY,   [2][3].color = BLACK, 
                                [2][4].piece = EMPTY,   [2][4].color = BLACK, [2][5].piece = EMPTY,   [2][5].color = BLACK, 
                                [2][6].piece = EMPTY,   [2][6].color = BLACK, [2][7].piece = EMPTY,   [2][7].color = BLACK,
                                [3][0].piece = EMPTY,   [3][0].color = BLACK, [3][1].piece = EMPTY,   [3][1].color = BLACK, 
                                [3][2].piece = EMPTY,   [3][2].color = BLACK, [3][3].piece = EMPTY,   [3][3].color = BLACK, 
                                [3][4].piece = EMPTY,   [3][4].color = BLACK, [3][5].piece = EMPTY,   [3][5].color = BLACK, 
                                [3][6].piece = EMPTY,   [3][6].color = BLACK, [3][7].piece = EMPTY,   [3][7].color = BLACK,
                                [4][0].piece = EMPTY,   [4][0].color = BLACK, [4][1].piece = EMPTY,   [4][1].color = BLACK, 
                                [4][2].piece = EMPTY,   [4][2].color = BLACK, [4][3].piece = EMPTY,   [4][3].color = BLACK, 
                                [4][4].piece = EMPTY,   [4][4].color = BLACK, [4][5].piece = EMPTY,   [4][5].color = BLACK, 
                                [4][6].piece = EMPTY,   [4][6].color = BLACK, [4][7].piece = EMPTY,   [4][7].color = BLACK,
                                [5][0].piece = EMPTY,   [5][0].color = BLACK, [5][1].piece = EMPTY,   [5][1].color = BLACK, 
                                [5][2].piece = EMPTY,   [5][2].color = BLACK, [5][3].piece = EMPTY,   [5][3].color = BLACK, 
                                [5][4].piece = EMPTY,   [5][4].color = BLACK, [5][5].piece = EMPTY,   [5][5].color = BLACK, 
                                [5][6].piece = EMPTY,   [5][6].color = BLACK, [5][7].piece = EMPTY,   [5][7].color = BLACK,
                                [6][0].piece = PAWN,    [6][0].color = BLACK, [6][1].piece = PAWN,    [6][1].color = BLACK, 
                                [6][2].piece = PAWN,    [6][2].color = BLACK, [6][3].piece = PAWN,    [6][3].color = BLACK,
                                [6][4].piece = PAWN,    [6][4].color = BLACK, [6][5].piece = PAWN,    [6][5].color = BLACK, 
                                [6][6].piece = PAWN,    [6][6].color = BLACK, [6][7].piece = PAWN,    [6][7].color = BLACK,
                                [7][0].piece = ROOK,    [7][0].color = BLACK, [7][1].piece = KNIGHT,  [7][1].color = BLACK,
                                [7][2].piece = BISHOP,  [7][2].color = BLACK, [7][3].piece = QUEEN,   [7][3].color = BLACK,
                                [7][4].piece = KING,    [7][4].color = BLACK, [7][5].piece = BISHOP,  [7][5].color = BLACK,
                                [7][6].piece = KNIGHT,  [7][6].color = BLACK, [7][7].piece = ROOK,    [7][7].color = BLACK,
                                
  };

  struct Square new_board[] = { {ROOK, WHITE},  {KNIGHT, WHITE},  {BISHOP, WHITE},  {QUEEN, WHITE},
                                {KING, WHITE},  {BISHOP, WHITE},  {KNIGHT, WHITE},  {ROOK, WHITE},
                                {PAWN, WHITE},  {PAWN, WHITE},    {PAWN, WHITE},    {PAWN, WHITE}, 
                                {PAWN, WHITE},  {PAWN, WHITE},    {PAWN, WHITE},    {PAWN, WHITE}, 
                                {EMPTY, BLACK}, {EMPTY, BLACK},   {EMPTY, BLACK},   {EMPTY, BLACK}, 
                                {EMPTY, BLACK}, {EMPTY, BLACK},   {EMPTY, BLACK},   {EMPTY, BLACK}, 
                                {EMPTY, BLACK}, {EMPTY, BLACK},   {EMPTY, BLACK},   {EMPTY, BLACK}, 
                                {EMPTY, BLACK}, {EMPTY, BLACK},   {EMPTY, BLACK},   {EMPTY, BLACK}, 
                                {EMPTY, BLACK}, {EMPTY, BLACK},   {EMPTY, BLACK},   {EMPTY, BLACK}, 
                                {EMPTY, BLACK}, {EMPTY, BLACK},   {EMPTY, BLACK},   {EMPTY, BLACK}, 
                                {EMPTY, BLACK}, {EMPTY, BLACK},   {EMPTY, BLACK},   {EMPTY, BLACK}, 
                                {EMPTY, BLACK}, {EMPTY, BLACK},   {EMPTY, BLACK},   {EMPTY, BLACK}, 
                                {PAWN, BLACK},  {PAWN, BLACK},    {PAWN, BLACK},    {PAWN, BLACK}, 
                                {PAWN, BLACK},  {PAWN, BLACK},    {PAWN, BLACK},    {PAWN, BLACK}, 
                                {ROOK, BLACK},  {KNIGHT, BLACK},  {BISHOP, BLACK},  {QUEEN, BLACK},
                                {KING, BLACK},  {BISHOP, BLACK},  {KNIGHT, BLACK},  {ROOK, BLACK} };

  printf("For the board variable: \n");
  for (int i = 0; i < (int) (sizeof(board) / sizeof(board[0])); i++) {
    for (int j = 0; j < (int) (sizeof(board[0]) / (sizeof(board[0][0]))); j++) {
      if (board[i][j].color == WHITE && board[i][j].piece != EMPTY) {
        printf("White piece\t");
      }
      if (board[i][j].color == BLACK && board[i][j].piece != EMPTY) {
        printf("Black piece\t");
      }
    }
    printf("\n");
  }

  printf("For the new_board variable: \n");
  for (int i = 0; i < (int) (sizeof(new_board) / sizeof(new_board[0])); i++) {
    if (new_board[i].color == WHITE && new_board[i].piece != EMPTY) {
      printf("Array index %d has a White piece\n", i);
    }
    if (new_board[i].color == BLACK && new_board[i].piece != EMPTY) {
      printf("Array index %d has a Black piece\n", i);
    }
  }

  return 0;
}

