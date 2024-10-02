// Q. The following program fragments illustrate the logical operators. Show the output produced by each, assuming that i, j, and k are int variables.
// a. i = 10; j = 5;
//    printf("%d", !i < j);
// Expectation: ((!i) < j) -> ((!10) < 5) -> 0 < 5 -> 1
// Actual: 1
// b. i = 2; j = 1;
//    printf("%d", !!i + !j);
// Expectation: ((!(!i)) + (!j)) ->  ((!(!2)) + (!1)) -> ((!0) + 0) -> (1 + 0) -> 1
// Actual: 1
// c. i = 5; j = 0; k = -5;
//    printf("%d", i && j || k);
// Expectation: ((i && j) || k) -> ((5 && 0) || k) -> (0 || -5) -> 1
// Actual: 1
// d. i = 1; j = 2; k = 3;
//    printf("%d", i < j || k);
// Expectation: ((i < j) || k) -> ((1 < 2) || k) -> (1 || 3) -> 1
// Actual: 1

#include <stdio.h>

int main (void) {

    int i, j, k;

    i = 10; j = 5;
    printf("%d\n", !i < j);

    i = 2; j = 1;
    printf("%d\n", !!i + !j);

    i = 5; j = 0; k = -5;
    printf("%d\n", i && j || k);

    i = 1; j = 2; k = 3;
    printf("%d\n", i < j || k);

    return 0;
}
