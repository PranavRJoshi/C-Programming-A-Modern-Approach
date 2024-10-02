// Q. Write a function that accepts a date from the user in the form mm/dd/yyyy and then displays it in the form month dd, yyyy, where month is the name of the month:
//    Enter a date (mm/dd/yyyy): 2/17/2011
//    You entered the date February 17, 2011.

#include <stdio.h>

void display_date (const char *date);

int main (void) {

  int month, day, year;
  char date_format[11];

  printf("Enter a date (mm/dd/yyyy): ");
  while (scanf("%2d/%2d/%4d", &month, &day, &year) != 3 || (month < 0  || month > 12) || (day < 0 || day > 31)) {
    printf("[WARN] The date speicified is invalid.\nTry again (mm/dd/yyyy): ");
  }

  sprintf(date_format, "%2d/%2d/%4d", month, day, year);

  display_date(date_format);

  return 0;
}

void display_date (const char *d) {
  const char named_month[][10] = {"January",
                                  "February",
                                  "March",
                                  "April",
                                  "May",
                                  "June",
                                  "July",
                                  "August",
                                  "September",
                                  "October",
                                  "November",
                                  "December"};
  
  int month, day, year;
  month = day = year = 0;
  int track = 0;

  while (*d) {
    if (track == 0 && *d != '/' && *d != ' ') {
      month = month * 10 + (*d - '0');
    }
    if (track == 1 && *d != '/' && *d != ' ') {
      day = day * 10 + (*d - '0');
    }
    if (track ==2 && *d != '/' && *d != ' ') {
      year = year * 10 + (*d - '0');
    }
    if (*d == '/') {
      track++;
    }
    d++;
  }

  printf("You entered the date %s %d, %d\n", named_month[month - 1], day, year);

}

