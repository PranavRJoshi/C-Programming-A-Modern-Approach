// Q. Programming Project 9 in Chapter 5 asked you to write a program that determines which of two dates comes earlier on the calendar. Generalize the program so that the user may enter any number of dates. The user will enter 0/0/0 to indicate that no more dates will be entered:
//    Enter a date (mm/dd/yy): 3/6/08
//    Enter a date (mm/dd/yy): 5/17/07
//    Enter a date (mm/dd/yy): 6/3/07
//    Enter a date (mm/dd/yy): 0/0/0
// 5/17/07 is the earliest date

#include <stdio.h>

int main (void) {

  int day, month, year;
  int early_day = 31, early_month = 12, early_year = 99;

  for (;;) {
    
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    if (month == 0 && day == 0 && year == 0)
      break;
    
    if (year < early_year) {
      early_year = year, early_month = month, early_day = day;
    } else if (year == early_year) {
        if (month < early_month) {
          early_year = year, early_month = month, early_day = day;
        } else if (month == early_month) {
            if (day < early_day) {
              early_year = year, early_month = month, early_day = day;
            } 
        }
    }
  }

  printf("%d/%d/%d is the earliest date.", early_month, early_day, early_year);

  return 0;  
}
