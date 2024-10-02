// Q. Write a program that sums a series of integers entered by the user. Here's what the user will see:
//  This program sums a series of integers.
//  Enter integers (0 to terminate): 8 23 71 5 0
//  The sum is: 107
// Clearly, we'll need a loop that uses scanf to read a number and then adds the number to the running total
// Letting n represent the number just read and sum the total of all numbers previously read

#include <stdio.h>

int main (void) {

    int n, sum = 0;

    printf("This program sums a series of integers.\n");
    printf("Enter intgers (0 to terminate): ");
    scanf("%d", &n);

    while (n != 0) {
        sum += n;
        scanf("%d", &n);
    }

    printf("The sum is: %d\n", sum);

    return 0;
}
