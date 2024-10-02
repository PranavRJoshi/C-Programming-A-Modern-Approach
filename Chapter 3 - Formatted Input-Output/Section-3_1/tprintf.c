#include <stdio.h>

int main (void) {
    int num_1 = 40;
    float num_2 = 888.888;

    printf("|%d|%1d|%-5d|%5.4d|\n", num_1, num_1, num_1, num_1);
    printf("This is just a test\a\n");
    printf("|%10.1f|%-10.2e|%5.2g|%5.4g|", num_2, num_2, num_2, num_2);

    return 0;
}
