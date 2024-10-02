// Q. Write calls of printf that display a float variable x in the following formats.
// a. Exponential notation; left-justified in a field of size 8; one digit after the decimal point.
// b. Exponential notation; right-justified in a field of size 10; six digits after the decimal point.
// c. Fixed decimal notation; left-justified in a field of size 8; three digits after the decimal point.
// d. Fixed decimal notation; right-justified in a field of size 6; no digits after the decimal point.

#include <stdio.h>

int main (void) {
    float x = 789.123456;

    printf("%-8.1e\n", x);
    printf("%10.6e\n", x); 
    printf("%-8.3f\n", x);
    printf("%6.0f\n", x);

    float i = 0, j = 0;
    int y = 0;

    printf("Enter the values: ");
    scanf("%f%d%f", &i, &y, &j);

    printf("The entered values are: %f %d and %f", i, y, j);

    return 0;
}

// Output:
// 7.9e+02 
// 7.891235e+02
// 789.123 
//    789
