// Q. The following program fragments illustrate the relational and equality operators. Show the output produced by each, assuming that i, j, and k are int variables.
// a. i = 2; j = 3;
//    k = i * j == 6;
//    printf("%d", k);
// Expectation: k = ((i * j) == 6) -> k = ((2 * 3) == 6) -> k = (6 == 6) -> k = 1
// Actual: 1
// b. i = 5; j = 10; k = 1;
//    printf("%d", k > i < j);
// Expectation: ((k > i) < j) -> ((1 > 5) < j) -> (0 < 10) -> 1
// Actual: 1
// c. i = 3; j = 2; k = 1;
//    printf("%d", i < j == j < k);
// Expectation: ((i < j) == (j < k)) -> ((3 < 2) == (2 < 1)) -> (0 == 0) -> 1
// Actual: 1
// d. i = 3; j = 4; k = 5;
//    printf("%d", i % j + 1 < k);
// Expectation: (((i % j) + 1) < k) -> (((3 % 4) + 1) < k) -> ((0 + 1) < k) -> (1 < 5) -> 1
// Actual: 1

#include <stdio.h>

int main (void) {
    
    int i, j, k;

    i = 2; j = 3;
    k = i * j == 6;
    printf("%d\n", k);

    i = 5; j = 10; k = 1;
    printf("%d\n", k > i < j);

    i = 3; j = 2; k = 1;
    printf("%d\n", i < j == j < k);

    i = 3; j = 4; k = 5;
    printf("%d\n", i % j + 1 < k);

    return 0;
}
