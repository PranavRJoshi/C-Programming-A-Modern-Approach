// Q. Contracts and other legal documents are often dated in the following way:
// Dated this _________ day of ________, 20__.
// Let's write a program that displays date in this form. We'll have the user enter the date in month/day/year form, then we'll display the date in "legal" form:
// Enter date (mm/dd/yy): 7/19/14
// Dated this 19th day of July, 2014.
// We can get printf to do most of the formatting. However, we're left with two problems: how to add "th" (or "st" or "nd" or "rd") to the day, and how to print the month as a word instead of a number. Fortunately, the switch statement is ideal for both situations: we'll have one switch print the day suffix and another print the month name.

#include <stdio.h>

int main (void) {

    int month, day, year;

    printf("Enter date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    switch (day) {
        case 1: case 21: case 31:
            printf("Dated this %dst day of ", day);
            break;
        case 2: case 22: case 32:
            printf("Dated this %dnd day of ", day);
            break;
        case 3: case 23:
            printf("Dated this %drd day of ", day);
            break;
        default:
            printf("Dated this %dth day of ", day);
            break;
    }

    switch (month) {
        case 1:
            printf("January, 20%.2d\n", year);
            break;
        case 2:
            printf("February, 20%.2d\n", year);
            break;
        case 3:
            printf("March, 20%.2d\n", year);
            break;
        case 4:
            printf("April, 20%.2d\n", year);
            break;
        case 5:
            printf("May, 20%.2d\n", year);
            break;
        case 6:
            printf("June, 20%.2d\n", year);
            break;
        case 7:
            printf("July, 20%.2d\n", year);
            break;
        case 8:
            printf("August, 20%.2d\n", year);
            break;
        case 9:
            printf("September, 20%.2d\n", year);
            break;
        case 10:
            printf("October, 20%.2d\n", year);
            break;
        case 11:
            printf("November, 20%.2d\n", year);
            break;
        case 12:
            printf("December, 20%.2d\n", year);
            break;
    }

    return 0;
}
