/* Convert the given temperature in Fahrenheit to Celcius */

#include <stdio.h>
#define FREEZING_POINT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)
// Using (5/9) is not going to work as the result would be less than 0 
// and the value after the decimal point is truncated

int main (void) {
    float temp_in_fahrenheit, temp_in_celcius;

    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &temp_in_fahrenheit);

    temp_in_celcius = (temp_in_fahrenheit - FREEZING_POINT) * SCALE_FACTOR;

    printf("The equivalent temperature in Celcius is: %.1f\n", temp_in_celcius);

    return 0;
}
