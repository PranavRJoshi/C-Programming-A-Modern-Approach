// Q. In the following declarations, the x and y structures have members named x and y:
//    struct { int x, y; } x;
//    struct { int x, y; } y;
// Are these declarations legal on an individual basis? Could both declarations appear as shown in a program? Justify your answer.
//
// My Answer:
//    Yes, the declarations are indeed legal. As seen in #8 of Chapter's Notes, we can declares structures as described in the question. One thing that seems like a minor inconvenience is that structure x and structure y are not considered as the same by the compiler, i.e. we can't assign the struct x to struct y and vice versa.

#include <stdio.h>

int main (void) {

  struct {
    int x, y;
  } x;

  struct {
    int x, y;
  } y;

  x.x = 1;
  x.y = 2;

  y.x = 3;
  y.y = 4;

  // Illegal operation(s)
  // x = y;
  // y = x;

  printf("The structure x has the members x and y whose values are %d and %d respectively.\n", x.x, x.y);     /* Prints 1 and 2 */
  printf("The structure y has the members x and y whose values are %d and %d respectively.\n", y.x, y.y);     /* Prints 3 and 4 */

  return 0;
}
