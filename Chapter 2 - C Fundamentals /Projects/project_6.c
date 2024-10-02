#include <stdio.h>

int main (void) {
    int x = 0;
    int result = 0;

    printf("Program that computes 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6\n");
    printf("Enter the value for x: ");
    scanf("%d", &x);

    result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("The result when x = %d is: %d\n", x, result);

    return 0;
}
