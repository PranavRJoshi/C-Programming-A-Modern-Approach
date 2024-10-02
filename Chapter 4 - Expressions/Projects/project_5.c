// Q. Rewrite the upc.c program of Section 4.1 so that the user enters 11 digits at one time, instead of entering one digit, then five digits, and then another five digits.
// Enter the first 11 digits of a UPC: 01380015173
// Check digit: 5

#include <stdio.h>

int main (void) {
    int first_digit, second_digit, third_digit, fourth_digit, fifth_digit;
    int sixth_digit, seventh_digit, eighth_digit, ninth_digit, tenth_digit;
    int eleventh_digit;
    int first_sum, second_sum, total;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &first_digit, &second_digit, &third_digit, &fourth_digit, &fifth_digit, &sixth_digit, &seventh_digit, &eighth_digit, &ninth_digit, &tenth_digit, &eleventh_digit);

    first_sum = first_digit + third_digit + fifth_digit + seventh_digit + ninth_digit + eleventh_digit;
    second_sum = second_digit + fourth_digit + sixth_digit + eighth_digit + tenth_digit;

    total = 3 * first_sum + second_sum;
    total--;
    total = total % 10;
    total = 9 - total;

    printf("Check digit: %d", total);

    return 0;
}
