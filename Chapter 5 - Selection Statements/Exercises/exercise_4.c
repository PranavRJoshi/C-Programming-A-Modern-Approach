// Q. Write a single expression whose value is either -1, 0 or +1 depending on whether i is less than, equal to, or greater than j, respectively.

#include <stdio.h>

int main (void) {

    int num;
    int result;

    printf("Enter a number: ");
    scanf("%d", &num);

    result = (num == 0 ? 0 : (num > 0 ? 1: -1));

    printf("The result for the given number is: %d\n", result);

    return 0;
}
