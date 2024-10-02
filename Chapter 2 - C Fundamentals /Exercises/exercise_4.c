#include <stdio.h>

int main (void) {
    int var_1, var_2, var_3, var_4, var_5;
    float var_6, var_7, var_8, var_9, var_10;

    printf("The values of integers that are not initialized are: \n");
    printf("Value in var_1: %d\n", var_1);
    printf("Value in var_2: %d\n", var_2);
    printf("Value in var_3: %d\n", var_3);
    printf("Value in var_4: %d\n", var_4);
    printf("Value in var_5: %d\n", var_5);
    printf("The values of floats that are not initialized are: \n");
    printf("Value in var_6: %f\n", var_6);
    printf("Value in var_7: %f\n", var_7);
    printf("Value in var_8: %f\n", var_8);
    printf("Value in var_9: %f\n", var_9);
    printf("Value in var_10: %f\n", var_10);

    return 0;
}

// The output of the program are as follows:
// The values of integers that are not initialized are: 
// Value in var_1: 73629696
// Value in var_2: 73629696
// Value in var_3: 73629696
// Value in var_4: 73629696
// Value in var_5: 73629696
// The values of floats that are not initialized are: 
// Value in var_6: 0.000000
// Value in var_7: 0.000000
// Value in var_8: 0.000000
// Value in var_9: 0.000000
// Value in var_10: 0.000000
