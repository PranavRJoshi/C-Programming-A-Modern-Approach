// Q. Write a program that finds the largest and smallest of four integers entered by the user:
//  Enter four integers: 21 43 10 35
//  Largest: 43
//  Smallest: 10
// Use as few if statements as possible. Hint: Four if statements are sufficient.

#include <stdio.h>

int main (void) {

    int num_1, num_2, num_3, num_4;
    int max_1, min_1, max_2, min_2;
    int largest_num, smallest_num;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &num_1, &num_2, &num_3, &num_4);

    if (num_1 > num_2) {
        max_1 = num_1;
        min_1 = num_2;
    } else {
        max_1 = num_2;
        min_1 = num_1;
    }

    if (num_3 > num_4) {
        max_2 = num_3;
        min_2 = num_4;
    } else {
        max_2 = num_4;
        min_2 = num_3;
    }

    if (max_1 > max_2) {
        largest_num = max_1;
    } else {
        largest_num = max_2;
    }

    if (min_1 < min_2) {
        smallest_num = min_1;
    } else {
        smallest_num = min_2;
    }

    printf("Largest: %d\n", largest_num);
    printf("Smallest: %d\n", smallest_num);

    return 0;
}
