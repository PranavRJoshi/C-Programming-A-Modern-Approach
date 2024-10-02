#include <stdio.h>
#define PI 3.14159f
#define VOL_FACTOR ( 4.0f / 3.0f )

int main (void) {
    float radius = 0.0f;

    printf("Enter the radius of sphere: ");
    scanf("%f", &radius);

    float volume = VOL_FACTOR * PI * (radius * radius * radius);

    printf("The volume of the sphere is: %.3f\n", volume);

    return 0;
}
