// Q. Repeat Exercise 3 for C99.
// From book: In C99, the result of division is always truncated towards zero. So -9/7 is -1 as it is more near to 0 than -2.
// Expectation: Since the value was in the range of either -1 or 1 using the C89 compiler, the values will be similar to C99 compiler as well(?)
// Actual Result: As expected, the values that were obtained were similar to the ones obtained using the C89 compiler.

#include <stdio.h>

int main (void) {
    int i = 8, j = 5;
    printf("(%d / %d) = %d\n", i, j, (i / j));

    i = -8, j = 5;
    printf("(%d / %d) = %d\n", i, j, (i / j));

    i = 8, j = -5;
    printf("(%d / %d) = %d\n", i, j, (i / j));

    i = -8, j = -5;
    printf("(%d / %d) = %d\n", i, j, (i / j));

    return 0;
}
