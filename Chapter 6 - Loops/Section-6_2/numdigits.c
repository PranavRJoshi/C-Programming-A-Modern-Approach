// Q. Wrie a program that calculates the number of digits in an integer entered by the user:
//  Enter a nonnegative integer: 60
//  The number has 2 digit(s)
// Our stratergy will be to divide the user's input by 10 repeatedly until it becomes 0; the number of divisions performed is the number of digits. 

#include <stdio.h>

int main (void) {

    int num, count = 0;

    printf("Enter a nonnegative number: ");
    scanf("%d", &num);

    do {
        num /= 10;
        count++;
    } while (num != 0);

    printf("The number has %d digit(s)\n", count);

    return 0;
}
