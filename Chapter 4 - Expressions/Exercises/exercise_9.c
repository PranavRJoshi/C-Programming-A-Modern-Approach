// Q. Show the output produced by each of the following program fragments. Assume that i, j, and k are int variables.
// a. i = 7; j = 8;
//    i *= j + 1;
//    printf("%d %d", i, j); 
// Expectation: i *= (j + 1) -> i = i * (j + 1) -> i = 7 * (8 + 1) -> i = 63, j = 8
// Actual: i = 63, j = 8
// b. i = j = k = 1;
//    i += j += k;
//    printf("%d %d %d", i, j, k);
// Expectation: i += (j += k) -> (i += (j += k)) -> (i += (j = j + k)) -> (i += (j = 2)) -> (i = i + j = 2) -> i = 3, j = 2, k = 1
// Actual: i = 3, j = 2, k = 1
// c. i = 1; j = 2; k = 3;
//    i -= j -= k;
//    printf("%d %d %d", i, j, k);
// Expectation: i -= (j -= k) -> (i -= (j -= k)) -> (i -= (j = j - k)) -> (i -= (j = -1)) -> (i = i - (j = -1)) -> i = 2, j = -1, k = 3
// Actual: i = 2, j = -1, k = 3
// d. i = 2; j = 1; k = 0;
//    i *= j *= k;
//    printf("%d %d %d", i, j, k);
// Expectation: i *= (j *= k) -> (i *= (j *= k)) -> (i *= (j = j * k)) -> (i *= (j = 0)) -> (i = i * (j = 0)) -> i = 0, j = 0, k = 0
// Actual: i = 0, j = 0, k = 0


#include <stdio.h>

int main (void) {
    int i, j, k;

    i = 7; j = 8;
    i *= j + 1;
    printf("%d %d\n", i, j); 

    i = j = k = 1;
    i += j += k;
    printf("%d %d %d\n", i, j, k);

    i = 1; j = 2; k = 3;
    i -= j -= k;
    printf("%d %d %d\n", i, j, k);

    i = 2; j = 1; k = 0;
    i *= j *= k;
    printf("%d %d %d\n", i, j, k);

    return 0;
}
