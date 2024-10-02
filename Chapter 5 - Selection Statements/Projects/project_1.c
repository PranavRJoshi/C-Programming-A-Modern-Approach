// Q. Write a program that calculates how many digits a number contains:
//      Enter a number: 374
//      The number 374 has 3 digits
// You may assume that the number has no more than four digits. Hint: Use if statements to test the number. For example, if the number is between 0 and 9, it has one digit. If the number is between 10 and 99, it has two digits.

#include <stdio.h>

int main (void) {

    int num;
    int num_of_digits = 0;

    printf("Enter a number: ");
    scanf("%4d", &num);

    if (num < 10) {
        num_of_digits = 1;
    } else if (num <= 99) {
        num_of_digits = 2;
    } else if (num <= 999) {
        num_of_digits = 3;
    } else if (num <= 9999) {
        num_of_digits = 4;
    }

    printf("The number %d has %d digits\n", num, num_of_digits);

    return 0;
}
