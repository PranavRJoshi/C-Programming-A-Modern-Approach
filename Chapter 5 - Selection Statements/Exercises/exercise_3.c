// Q. The following program fragments illustrate the short-circuit behavior of logical expressions. Show the output produced by each, assuming that i, j, and k are int variables.
// a. i = 3; j = 4; k = 5;
//    printf("%d ", i < j || ++j < k);
//    printf("%d %d %d", i, j, k);
// Expectation: ((i < j) || ((++j) < k)) -> ((3 < 4) || ((++j) < k)) -> (1 || ((++j) < k)) -> 1 (since (1 (or any non-zero number) || anything) is 1) -> 1 3 4 5
// Actual: 1 3 4 5
// b. i = 7; j = 8; k = 9;
//    printf("%d ", i - 7 && j++ < k);
//    printf("%d %d %d", i, j, k);
// Expectation: ((i - 7) && ((j++) < k)) -> ((7 - 7) && ((j++) < k)) -> (0 && ((j++) < k)) -> 0 (since (0 && anything) is 0) -> 
// Actual: 0 7 8 9
// c. i = 7; j = 8; k = 9;
//    printf("%d ", (i = j) || (j = k));
//    printf("%d %d %d", i, j, k);
// Expectation: ((i = j) || (j = k)) -> ((i = 8) || (j = k)) -> (8 || (j = k)) -> 1 -> 1 8 8 9
// Actual: 1 8 8 9
// d. i = 1; j = 1; k = 1;
//    printf("%d ", ++i || ++j && ++k);
//    printf("%d %d %d", i, j, k);
// Expectation: (((++i) || (++j)) && (++k)) -> (((2) || (++j)) && (++k)) -> (1 && (++k)) -> (1 && 2) -> 1 -> 1 2 1 2 // Mistake: && has higher precedance than ||, so the correct way to paranthesize the expression is ((++i) || ((++j) && (++k)))
// Actual: 1 2 1 1

#include <stdio.h>

int main (void) {

    int i, j, k;

    i = 3; j = 4; k = 5;
    printf("%d ", i < j || ++j < k);
    printf("%d %d %d\n", i, j, k);

    i = 7; j = 8; k = 9;
    printf("%d ", i - 7 && j++ < k);
    printf("%d %d %d\n", i, j, k);

    i = 7; j = 8; k = 9;
    printf("%d ", (i = j) || (j = k));
    printf("%d %d %d\n", i, j, k);

    i = 1; j = 1; k = 1;
    printf("%d ", ++i || ++j && ++k);
    printf("%d %d %d\n", i, j, k);

    return 0;
}
