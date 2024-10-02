// Q. Modify the upc.c program of Section 4.1 so that it checks whether a UPC is valid. After the user enters a UPC, the program will display either VALID or NOT VALID.

#include <stdio.h>

int main (void) {
    int first_digit, second_digit, third_digit, fourth_digit, fifth_digit;
    int sixth_digit, seventh_digit, eighth_digit, ninth_digit, tenth_digit;
    int eleventh_digit, twelfth_digit;
    int first_sum, second_sum, total;

    printf("Enter the 12 digits of UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &first_digit, &second_digit, &third_digit, &fourth_digit, &fifth_digit, &sixth_digit, &seventh_digit, &eighth_digit, &ninth_digit, &tenth_digit, &eleventh_digit, &twelfth_digit);

    first_sum = first_digit + third_digit + fifth_digit + seventh_digit + ninth_digit + eleventh_digit;
    second_sum = second_digit + fourth_digit + sixth_digit + eighth_digit + tenth_digit;

    total = 3 * first_sum + second_sum;
    total = (9 - ((total - 1) % 10));

    if (total == twelfth_digit) {
        printf("VALID\n");
    } else {
        printf("NOT VALID\n");
    }

    return 0;
}
