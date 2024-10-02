// Q. Improve the remind.c program of Section 13.5 in the following ways:
//    a. Have the program print an error message and ignore a reminder if the corresponding day is negative or larger than 31. Hint: Use the continue statement.
//    b. Allow the user to enter a day, a 24-hour time, and a reminder. The printed reminder list should be sorted first by day, then by time. (The original program allows the user to enter a time, but it's treated as a part of the reminder.)
//    c. Have the program print a one-year reminder list. Require the user to enter days in the form month/day.

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50     /* maximum number of reminders */
#define MSG_LEN 60        /* max length of reminder message */

int read_line (char *arr, int size);
void clean_input_buffer ();

int main (void) {

  char reminders[MAX_REMIND][MSG_LEN+3];
  char day_str[3];
  char time_str[6];
  char date_time_str[10];
  char msg_str[MSG_LEN+1];
  int day, i, j;
  int hour, minute;
  int num_remind = 0;

  for (;;) {
    if (num_remind >= MAX_REMIND) {
      printf("-- FULL: CANNOT STORE MORE REMINDERS --\n");
      break;
    }
    printf("Enter day, time and reminder: ");
    while (scanf("%2d", &day) != 1) {
      clean_input_buffer();
      printf("[WARN] Day is not present.\n[RETRY] Continue from day [dd] [hh:mm] [reminder]: ");
    }
    if (day == 0) {
      break;
    }
    if (day < 0 || day > 31) {
      printf("[ERROR] Invalid Date Entered. Try Again.\n");
      clean_input_buffer();
      continue;
    }
    sprintf(day_str, "%2d", day);

    // for storing 24-hour time in hh:mm format
    // int temp = 0;
    // temp = scanf("%d:%d", &hour, &minute);
    // printf("[LOG] temp has the value: %d", temp);
    // NOTE: on valid input, scanf should return 2.
    while (scanf("%d:%d", &hour, &minute) != 2) {
      clean_input_buffer();
      printf("[WARN] Time is not present.\n[RETRY] Continue from time [hh:mm] [reminder]: ");
    }
    
    if (hour < 0 || hour > 23) {
      printf("[ERROR] Invalid Hour Time Entered. Try Again.\n");
      clean_input_buffer();
      continue;
    }

    if (minute < 0 || minute > 59) {
      printf("[ERROR] Invalid Minute Time Entered. Try Again.\n");
      clean_input_buffer();
      continue;
    }

    sprintf(time_str, "%2d:%2d", hour, minute);

    strcpy(date_time_str, day_str);
    strcat(date_time_str, time_str);

    // printf("[LOG] time_str contains: %s\n", time_str);
    // printf("[LOG] date_time_str contains is: %s\n", date_time_str);

    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++) {
      // for log purposes only!
      // printf("[LOG] ");
      // for (char *k = day_str; k < (day_str+3); k++) {
      //   printf("%c", *k);
      // }
      // for (char *l = time_str; l < (time_str + 6); l++) {
      //   printf("%c", *l);
      // }
      // printf(" ");
      // for (char *l = reminders[i]; *l; l++) {
      //   printf("%c", *l);
      // }
      // printf("\n");
      if (strcmp(date_time_str, reminders[i]) < 0) {
        break;
      }
    }

    for (j = num_remind; j > i; j--) {
      strcpy(reminders[j], reminders[j-1]);
    }

    strcpy(reminders[i], day_str);
    strcat(reminders[i], time_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Time Reminder\n");
  for (i = 0; i < num_remind; i++) {
    printf(" %s\n", reminders[i]);
  }
  
  return 0;
}

int read_line (char *p, int n) {
  int count = 0;
  int ch;

  while ((ch = getchar()) != '\n') {
    if (count < n) {
      *p++ = ch;
      count++;
    }
  }
  *p = '\0';
  return count;
}

void clean_input_buffer () {
  while (getchar() != '\n') {
    ;
  }
}
