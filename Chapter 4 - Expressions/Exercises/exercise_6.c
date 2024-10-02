// Q. Repeat Exercise 5 for C99
// The explaination for the expected values are provided in exercise_3.c file.
// a. 8 % 5 // Expected: 3 // Actual: 3
// b. -8 % 5 // Expected: -3 or +2 // Actual: -3
// c. 8 % -5 // Expected: +3 or -2 // Actual: 3
// d. -8 % -5 // Expected: 3 // Actual: -3 // Explaination provided in exercise_5.c

#include <stdio.h>

int main (void) {
    int i = 8, j = 5;
    printf("(%d %% %d) = %d\n", i, j, (i % j));

    i = -8, j = 5;
    printf("(%d %% %d) = %d\n", i, j, (i % j));

    i = 8, j = -5;
    printf("(%d %% %d) = %d\n", i, j, (i % j));

    i = -8, j = -5;
    printf("(%d %% %d) = %d\n", i, j, (i % j));

    return 0;
}
