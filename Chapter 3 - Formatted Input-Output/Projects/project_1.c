// Q. Write a program that accepts a date of from the user in the form mm/dd/yyyy and then displays it in the form yyyymmdd:
// Enter a date (mm/dd/yyyy): 2/17/2011
// You entered the date 20110217

#include <stdio.h>

int main (void) {
    int month = 0, date = 0, year = 0;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &date, &year);

    printf("You entered the date %4d%2.2d%2.2d\n", year, month, date);
    // %2.2d (of format %m.pX; X = d here) indicates a field width of 2 and for %d, p indicates the minimum number to display (0 is used as padding)

    return 0;
}
