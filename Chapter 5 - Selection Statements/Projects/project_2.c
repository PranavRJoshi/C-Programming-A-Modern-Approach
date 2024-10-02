// Q. Write a program that asks the user for a 24-hour time, then displays the time in 12-hour form:
//      Enter a 24-hour time: 21:11
//      Equivalent 12-hour time: 9:11 PM
// Be careful not to display 12:00 as 0:00.

#include <stdio.h>

int main (void) {

    int hour = 0, minute = 0;

    printf("Enter a 24-hour time: ");
    scanf("%2d:%2d", &hour, &minute);

    if (hour > 12) {
        printf("Equivalent 12-hour time: %.2d:%.2d PM", (hour - 12), minute);
    } else if (hour == 12) {
        printf("Equivalent 12-hour time: %.2d:%.2d PM", hour, minute);
    } else {
        printf("Equivalent 12-hour time: %.2d:%.2d AM", hour, minute);
    }

    return 0;
}
