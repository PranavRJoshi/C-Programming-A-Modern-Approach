// Q. The program will first prompt the user to enter a number n. It will then print n lines of output, with each line containing a number between 1 and n together with its square:
//  This program prints a table of squares.
//  Enter number of entries in table: 5
//          1       1
//          2       4
//          3       9
//          4      16
//          5      25

#include <stdio.h>

int main (void) {

    int n, i = 1;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    while (i <= n) {
        printf("%10d%10d\n", i, i*i);
        i++;
    }
    
    return 0;
}
