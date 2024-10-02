/*
// Q. What is the value of each of the following expressions in C89? (Give all possible values if an expression may have more than one value)
// a. 8 / 5 // Expected: 1 // Actual: 1
// b. -8 / 5 // Expected: -1 or -2 // Actual: -1
    // (i / j) * j + i % j == i // The result of (i / j) can be either rounded up or down if either one of operand is negative.
    // (-8 / 5) * 5 + (-8 % 5) -> (-1 * 5) + (-3) = -8
    // (-8 / 5) * 5 + (-8 % 5) -> (-2 * 5) + (+2) = -8
// c. 8 / -5 // Expected: -1 or -2 // Actual: -1
    // (i / j) * j + i % j == i
    // (8 / -5) * -5 + (8 % -5) -> (-1 * -5) + (+3) = 8
    // (8 / -5) * -5 + (8 % -5) -> (-2 * -5) + (-2) = 8
// d. -8 / -5 // Expected: 1 // Actual: 1
    // This should work like a normal division as both the operands have a negative sign, thereby cancelling the minus sign.
    // (i / j) * j + i % j == i
    // (-8 / -5) * -5 + (-8 % -5) -> (-1 * -5) + (???) = -8 // this and the expression below simply does not work as the value for (i % j) should be such that it should be -13 to get the final result of -8
    // (-8 / -5) * -5 + (-8 % -5) -> (-2 * -5) + (???) = -8 // the value of (i % j) should be -18 to get the final result of -8
*/

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
