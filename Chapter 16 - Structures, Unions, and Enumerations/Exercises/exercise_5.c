// Q. Write the following functions, assuming that the date structure contains three members:
//    month, day, and year (all of type int).
//
//    (a) int day_of_year(struct date d);
//
// Returns the day of the year (an integer between 1 and 366) that corresponds to the date d.
//
//    (b) int compare_dates(struct date d1, struct date d2);
//
// Returns -1 if d1 is an earlier date than d2, +1 if d1 is later date than d2, and 0 if d1 and d2 are the same.

#include <stdio.h>

/*
 * date:  A structure that has the members month (int), day (int), and year (int).
*/
struct date {
  int month;
  int day;
  int year;
};

/*
 * day_of_year: Returns the day of the year (an integer between 1 and 366)
 *              that corresponds to the date d. 
*/
int day_of_year (struct date d);

/*
 * compare_dates: Returns -1 if d1 is earlier date than d2, +1 if d1 is a 
 *                later date than d2, and 0 if d1 and d2 are the same.
*/
int compare_dates (struct date d1, struct date d2);

/*
 * clear_imput_stream:  clears the standard input stream. will also work
 *                      for files that have EOF as the last character.
*/
void clear_input_stream (void);

int main (void) {

  struct date d1, d2;

  printf("Enter the first date in the format (yyyy/mm/dd): ");
  while (scanf("%4d/%2d/%2d", &d1.year, &d1.month, &d1.day) != 3) {
    printf("[ERROR] Not all fields provided by the user.\nTry Again: ");
    clear_input_stream();
  }

  printf("Enter the second date in the format (yyyy/mm/dd): ");
  while (scanf("%4d/%2d/%2d", &d2.year, &d2.month, &d2.day) != 3) {
    printf("[ERROR] Not all fields provided by the user.\nTry Again: ");
    clear_input_stream();
  }

  printf("The day of the year for the two dates are: \n");
  printf("For the first date: %d\n", day_of_year(d1));
  printf("For the second date: %d\n", day_of_year(d2));

  int date_comparision = compare_dates(d1, d2);

  // printf("[LOG] The returned value from compare_dates is: %d\n", date_comparision);

  if (date_comparision == 0) {
    printf("The first date and the second date are the same.\n");
  } else if (date_comparision < 0) {
    printf("The first date is earlier than the second date.\n");
  } else {
    printf("The first date is later than the second date.\n");
  }

  return 0;
}

int day_of_year (struct date d) {
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int total_days = 0;

  for (int i = 0; i < d.month - 1; i++) {
    total_days += days_in_month[i];
  }

  if (((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0)) && d.month > 2) {
    total_days++;
  }

  return total_days + d.day;
}

int compare_dates (struct date d1, struct date d2) {
  if (d1.year > d2.year) {
    return 1;
  } else if (d1.year < d2.year) {
    return -1;
  } else {
    return (day_of_year(d1) - day_of_year(d2)) < 0 ? -1 : (day_of_year(d1) - day_of_year(d2)) == 0 ? 0 : 1;
  }
}

void clear_input_stream (void) {
  int ch;
  ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}
