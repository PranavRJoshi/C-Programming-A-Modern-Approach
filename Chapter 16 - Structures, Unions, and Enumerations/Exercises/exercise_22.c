// Q. Let chess_pieces be the following enumeration:
//    enum chess_pieces { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };
//
//    a.  Write a declaration (including an initializer) for a constant array of integers named piece_value that stores the numbers 200, 9, 5, 3, 3, and 1, representing the value of each chess piece, from king to pawn. (The king's value is actually infinite, since "capturing" the king (checkmate) ends the game, but some chess-playing software assigns the king a large value such as 200.)
//    b. (C99) Repeat part (a), but use a designated initializer to initialize the array. Use the enumeration constants in chess_pieces as subscripts in the designators. (Hint: See the last question in Q&A for an example.)

#include <stdio.h>
#include <stdlib.h>

int main (void) {

  enum chess_pieces { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

  const int chess_pieces[] = { 200, 9, 5, 3, 3, 1 };

  const int chess_pieces_c99[] = {  [KING]    = 200,
                                    [QUEEN]   = 9,
                                    [ROOK]    = 5,
                                    [BISHOP]  = 3,
                                    [KNIGHT]  = 3,
                                    [PAWN]    = 1  };

  printf("The contents of constant integer variable chess_pieces is: \n");
  for (int i = 0; i < (int) (sizeof(chess_pieces) / sizeof(chess_pieces[0])); i++) {
    printf("Index %d: %d\n", i, chess_pieces[i]);
  }

  printf("\n\n");

  enum chess_pieces c1 = KING, c2 = PAWN;

  printf("The contents of constant integer variable chess_pieces_c99 is: \n");
  while (c1 <= c2) {
    switch (c1) {
      case KING:
        printf("KING: %d\n", chess_pieces_c99[c1]);
        c1++;
        break;
      case QUEEN:
        printf("QUEEN: %d\n", chess_pieces_c99[c1]);
        c1++;
        break;
      case ROOK:
        printf("ROOK: %d\n", chess_pieces_c99[c1]);
        c1++;
        break;
      case BISHOP:
        printf("BISHOP: %d\n", chess_pieces_c99[c1]);
        c1++;
        break;
      case KNIGHT:
        printf("KNIGHT: %d\n", chess_pieces_c99[c1]);
        c1++;
        break;
      case PAWN:
        printf("PAWN: %d\n", chess_pieces_c99[c1]);
        c1++;
        break;
      default:
        fprintf(stderr, "[FATAL ERROR] Enumeration Variable Contains Out-Of-Bound Value.\n");
        exit(EXIT_FAILURE);
    }
  }

  printf("\n\n");

  return 0;
}

