/*
// Q. What is the value of each of the following expressions in C89? (Give all possible values if an expression may have more than one value.)
// The explaination for the expected values are provided in exercise_4.c file.
// a. 8 % 5 // Expected: 3 // Actual: 3
// b. -8 % 5 // Expected: -3 or +2 // Actual: -3
// c. 8 % -5 // Expected: +3 or -2 // Actual: 3
// d. -8 % -5 // Expected: 3 // Actual: -3

// So, why does -8 (i) % -5 (j) yield -3? As C must satisfy the equality for negative integers in division or modulus operation
// like (i / j) * j + i % j == i. So, i % j == i - ((i / j) * j)
// (i / j) will yield 1, so i % j == -8 - ((1) * -5) -> i % j = -8 - (-5) -> i % j = -3
*/

#include <stdio.h>

int main (void) {
    int i = 8, j = 5;
    printf("(%d %% %d) = %d\n", i, j, (i % j));

    i = -8, j = 5;
    printf("(%d %% %d) = %d\n", i, j, (i % j));

    i = 8, j = -5;
    printf("(%d %% %d) = %d\n", i, j, (i % j));

    i = -8, j = -5;
    printf("(%d %% %d) = %d\n", i, j, (i % j));

    return 0;
}
