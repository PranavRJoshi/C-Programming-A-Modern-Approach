// Q. Write a program that prompts the user to enter two dates and then indicates which date comes earlier on the calendar:
//  Enter first date (mm/dd/yy): 3/6/08
//  Enter second date (mm/dd/yy): 5/17/07
//  5/17/07 comes earlier than 3/6/08

#include <stdio.h>

int main (void) {

    int day_1, month_1, year_1;
    int day_2, month_2, year_2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &month_1, &day_1, &year_1);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &month_2, &day_2, &year_2);

    if (year_1 == year_2) {
        if (month_1 == month_2) {
            if (day_1 == day_2) {
                printf("%d/%d/%d inputted twice.", month_1, day_1, year_1);
            } else if (day_1 < day_2) {
                printf("%d/%d/%d comes earlier than %d/%d/%d", month_1, day_1, year_1, month_2, day_2, year_2);    
            } else {
                printf("%d/%d/%d comes earlier than %d/%d/%d", month_2, day_2, year_2, month_1, day_1, year_1);    
            }
        } else if (month_1 < month_2) {
            printf("%d/%d/%d comes earlier than %d/%d/%d", month_1, day_1, year_1, month_2, day_2, year_2);
        } else {
            printf("%d/%d/%d comes earlier than %d/%d/%d", month_2, day_2, year_2, month_1, day_1, year_1);
        }
    } else if (year_1 < year_2) {
        printf("%d/%d/%d comes earlier than %d/%d/%d", month_1, day_1, year_1, month_2, day_2, year_2);   
    } else {
        printf("%d/%d/%d comes earlier than %d/%d/%d", month_2, day_2, year_2, month_1, day_1, year_1);
    }

    return 0;
}
