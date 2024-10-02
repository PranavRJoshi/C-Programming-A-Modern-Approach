// Q. Would the upc.c program still work if the expression 9 - ((total - 1) % 10) were replaced by (10 - (total % 10)) % 10?
// A. The program seems to run as expected for the following examples: 0-13800-15173-?(5), 0-51500-24128-?(8), 0-31200-01005-?(6).

#include <stdio.h>

int main (void) {
    int first_digit;
    int i1, i2, i3, i4, i5;
    int j1, j2, j3, j4, j5;
    int first_sum, second_sum;
    int total;

    printf("Enter the first (single) digit: ");
    scanf("%1d", &first_digit);

    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    first_sum = first_digit + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;

    printf("Check digit: %d\n", ((10 - (total % 10)) % 10));

    return 0;
}
