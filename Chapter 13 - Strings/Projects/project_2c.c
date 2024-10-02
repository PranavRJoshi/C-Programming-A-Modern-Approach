#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50     /* maximum number of reminders */
#define MSG_LEN 60        /* max length of reminder message */
#define DATE_LEN 6
#define TIME_LEN 6
#define DATE_TIME_LEN 15

int read_line (char *arr, int size);
void clean_input_buffer ();

int main (void) {

  char reminders[MAX_REMIND][MSG_LEN+3];
  char date_str[DATE_LEN];
  char time_str[TIME_LEN];
  char date_time_str[DATE_TIME_LEN];
  char msg_str[MSG_LEN+1];
  int month, day, i, j;
  int hour, minute;
  int num_remind = 0;

  for (;;) {
    if (num_remind >= MAX_REMIND) {
      printf("-- FULL: CANNOT STORE MORE REMINDERS --\n");
      break;
    }
    printf("Enter month/day, hour:minute and reminder: ");
    // the reason we put a space between %2d and / is that, in the scenario when user enters "12        /    15", the program should take it as a valid month/day format. Having the space in the format string in scanf indicates that scanf expects one or more (or none) spaces after reading the first conversion specifier (%d for &month) and the character '/'. There is no need to put space after the '/' character in the format string as all the leading spaces before the second number in the input string is ignored, and scanf reads for the second number (%d for &day) when it finds a non-space character. 
    while (scanf("%2d /%2d", &month, &day) != 2) {
      clean_input_buffer();
      printf("[WARN] Day is not present.\n[RETRY] Continue from day [mm/dd] [hh:mm] [reminder]: ");
    }
    if (day == 0 || month == 0) {
      break;
    }
    if (month < 0 || month > 12) {
      printf("[ERROR] Invalid Month Entered. Try Again.\n");
      clean_input_buffer();
      continue;
    }
    if ((day < 0 || day > 31) || (month < 0 || month > 12)) {
      printf("[ERROR] Invalid Day Entered. Try Again.\n");
      clean_input_buffer();
      continue;
    }
    sprintf(date_str, "%2d/%2d", month, day);

    // for storing 24-hour time in hh:mm format
    // int temp = 0;
    // temp = scanf("%d:%d", &hour, &minute);
    // printf("[LOG] temp has the value: %d", temp);
    // NOTE: on valid input, scanf should return 2.
    //
    // We put a space before the `:` character (in the scanf format string) as the user could input 15     :     20, which is indeed a valid time format, but since there are a lot of spaces between 5 and :, once scanf reads the first space after 5, scanf will terminate as it fails to find the `:` character. Having that one space in the format string indicates that there could be one or more (or none) spaces between the first converstion (%d for &hour) and `:`.
    while (scanf("%d :%d", &hour, &minute) != 2) {
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

    strcpy(date_time_str, date_str);
    strcat(date_time_str, time_str);

    // printf("[LOG] time_str contains: %s\n", time_str);
    // printf("[LOG] date_time_str contains is: %s\n", date_time_str);

    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++) {
      // for log purposes only!
      // printf("[LOG] ");
      // for (char *k = date_str; k < (date_str+DATE_LEN); k++) {
      //   printf("%c", *k);
      // }
      // for (char *l = time_str; l < (time_str + TIME_LEN); l++) {
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

    strcpy(reminders[i], date_str);
    strcat(reminders[i], " ");
    strcat(reminders[i], time_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\n mm/dd hh:mm Reminder\n");
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

