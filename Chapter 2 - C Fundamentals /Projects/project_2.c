#include <stdio.h>
#define PI 3.14159f
#define VOL_FACTOR ( 4.0f / 3.0f )

int main (void) {
    float radius = 10.0f;
    float volume = VOL_FACTOR * PI * (radius * radius * radius);

    printf("The volume of the sphere is: %.3f\n", volume);

    return 0;
}

// Discussion: When the VOL_FACTOR is only ( 4 / 3 ), it truncates the value after the decimal leaving only 1
// which results in the volume to be of value 3141.590
// but when changed to ( 4.0f / 3.0f ), it results the correct value of 4188.787
