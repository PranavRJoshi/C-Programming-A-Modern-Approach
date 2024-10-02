// Q. Which of the following statements aboue enumeration constants are true?
//    a. An enumeration constant may represent any integers specified by the programmer.
//    b. Enumeration constants have exactly the same properties as constants created using #define.
//    c. Enumeration constants have the values 0, 1, 2, ... by default.
//    d. All constants in an enumeration must have different values.
//    e. Enumeration constants may be used as integers in expression.
//
// My Answer:
//  a. True. We must declare enumeration constant and initialize it if necessary:
//      enum { SPADES = 10, DIAMONDS = 20, HEARTS = 30, CLUBS = 40 } s1, s2;
//  b. False. Enumeration constants must follow the C's block scope, i.e. enumeration defined inside a block won't be visible outside the block.
//  c. True. Enumerations constants have 0, 1, 2, ... as the default value, but can be changed like:
//      enum { VAR_1, VAR_2 = 10, VAR_3, VAR_4 = 20 } var;  /* VAR_1 = 0, VAR_2 = 10, VAR_3 = 11, VAR_4 = 20 */
//  d. False. Enumeration constants can contain the same integer constant:
//      enum { NUM_1 = 15, NUM_2 = 30, NUM_3 = 15, NUM_4 } num;   /* NUM_1 = 15, NUM_2 = 30, NUM_3 = 15, NUM_4 = 16 */
//  e. True. We can use the enumeration constants defined in an expression:
//      enum { SPADES = 10, DIAMONDS = 20, HEARTS = 30, CLUBS = 40 } s1, s2;
//      int i;
//      s1 = SPADES;
//      s2 = CLUBS;
//      i = s1 + s2;
//      if (i == 50 && (s1 == CLUBS || s1 == SPADES) && (s2 == SPADES || s2 == CLUBS)) {
//        printf("The selected card only consists of the color black\n");
//      } else if (i == 50 && (s1 == DIAMONDS || s1 == HEARTS) && (s2 == DIAMONDS || s2 == HEARTS)) {
//        printf("The selected card only consists of the color red\n");
//      } else {
//        printf("The selected cards consists of both color: black and red\n");
//      }

#include <stdio.h>

int main (void) {

  {
    enum { SPADES = 10, DIAMONDS = 20, HEARTS = 30, CLUBS = 40 } s1, s2;
    printf("The contents of enum defined in this block is: \n"                              \
           "SPADES:   %d\n"                                                                 \
           "DIAMONDS: %d\n"                                                                 \
           "HEARTS:   %d\n"                                                                 \
           "CLUBS:    %d\n", SPADES, DIAMONDS, HEARTS, CLUBS);
  }

  /* undeclared identifier */
  // printf("The enumeration constant SPADES contains the integer: %d\n", SPADES);
  
  {
    enum { VAR_1, VAR_2 = 10, VAR_3, VAR_4 = 20 } var;  /* VAR_1 = 0, VAR_2 = 10, VAR_3 = 11, VAR_4 = 20 */
    printf("The contents of enum defined in this block is: \n"                            \
           "VAR_1: %d\n"                                                                  \
           "VAR_2: %d\n"                                                                  \
           "VAR_3: %d\n"                                                                  \
           "VAR_4: %d\n", VAR_1, VAR_2, VAR_3, VAR_4);
  }

  {
    enum { NUM_1 = 15, NUM_2 = 30, NUM_3 = 15, NUM_4 } num;   /* NUM_1 = 15, NUM_2 = 30, NUM_3 = 15, NUM_4 = 16 */
    printf("The contents of enum defined in this block is: \n"                            \
           "NUM_1: %d\n"                                                                  \
           "NUM_2: %d\n"                                                                  \
           "NUM_3: %d\n"                                                                  \
           "NUM_4: %d\n", NUM_1, NUM_2, NUM_3, NUM_4);
  }

  {
    enum { SPADES = 10, DIAMONDS = 20, HEARTS = 30, CLUBS = 40 } s1, s2;
    int i;
    s1 = DIAMONDS;
    s2 = CLUBS;
    i = s1 + s2;
    if (i == 50 && (s1 == CLUBS || s1 == SPADES) && (s2 == SPADES || s2 == CLUBS)) {
      printf("The selected card only consists of the color black\n");
    } else if (i == 50 && (s1 == DIAMONDS || s1 == HEARTS) && (s2 == DIAMONDS || s2 == HEARTS)) {
      printf("The selected card only consists of the color red\n");
    } else {
      printf("The selected cards consists of both color: black and red\n");
    }
  }

  return 0;
}

