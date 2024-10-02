/* Computing a UPC Check digit */

// Background: Universal Product Code (UPC) are those codes (bar codes) put by manufacturers of goods that was sold in USA and Canadian stores.
// Each bar code represents a twelve-digit number, which is usually printed underneath the bars.
// The numbers are usually in the format: x xxxxx xxxxx x; here, x represents a digit
// The first number identifies the type of item (0 or 7) for most items, 2 for items that must be weighed, 3 for drugs and health-related merchandise, and 5 for coupons.
// The first group of five digits identifies the manufacturer.
// The second group of five digits identifies the product (including package size).
// The final digit is a "check digit", whose only purpose is to help identify an error in the preceding digits.
// If the UPC is scanned incorrectly, the first 11 digits probably won't be consistent with the last digit, and the store's scanner will reject the entire code.

// One method of computing the check digit:
// Add the first, third, fifth, seventh, ninth, and eleventh digits.
// Add the second, fourth, sixth, eighth, and tenth digits.
// Multiply the first sum by 3 and add it to the second sum.
// Subtract 1 from the total.
// Compute the remainder when the adjusted total is divided by 10.
// Subtract the remainder from 9.

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

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}
