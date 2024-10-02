// Q. Show the output produced by each of the following program fragments. Assume that i, j, and k are int variables.
// a. i = 5; j = 3;
//    printf("%d %d", i / j, i % j); // Expected: 1 2 // Actual: 1 2
// b. i = 2; j = 3;
//    printf("%d", (i + 10) % j); // Expected: (2 + 10) % 3 -> 0 // Actual: 0
// c. i = 7; j = 8; k = 9;
//    printf("%d", (i + 10) % k / j); // Expected: (((7 + 10) % 9) / 8) -> 8 / 8 -> 1 // Actual: 1
// d. i = 1; j = 2; k = 3;
//    printf("%d", (i + 5) % (j + 2) / k); // Expected: (((1 + 5) % (2 + 2)) / 3) -> 2 / 3 -> 0 // Actual: 0

#include <stdio.h>

int main (void) {
    int i = 5, j = 3;
    printf("%d %d\n", i / j, i % j);

    i = 2; j = 3;
    printf("%d\n", (i + 10) % j);

    i = 7; j = 8;
    int k = 9;
    printf("%d\n", (i + 10) % k / j);

    i = 1; j = 2; k = 3;
    printf("%d\n", (i + 5) % (j + 2) / k);

    return 0;
}
