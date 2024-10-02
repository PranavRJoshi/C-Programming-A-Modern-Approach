// Q. Modify Programming Project 9 from Chapter 5 so that each date entered by the user is stored in a date structure (see Exercise 5). Incorporate the compare_dates function of Exercise 5 into your program.

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
  int scanf_return_count = 0;

  for (;;) {
    printf("Enter the first date in the format (yy/mm/dd): ");
    if ((scanf_return_count = scanf("%2d/%2d/%2d", &d1.year, &d1.month, &d1.day)) != 3) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    if (d1.year < 0) {
      fprintf(stderr, "[ERROR] Invalid Year Entered.\n");
      clear_input_stream();
      continue;
    }
    if (d1.month <= 0 || d1.month > 12) {
      fprintf(stderr, "[ERROR] Invalid Month Entered.\n");
      clear_input_stream();
      continue;
    }
    if (d1.day <= 0 || d1.day > 31) {
      fprintf(stderr, "[ERROR] Invalid Day Entered.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  for (;;) {
    printf("Enter the second date in the format (yy/mm/dd): ");
    if ((scanf("%2d/%2d/%2d", &d2.year, &d2.month, &d2.day)) != 3) {
      printf("[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    if (d2.year < 0) {
      fprintf(stderr, "[ERROR] Invalid Year Entered.\n");
      clear_input_stream();
      continue;
    }
    if (d2.month <= 0 || d2.month > 12) {
      fprintf(stderr, "[ERROR] Invalid Month Entered.\n");
      clear_input_stream();
      continue;
    }
    if (d2.day <= 0 || d2.day > 31) {
      fprintf(stderr, "[ERROR] Invalid Day Entered.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  int date_comparision = compare_dates(d1, d2);

  if (date_comparision == 0) {
    printf("Same Date Entered.\n");
  } else if (date_comparision < 0) {
    printf("The first date comes earlier than the second date\n");
  } else {
    printf("The second date comes earlier than the second date.\n");
  }

  return 0;
}

int compare_dates (struct date d1, struct date d2) {
  if (d1.year > d2.year) {
    return 1;
  } else if (d1.year < d2.year) {
    return -1;
  } else {
    if (d1.month > d2.month) {
      return 1;
    } else if (d1.month < d2.month) {
      return -1;
    } else {
      if (d1.day > d2.day) {
        return 1;
      } else if (d1.day < d2.day) {
        return -1;
      } else {
        return 0;
      }
    }
  }
}

void clear_input_stream (void) {
  int ch;
  ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

