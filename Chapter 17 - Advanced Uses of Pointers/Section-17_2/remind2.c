// The original remind.c program stores the reminder strings in a two-dimensional array of characters, with each row of the array containing one string. The steps the program can be broken down as:
//    a. After the program reads a day and its associated reminder, it searches the array to determine where the day belongs, using strcmp to do the comparisions.
//    b. It then uses strcpy to move all strings below that point down one position.
//    c. Finally, the program copies the day into the array and calls strcat to append the reminder to the day.
// In the new program (remind2.c), the array will be one-dimensional; its elements will be pointers to dynamically allocated strings.
// 
// Switching to dynamically allocated strings in this program will have two primary advantages.
//    -> First, we can use space more efficiently by allocating the exact number of characters needed to store a reminder, rather than storing the reminder in a fixed number of characters as the original program does.
//    -> Second, we won't need to call strcpy to move existing reminder strings in order to make room for a new reminder. Instead, we'll merely move pointers to strings.
//
// Here's the new program, with changes between the comments that has `CHANGES` in it. Switching from a two-dimensional array to an array of pointers turns out to be remarkably easy: we'll only need to change eight lines of the program.

#include <stdio.h>
/*********** CHANGES ***************/
#include <stdlib.h>
/*********** CHANGES ***************/
#include <string.h>

#define MAX_REMIND 50     /* maximum number of reminders */
#define MSG_LEN 60        /* max length of reminder message */

int read_line (char *arr, int size);

int main (void) {

  /*********** CHANGES ***************/
  char *reminders[MAX_REMIND];
  /*********** CHANGES ***************/
  char day_str[3];
  char msg_str[MSG_LEN+1];
  int day, i, j;
  int num_remind = 0;

  for (;;) {
    if (num_remind >= MAX_REMIND) {
      printf("-- FULL: CANNOT STORE MORE REMINDERS --\n");
      break;
    }
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0) {
      break;
    }
    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++) {
      if (strcmp(day_str, reminders[i]) < 0) {
        break;
      }
    }

    for (j = num_remind; j > i; j--) {
      /*********** CHANGES ***************/
      reminders[j] = reminders[j-1];
      /*********** CHANGES ***************/
    }

    /*********** CHANGES ***************/
    reminders[i] = malloc(2 + strlen(msg_str) + 1);
    if (reminders[i] == NULL) {
      printf("-- No space left --\n");
      break;
    }
    /*********** CHANGES ***************/

    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
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

