// Q. Show that output produced by each of the following program fragments. Assume that i and j are int variables.
// a. i = 6;
//    j = i += i;
//    printf("%d %d", i, j);
// Expectation: j = (i += i) -> j = (i = i + i) -> (j = (i = 12)) -> j = 12 -> i = 12, j = 12
// Actual: i = 12, j = 12
// b. i = 5;
//    j = (i -= 2) + 1;
//    printf("%d %d", i, j);
// Expectation: j = ((i -= 2) + 1) -> j = ((i = i - 2) + 1) -> j = ((i = 3) + 1) -> j = 4 -> i = 3, j = 4
// Actual: i = 3, j = 4
// c. i = 7;
//    j = 6 + (i = 2.5);
//    printf("%d %d", i, j);
// Expectation: j = (6 + (i = 2.5)) -> j = 8.5 but since j is int, j = 8 and same for i, i.e. i = 2 -> i = 2, j = 8
// Actual: i = 2, j = 8 (Also got the warning: implicit conversion from 'double' to 'int' changes value from 2.5 to 2 [-Wliteral-conversion])
// d. i = 2; j = 8;
//    j = (i = 6) + (j = 3);
//    printf("%d %d", i, j);
// Expectation: j = ((i = 6) + (j = 3)) -> j = (6 + 3) = 9 -> i = 6, j = 9 or 3. The value of j is assigned twice in the same statement, so it mostly depends on the compiler to assign the actual value for j.
// Actual: i = 6, j = 9 (Also got the warning: multiple unsequenced modifications to 'j' [-Wunsequenced])

#include <stdio.h>

int main (void) {
    int i, j;

    i = 6;
    j = i += i;
    printf("%d %d\n", i, j);

    i = 5;
    j = (i -= 2) + 1;
    printf("%d %d\n", i, j);

    i = 7;
    j = 6 + (i = 2.5);
    printf("%d %d\n", i, j);

    i = 2; j = 8;
    j = (i = 6) + (j = 3);
    printf("%d %d\n", i, j);

    return 0;
}
