// Q. Write a function day_of_year(month, day, year) that returns the day of the year (an integer between 1 and 366) specified by the three arguments.

#include <stdio.h>

int day_of_month (int month, int day, int year);

int main (void) {
  int month, day, year;

  printf("Enter the date (yy/mm/dd): ");
  scanf("%d/%d/%d", &year, &month, &day);

  printf("%d day(s) have gone for the year %d\n", day_of_month(month, day, year), year); 
  
  return 0;
}

int day_of_month (int m, int d, int y) {
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int total_days = 0;

  for (int i = 0; i < m - 1; i++) {
    total_days += days_in_month[i];
  }

  // when a year is divisible by 4 (and not divisible by 100), it is a leap year
  // OR if a year is divisible by 400, then also it is a leap year
  if (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && m > 2) {
    total_days++;
  }

  return total_days + d;
}

