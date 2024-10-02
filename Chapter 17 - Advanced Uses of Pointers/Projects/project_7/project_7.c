// Q. (C99) Modify the remind2.c program of Section 17.2 so that each element of the reminders array is a pointer to a vstring structure (see Section 17.9) rather than a pointer to an ordinary string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_REMIND 50      /* maximum number of reminders */
#define MSG_LEN 60            /* max length of reminder message */

int max_remind = 5;

int read_line (char *arr, int size);

/* Structure according to the question */
struct v_str_arr {
  char day[3];
  char reminder[];
} **reminders;

int main (void) {

  char day_str[3];
  char msg_str[MSG_LEN+1];
  int day;
  int i, j;
  int num_remind = 0;

  int msg_len = 0;
  struct v_str_arr *temp = NULL; 

  reminders = malloc(sizeof(struct v_str_arr *) * max_remind);
  if (reminders == NULL) {
    fprintf(stderr, "[FATAL ERROR] Failed to allocate sufficient memory. Exiting.\n");
    exit(EXIT_FAILURE);
  }

  for (;;) {
    if (num_remind >= max_remind) {
      max_remind = max_remind * 2;
      printf("[LOG] Doubling the size of strucutre from %d to %d.\n", max_remind / 2, max_remind);
      reminders = realloc(reminders, sizeof(struct v_str_arr *) * max_remind);
      if (reminders == NULL) {
        fprintf(stderr, "[FATAL ERROR] Failed to allocate sufficient memory. Exiting.\n");
        exit(EXIT_FAILURE);
      }
    }
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0) {
      break;
    }
    sprintf(day_str, "%2d", day);
    msg_len = read_line(msg_str, MSG_LEN);

    // unwanted code.
    // msg_len = read_line((*(reminders + num_remind))->reminder, MSG_LEN);
    // msg_len = read_line(reminders[num_remind]->reminder, MSG_LEN);    /* Alternate */

    /* TODO: Has no use if the loop below is not executed. */
    /* Working fine for now. A detailed explaination is given below. */
    for (i = 0; i < num_remind; i++) {
      if (strcmp(day_str, (*(reminders + i))->day) < 0) {
        break;
      }
    }

    /* TODO: Check why it breaks the code. */
    /* Working fine for now. The more explaination is given below during the allocation of memory for a structure with flexible array. */
    for (j = num_remind; j > i; j--) {
      /*********** CHANGES ***************/
      *(reminders + j) = *(reminders + (j - 1)); 
      // reminders[j] = reminders[j-1];
      /*********** CHANGES ***************/
    }

    /* The reason why it was not working previously is because of the statement: (TL;DR: A logic error)
     *    *(reminders + num_remind) = malloc(sizeof(struct v_str_arr) + msg_len + 1); 
     * num_remind will always point to the largest "array index", but as the previous loops are used 
     * for determining the position of the reminders based on the day string, if we have a reminder which 
     * should come before the previous reminder stored, like, the previous one stored with day 14, and the
     * current one has the day 10. This will result in the first loop breaking out when i is 0, and when the 
     * second loop is executed, j is 1 (as num_remind), and *(reminders + j) == *(reminders + 1)--in this 
     * example--will hold a pointer to a structure containing the previous day and reminder. Then, we know that
     * i is the index which needs to allocate a new memory location capable to hold the variable length reminders
     * and the day (10 in this case) and the reminder. A simple visualization will be:
     *    // Previous reminder: 
     *        *(reminders + 0) = 14 foo
     *    Day and reminder: 10 bar
     * Now, 14 > 10, so strcmp(day_str[10], (*(reminders + i))->day[14]) will be negative 
     * Now, i is 0, and j is num_remind[1], so the array element *(reminders + j) will now
     * store the pointer to struct v_str_arr at *(reminders + (j - 1)), which is *(reminders + 1) = *(reminders + 0) 
     * and a new memory is allocated at *(reminders + i), which is *(reminders + 0).
     * Now, say another day and reminder is being added:
     *    // Previous days:
     *        *(reminders + 0) = 10 bar
     *        *(reminders + 1) = 14 foo
     *    Day and reminder: 12 baz
     * Now, the day is compared. As 12 is greater than 10, the strcmp in the for loop, in the first iteration, 
     * returns a value which is greater than 0. Another iteration takes place, i.e. i = 1, and now day is checked.
     * As 12 is not greater than 14. The strcmp will return a number less than 0. So the loop breaks at i = 1.
     * When another loop body is entered, j is initialized with the value of 2 == num_remind. j is greater than i.
     * So the loop body enters. And now, the assignment *(reminders + 2) = *(reminders + 1) takes place.
     * The loop terminates again (as j is decremented and 1 < 1 is false), and another memory is allocated at *(reminders + i) 
     * to hold the current day and msg.
     * At last, consider another new day and reminder as:
     *    // Previous days:
     *        *(reminders + 0) = 10 bar
     *        *(reminders + 1) = 12 baz
     *        *(reminders + 2) = 14 foo
     *    Day and reminder: 1 lorem 
     * The day is least, so the loop terminates when i is 0, j is 3, so the loop will run for three time:
     *    *(reminders + 3) = *(reminders + 2) // first iteration
     *    *(reminders + 2) = *(reminders + 1) // second iteration
     *    *(reminders + 1) = *(reminders + 0) // third iteration
     * Now, another memory is alloacted at *(reminders + 0) which will hold the curren day and msg. and the final reminders array will hold:
     *    *(reminders + 0) = 1 lorem 
     *    *(reminders + 1) = 10 bar
     *    *(reminders + 2) = 12 baz
     *    *(reminders + 3) = 14 foo
    */
    *(reminders + i) = malloc(sizeof(struct v_str_arr) + msg_len + 1);
    // reminders[num_remind] = malloc(sizeof(struct v_str_arr) + msg_len + 1);       /* Alternate */
    if (*(reminders + i) == NULL) {
      fprintf(stderr, "[FATAL ERROR] Failed to allocate sufficient memory. Exiting.\n");
      exit(EXIT_FAILURE);
    }

    strlcpy((*(reminders + i))->reminder, msg_str, msg_len + 1);
    // strlcpy(reminders[num_remind]->reminder, msg_str, msg_len + 1);   /* Alternate */
    strlcpy((*(reminders + i))->day, day_str, 3);
    // strlcpy(reminders[num_remind]->day, day_str, 3);   /* Alternate */

    /* LOGS */
    // printf("[LOG] The message length is: %d and the message is: %s %s\n", msg_len, (*(reminders + i))->day, (*(reminders + i))->reminder);
    // printf("[LOG] The message length is: %d and the message is: %s %s\n", msg_len, reminders[num_remind]->day, reminders[num_remind]->reminder);    /* Alternate */

    num_remind++;
  }
  
  printf("Total reminders: %d\n", num_remind);

  printf("\nDay Reminder\n");
  for (int i = 0; i < num_remind; i++) {
    printf("%s %s\n", (*(reminders + i))->day, (*(reminders + i))->reminder);
    // printf("%s %s\n", reminders[i]->day, reminders[i]->reminder);     /* Alternate */
  }

  for (int i = 0; i < num_remind; i++) {
    temp = (*(reminders + i));
    // temp = reminders[i];    /* Alternate */
    free(temp);
    temp = NULL;
  }

  free(reminders);
  reminders = NULL;
  
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

