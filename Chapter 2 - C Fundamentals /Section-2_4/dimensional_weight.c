/* Compute the dimensional weight of a 12" x 10" x 8" box */

#include <stdio.h>

int main (void) {
    int height, length, width, volume, weight;

    height = 8;
    width = 10;
    length = 12;
    volume = height * width * length;
    weight = (volume + 165) / 166;
    // 166 is the allowable number of cubic inches per pound
    // we add 165 to the volume as the division operation truncates the values after the decimal point
    // therefore rounding down the value, but we require the value to be rounded up

    printf("Dimensions (in inches): %dx%dx%d\n", length, width, height);
    printf("Volume (in cubic inches): %d\n", volume);
    printf("Dimensional Weight (in pounds): %d\n", weight);

    return 0;
}
