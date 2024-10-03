// Q. Write the following function:
//    void split_date (int day_of_year, int year, int *month, int *day);
// day_of_year is an integer between 1 and 366, specifying a particular day within the year designated by year. month and day point to variables in which the function will store the equiavalent month (1-12) and day within that month (1-31).

#include <stdio.h>
#include <stdbool.h>

void split_date (int day_of_year, int year, int *month, int *day);

int main (void) {

  int total_day, year;
  int month, day;

  printf("Enter the date (1-366): ");
  scanf("%d", &total_day);

  printf("Enter the year: ");
  scanf("%d", &year);

  split_date(total_day, year, &month, &day);

  printf("In yy/mm/dd format, the date is: %.4d/%.2d/%.2d\n", year, month, day);

  return 0;
}

void split_date (int day_of_year, int year, int *month, int *day) {
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool is_leap_year = false;

  if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
    is_leap_year = true;
  }

  for (int i = 0; i < ((int) (sizeof(days_in_month) / sizeof(days_in_month[0]))); i++) {
    if (i == 1 && is_leap_year) {
      days_in_month[i]++;
    }
    if ((day_of_year - days_in_month[i]) <= 0) {
      (*month) = i + 1;
      break;
    }
    day_of_year -= days_in_month[i];
    (*month) = i + 1;
  }
  *day = day_of_year;
}
