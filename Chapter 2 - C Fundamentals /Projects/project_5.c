#include <stdio.h>
// #define SQUARE_NUM(x)  (x * x)
// #define CUBE_NUM(x)    (x * x * x)
// #define QUAD_NUM(x)    (x * x * x * x)
// #define QUINT_NUM(x)   (x * x * x * x * x)

int main (void) {
    int x = 0;
    int result = 0;

    printf("Program that computes 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6\n");
    printf("Enter the value for x: ");
    scanf("%d", &x);

    // result = 3 * QUINT_NUM(x) + 2 * QUAD_NUM(x) - 5 * CUBE_NUM(x) - SQUARE_NUM(x) + 7 * x - 6;
    result = 3 * (x * x * x * x * x) + 2 * (x * x * x * x) - 5 * (x * x * x) - (x * x) + 7 * x - 6;

    printf("The result when x = %d is: %d\n", x, result);

    return 0;
}
