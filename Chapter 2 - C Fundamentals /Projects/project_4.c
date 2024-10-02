#include <stdio.h>

int main (void) {
    float value_before_tax = 0.0f;
    float value_after_tax = 0.0f;

    printf("Enter an amount: ");
    scanf("%f", &value_before_tax);

    value_after_tax = 1.05f * value_before_tax;

    printf("With tax added: %.2f\n", value_after_tax);

    return 0;
}
