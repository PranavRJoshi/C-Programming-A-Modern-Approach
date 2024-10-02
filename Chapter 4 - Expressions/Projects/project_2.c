// Q. Extend the program in Programming Project 1 to handle three-digit numbers.

#include <stdio.h>

int main (void) {
    int num;
    int reverse_num = 0;

    printf("Enter a three-digit number: ");
    scanf("%3d", &num);

    reverse_num = ((num % 10) * 100) + (((num / 10) % 10) * 10) + (num / 100);

    printf("The reversal is %d", reverse_num);

    return 0;
}
