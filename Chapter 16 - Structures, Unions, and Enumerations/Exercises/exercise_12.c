// Q. Suppose that u is the following union:
//    union {
//      double a;
//      struct {
//        char b[4];
//        double c;
//        int d;
//      } e;
//      char f[4];
//    } u;
// If char values occupy one byte, int values occupy four bytes, and double values occupy eight bytes, how much space will a C compiler allocate for u? (Assume that the compiler leaves no "holes" between members.)
//
// My Answer:
//    The following members are present in the union. NOTE: union will hold the member that allocates the largest size. The following members are present in the union u:
//      1. A variable 'a' of type double.
//      2. A structure variable 'e' consisting of members:
//          a. An array of characters of length 4.
//          b. A variable of type double.
//          c. A variable of type integer.
//      3. An array of characters 'f' of length 4.
//    So, the space allocation for 1 is 8 bytes, 2 is--assuming that the compiler leaves no holes--(4 * 1 bytes + 8 bytes + 4 bytes = 16 bytes), 3 is 4 * 1 bytes = 4 bytes.
//    As union will hold the max of the size of members, the space allocation for the union 'u' is: max(8 bytes, 16 bytes, 4 bytes) = 16 bytes.
// NOTE: Based on the previous question, it seems as if the compiler will allocate space in multiple of 8, so, it is possible that the result obtained will be 24 bytes instead, considering the "holes" that will be added after compilation.
// NOTE: When the member c is removed from the struct variable e, the compiler instead allocates a space of 8 bytes.

#include <stdio.h>

int main (void) {

  union {
    double a;
    struct {
      char b[4];
      double c;
      int d;
    } e;
    char f[4];
  } u;

  printf("[LOG] The size of the union variable u is: %zu\n", sizeof(u));

  return 0;
}

