// Q. Suppose that b and i are declared as follows: 
//      enum { FALSE, TRUE } b;
//      int i;
//    Which of the following statements are legal? Which ones are "safe" (always yield a meaningful result)?
//      a. b = FALSE;
//      b. b = i;
//      c. b++;
//      d. i = b;
//      e. i = 2 * b + 1;
// My Answer:
//  a. Legal. The statement assigns the enumeration constant to the variable b--of type enum <anonymous>.
//  b. Legal but not safe. i can be any integer, and if i contains an integer which none of the enumeration constant holds, we might have some problems. Like, We might be iterating the variable b over to check for a certain enumeration constant, but end up not getting any result.
//  c. Legal but not safe. Enumeration might go out of bound.
//  d. Legal. The statement assigns the integers that represents the enumeration constant stored in b.
//  e. Legal. The statement results in 2 * (integer constant represented by the enumeration constant on b) + 1

#include <stdio.h>

int main (void) {

  enum { FALSE, TRUE } b;
  int i = 10;

  b = FALSE;
  // b = i;
  b++;
  printf("b contains: %d\n", b);

  if (b == TRUE || b == FALSE) {
    printf("[LOG 1] b still contains an enumeration.\n");
  } else {
    printf("[LOG 1] b does not contain an enumeration.\n");
  }

  b++;
  printf("b contains: %d\n", b);

  if (b == TRUE || b == FALSE) {
    printf("[LOG 2] b still contains an enumeration constant.\n");
  } else {
    printf("[LOG 2] b does not contain an enumeration constant.\n");
  }

  i = 2 * b + 1;
  b++;

  if (b == TRUE || b == FALSE) {
    printf("[LOG 2] b still contains an enumeration constant.\n");
  } else {
    printf("[LOG 2] b does not contain an enumeration constant.\n");
  }

  printf("b contains: %d\n", b);
  printf("i contains: %d\n", i);

  return 0;
}

