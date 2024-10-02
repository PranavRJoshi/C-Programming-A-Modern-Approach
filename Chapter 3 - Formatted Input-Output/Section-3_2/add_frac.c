/* Add two fractions */
/* The input expects a value of <num1>/<num2> */

#include <stdio.h>

int main (void) {
    int num1 = 0, num2 = 0, denom1 = 1, denom2 = 1;
    int result_num = 0, result_denom = 1;

    printf("Enter the value of the first fractional number: ");
    scanf("%d/%d", &num1, &denom1);

    printf("Enter the value of the second fractional number: ");
    scanf("%d/%d", &num2, &denom2);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    printf("The sum of two given fractional number is: %d/%d\n", result_num, result_denom);
    
    return 0;
}
