// Q. Show how to modify the addfrac.c program of Section 3.2 so that the user is allowed to enter fractions that contain spaces before and after each / character. 

/* Modified add_frac program */

#include <stdio.h>

int main (void) {
    int num1 = 0, num2 = 0;
    int denom1 = 1, denom2 = 1;
    int result_num = 0, result_denom = 1;

    printf("Enter the first fraction: ");
    scanf("%d /%d", &num1, &denom1);

    printf("Enter the second fraction: ");
    scanf("%d /%d", &num2, &denom2);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    printf("The sum of two fraction numbers given are: %d / %d\n", result_num, result_denom);

    return 0;
}
