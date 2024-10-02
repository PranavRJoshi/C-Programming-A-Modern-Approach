/* Compute the dimensional weight of a box */

#include <stdio.h>
#define INCHES_PER_POUND 166

int main (void) {
    int height, length, width, volume, weight;

    printf("Enter the height of the box: ");
    scanf("%d", &height);
    printf("Enter the width of the box: ");
    scanf("%d", &width);
    printf("Enter the length of the box: ");
    scanf("%d", &length);

    volume = height * width * length;
    weight = (volume + 165) / INCHES_PER_POUND;
    // 166 is the allowable number of cubic inches per pound
    // we add 165 to the volume as the division operation truncates the values after the decimal point
    // therefore rounding down the value, but we require the value to be rounded up

    printf("Dimensions (in inches): %dx%dx%d\n", length, width, height);
    printf("Volume (in cubic inches): %d\n", volume);
    printf("Dimensional Weight (in pounds): %d\n", weight);

    return 0;
}
