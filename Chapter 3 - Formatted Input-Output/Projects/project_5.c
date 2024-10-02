// Q. Write a program that asks the user to enter the numbers from 1 to 16 (in any order) and then displays the numbers in a 4 by 4 arrangement, followed by the sums of the rows, columns, and diagonals:
// Enter the numbers from 1 to 16 in any order:
// 16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
// 16  3  2 13
// 5  10 11  8
// 9   6  7 12
// 4  15 14  1
// Row sums: 34 34 34 34
// Column sums: 34 34 34 34
// Diagonal sums: 34 34
// If the row, column, and diagonal sums are all the same (as they are in this example), the numbers are said to form a magic square. The magic square shown here appears in a 1514 engraving by artist and mathematician Albrecht Durer. (Note that the middle numbers in the last row give the date of the engraving.)

#include <stdio.h>

int main (void) {
    int num_1, num_2, num_3, num_4, num_5, num_6, num_7, num_8, num_9, num_10;
    int num_11, num_12, num_13, num_14, num_15, num_16;
    // int row_sum_1, row_sum_2, row_sum_3, row_sum_4;
    // int col_sum_1, col_sum_2, col_sum_3, col_sum_4;
    // int diag_sum_1, diag_sum_2;

    printf("Enter the numbers from 1 to 16 in any order: \n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &num_1, &num_2, &num_3, &num_4, &num_5, &num_6, &num_7, &num_8, &num_9, &num_10, &num_11, &num_12, &num_13, &num_14, &num_15, &num_16);

    printf("%2d %2d %2d %2d\n", num_1, num_2, num_3, num_4);
    printf("%2d %2d %2d %2d\n", num_5, num_6, num_7, num_8);
    printf("%2d %2d %2d %2d\n", num_9, num_10, num_11, num_12);
    printf("%2d %2d %2d %2d\n", num_13, num_14, num_15, num_16);

    printf("Row sums: %d %d %d %d\n", (num_1+num_2+num_3+num_4), (num_5+num_6+num_7+num_8), (num_9+num_10+num_11+num_12), (num_13+num_14+num_15+num_16));
    printf("Column sums: %d %d %d %d\n", (num_1+num_5+num_9+num_13), (num_2+num_6+num_10+num_14), (num_3+num_7+num_11+num_15), (num_4+num_8+num_12+num_16));
    printf("Diagonal sums: %d %d\n", (num_1+num_6+num_11+num_16), (num_13+num_10+num_7+num_4));
    

    return 0;
}
