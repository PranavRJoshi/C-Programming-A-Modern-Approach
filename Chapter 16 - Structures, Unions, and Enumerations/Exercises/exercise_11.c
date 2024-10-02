// Q. Suppose that s is the following structure:
//    struct {
//      double a;
//      union {
//        char b[4];
//        double c;
//        int d;
//      } e;
//      char f[4];
//    } s;
// If char value occupies one byte, int values occupy four bytes, and double values occupy eight bytes, how much space will a C compiler allocate for s? (Assume that the compiler leaves no "holes" between members.)
//
// My answer: 
// Assuming that the compiler leaves no holes, the struct contains the following members:
//    1. A variable 'a' of type double.
//    2. A union 'e' consisting of members:
//        a. A character array of length 4.
//        b. A variable of type double.
//        c. A variable of type integer.
//    3. An array of characters 'f' of length 4.
// Based on this informations, we can say that the structure will have 8 bytes + max(4 bytes, 8 bytes, 4 bytes) + 4 * 1 bytes
// So, the structure will occupy a space of 20 bytes.

#include <stdio.h>

int main (void) {

  struct {
    double a;
    union {
      char b[4];
      double c;
      int d;
    } e;
    char f[4];
  } s;

  /* NOTE:  For my machine, it printed out 24, probably as the members should be 
   *        a multiple of 8. But without holes, the compiler should allocate 
   *        20 bytes for the structure defined above.
  */
  printf("[LOG] The size of the structure variable s of tag <anonymous> is: %zu\n", sizeof(s));

  return 0;
}

