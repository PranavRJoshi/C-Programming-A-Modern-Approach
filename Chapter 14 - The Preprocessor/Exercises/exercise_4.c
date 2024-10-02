// Q. For each of the following macros, give an example, that illustrates a problem with the macro and show how to fix it.
//    a. #define AVG(x, y) (x - y) / 2
//    b. #define AREA(x, y) (x) * (y)

// From initial inspection, in a,
// the flaw I can find is that when we invoke AVG as AVG(15 - 6 + 3, 9 + 12 * 10), the following expansion would take place:
// NOTE: The operators +, -, *, and / are all left associative, so when we encounter an expression that has operator of similar precedence, the associativity comes into play
//  -> (15 - 6 + 3 - 9 + 12 * 10) / 2 ---> (15 - 6 + 3 - 9 + 120) / 2 ---> (9 + 3 - 9 + 120) / 2 ---> (12 - 9 + 120) / 2 ---> (3 + 120) / 2 ---> 123 / 2 ---> 61
// The right answer should be:
//  -> ((15 - 6 + 3) - (9 + 1$ * 10)) / 2 ---> (12 - 129) / 2 ---> -117 / 2 ---> 58
//
// For b,
// It seems like when we normally invoke AREA, there will be no error, but say that we define another macro called VOLUME that has the form:
// #define VOLUME(x, y, z) AREA(x, y) * z
// Now say that we invoke VOLUME by passing it the parameters as:
//  -> VOLUME(12 + 3 * 6, 45 / 6 + 63, 13 * 43 / 12)
//  -> AREA(12 + 3 * 6, 45 / 6 + 63) * 13 * 43 / 12)
//  -> (12 + 3 * 6) * (45 / 6 + 43) * 13 * 43 / 12 ---> (30) * (50) * 13 * 3 ---> ...
//
// Another one that is described in the solution is the case when we invoke AREA as: 1 / AREA(1, 2) ---> 1 / 1 * 2 ---> 1 * 2 ---> 2 (wrong)

#include <stdio.h>

#define AVG(x, y) (x - y) / 2
#define AVG_FIXED(x, y) (((x) - (y)) / 2)

#define AREA(x, y) (x) * (y)
#define AREA_FIXED(x, y) ((x) * (y))

#define VOLUME(x, y, z) AREA(x, y) * z
#define VOLUME_FIXED(x, y, z) ((x) * (y) * (z))

int main (void) {

  int result = 0;

  result = AVG(15 - 6 + 3, 9 + 12 * 10);

  printf("[AVG TEST] The result of the macro invocation AVG(15 - 6 + 3, 9 + 12 * 10) is: %d\n", result);

  result = AVG_FIXED(15 - 6 + 3, 9 + 12 * 10);

  printf("[AVG_FIXED TEST] The result of the macro invocation AVG_FIXED(15 - 6 + 3, 9 + 12 * 10) is: %d\n", result);

  result = 1 / AREA(1, 2);

  printf("[AREA TEST] The result of the macro invocation 1 / AREA(1, 2) is: %d\n", result);

  result = 1 / AREA_FIXED(1, 2);

  printf("[AREA_FIXED TEST] The result of the macro invocation 1 / AREA_FIXED(1, 2) is: %d\n", result);

  result = VOLUME(12 + 3 * 6, 45 / 6 + 63, 13 * 43 / 12);

  printf("[VOLUME TEST] The result of the macro invocation VOLUME(12 + 3 * 6, 45 / 6 + 63, 13 * 43 / 12) is: %d\n", result);

  result = VOLUME_FIXED(12 + 3 * 6, 45 / 6 + 63, 13 * 43 / 12);

  printf("[VOLUME_FIXED TEST] The result of the macro invocation VOLUME_FIXED(12 + 3 * 6, 45 / 6 + 63, 13 * 43 / 12) is: %d\n", result);

  return 0;
}
