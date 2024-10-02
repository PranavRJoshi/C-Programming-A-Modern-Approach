#include <stdio.h>

int main (void) {
    int height = 8, length = 12, width = 10, volume;
    volume = height * width * length;
    printf("Dimensions (in inches): %dx%dx%d\n", length, width, height);
    printf("Volume (in cubic inches): %d\n", volume);
    printf("Dimensional Weight (in pounds): %d\n", ((volume + 165) / 166));
    return 0;
}
