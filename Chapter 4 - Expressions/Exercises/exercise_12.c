// Q. Show the output produced by each of the following program fragments. Assume that i and j are int variables.
// a. i = 5;
//    j = ++i * 3 - 2;
//    printf("%d %d", i, j);
// Expectation: j = (++i) * 3 - 2 -> j = ((++i) * 3) - 2 -> j = (((++i) * 3) - 2) -> j = ((6 * 3) - 2) -> 16 -> i = 6, j = 16
// Actual: 6 16
// b. i = 5;
//    j = 3 - 2 * i++;
//    printf("%d %d", i, j);
// Expectation: j = 3 - 2 * (i++) -> j = 3 - (2 * (i++)) -> j = (3 - (2 * (i++))) -> j = (3 - (2 * 5)) -> j = (3 - 10) -> j = -7 -> i = 6, j = -7
// Actual: 6 -7
// c. i = 7;
//    j = 3 * i-- + 2;
//    printf("%d %d", i, j);
// Expectation: j = 3 * (i--) + 2 -> j = (3 * (i--)) + 2 -> j = ((3 * (i--)) + 2) -> j = ((3 * 7) + 2 -> j = (21 + 2) -> j = 23 -> i = 6, j = 23;
// Actual: 6 23
// d. i = 7;
//    j = 3 + --i * 2;
//    printf("%d %d", i, j);
// Expectation: j = 3 + (--i) * 2 -> j = 3 + ((--i) * 2) -> j = (3 + ((--i) * 2)) -> j = (3 + (6 * 2)) -> j = (3 + 12) -> j = 15 -> i = 6, j = 15
// Actual: 6 15

#include <stdio.h>

int main (void) {
    int i, j;

    i = 5;
    j = ++i * 3 - 2;
    printf("%d %d\n", i, j);

    i = 5;
    j = 3 - 2 * i++;
    printf("%d %d\n", i, j);

    i = 7;
    j = 3 * i-- + 2;
    printf("%d %d\n", i, j);

    i = 7;
    j = 3 + --i * 2;
    printf("%d %d\n", i, j);

    return 0;
}
