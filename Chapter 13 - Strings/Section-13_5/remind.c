// Q. The user will enter a series of reminders, with each prefixed by a day of the month. When the user enters 0 instead of a valid day, the program will print a list of all reminders entered, stored by day. Here's what a session with the program will look like:
//    Enter day and reminder: 24 Susan's birthday
//    Enter day and reminder: 5 6:00 - Dinner with Marge and Russ
//    Enter day and reminder: 26 Movie - "Chinatown"
//    Enter day and reminder: 7 10:30 - Dental appointment
//    Enter day and reminder: 12 Movie - "Dazed and Confused"
//    Enter day and reminder: 5 Saturday class
//    Enter day and reminder: 12 Saturday class
//    Enter day and reminder: 0
// 
// Day Reminder
//   5 Saturday class
//   5 6:00 - Dinner with Marge and Russ
//   7 10:30 - Dental appointment
//  12 Saturday class
//  12 Movie - "Dazed and Confused"
//  24 Susan's birthday
//  26 Movie - "Chinatown"
// 
// The overall strategy isn't very complicated: we'll have the program read a series of day-and-reminder combinations, storing them in order (sorted by day), and then display them. To read the days, we'll use scanf; to read the reminders, we'll use the read_line function of Section 13.3.
// 
// We'll store the strings in a two-dimensional array of characters, with each row of the array contianing one string. After the program reads a day and its associated reminder, it will search the array to determine where the day belongs, using strcmp to do comparisons. It will then use strcpy to move all strings below that point down one position. Finally, the program will copy the day into the array and call strcat to append the reminder to the day. (The day and the reminder have been kept separate up to this point.)
//
// Of course, there are always a few minor complications. For example, we want the days to be right-justified in a two-character field, so that their ones digit will line up. There are many ways to handle the problem. I've chosen to have the program use scanf to read the day into an integer variable, then call sprintf to convert the day back into string form. sprintf is a library function that's similar to printf, except that it writes output into a string. The call 
//    sprintf(day_str, "%2d", day);
// writes the value of day into day_str. Since sprintf automatically adds a null character when it's through writing, day_str will contain a properly null-terminated string.
//
// Another complication is making sure that the user doesn't enter more than two digits. We'll use the following call of scanf for this purpose:
//    scanf("%2d", &day);
// The number 2 between % and d tells scanf to stop reading after two digits, even if the input has more digits.

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50     /* maximum number of reminders */
#define MSG_LEN 60        /* max length of reminder message */

int read_line (char *arr, int size);

int main (void) {

  char reminders[MAX_REMIND][MSG_LEN+3];
  char day_str[3];
  char msg_str[MSG_LEN+1];
  int day, i, j;
  int num_remind = 0;

  for (;;) {
    // check if the number of reminders entered by the user are less than that defined in MAX_REMIND
    if (num_remind >= MAX_REMIND) {
      printf("-- FULL: CANNOT STORE MORE REMINDERS --\n");
      break;
    }
    // Prompt the user to enter a day and a reminder
    // store the date entered in the day variable first
    // if the day entered is zero, we know that the program needs to be terminated
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0) {
      break;
    }
    // sprintf takes the 2 digits from the day variable and puts it into the day_str char array
    // if the user entered a single digit instead of a two digit number
    // the number is stored in day_str as a right justified, i.e. if 5 is entered, day_str will hold it as " 5"
    // to make it left justified, we could probably use sprintf(day_str, "%-2d", day);
    sprintf(day_str, "%2d", day);
    // read_line takes the msg_str array and takes MSG_LEN as the size, and it will read all the characters
    read_line(msg_str, MSG_LEN);

    // this for loop block essentially traverses the n reminders we have added in the reminders two-dimensional array
    // it compares the day_str with reminders[i] string, which is less than 0 when:
    // - say that day_str is 8, and the reminders[i] has `9 Get better`
    // - say that day_str is 8, and the reminders[i] has `8 Get Rickrolled`
    // since 8 is less than 9, it will make the result of strcmp less than 0.
    // since the seond example has other characters than the character 8, it will result the strcmp to have value less than 0.
    // if non of the strings are less than the ones in reminders[i], it just increases i.
    // note that the third expression is not evaluated if the break statement is encountered!
    // Consider that reminders with day 5, 10, and 20 are already added
    // Now another input is given as:
    //    Enter day and reminder: 26 Movie - "Chinatown"
    // Now the loop occurs as follows:
    // It first checks 26 with `5 <reminder>`
    // 5 is stored as ` 5`, and since the space has a character number less than any digits, the strcmp function will return >0 value, so it increments i again 
    // when it encounters `10 <reminder>`, since `10` < `26`, the strcmp function will still return >0 value, so i is again incremented
    // when it encounters `20 <reminder>`, since `20` < `26`, while 2 is the same for both, but 0 is less than 6, the strcmp function will again >0 value, and then again increments i.
    // by this time, i should be equal to num_remind, so the loop terminates
    for (i = 0; i < num_remind; i++) {
      // for (char *k = day_str; k < (day_str+3); k++) {
      //   printf("%c", *k);
      // }
      // printf("\n");
      // for (char *l = reminders[i]; l < (reminders[i] + MSG_LEN); l++) {
      //   if (*l == '\0') {
      //     break;
      //   }
      //   printf("%c", *l);
      // }
      // printf("\n");
      if (strcmp(day_str, reminders[i]) < 0) {
        break;
      }
    }

    // note that i still retains the value from the above for loop!
    // after we find a day_str which is less than the one in reminders[i]
    // or not, the for loop will adjust the array of strings
    // consider the two reminders added:
    //    Enter day and reminder: 24 Susan's birthday
    //    Enter day and reminder: 5 6:00 - Dinner with Marge and Russ
    // The first reminder is not evaluated in either of the for loop
    // When the second reminder is taken from the user,
    // the for loop above breaks at the first iteration since reminders will have more characters than day_str--which has 5 in this case.
    // since i will be 0 and num_remind will be 1, which is assigned to the variable j
    // now strcpy(reminders[j], reminders[j-1]) -> strcpy(reminders[1], reminders[0]) -> copy the string of reminders[0] and put it to reminders[1]
    // and then since i is 0, the below two string functions--strcpy and strcat--will add the second reminder in reminders[0]
    // Consider the third example
    //    Enter day and reminder: 5 Saturday class
    // When the event is added, since it will be less than reminders[0] which holds `5 6:00 -Dinner...` since there are more characters present
    // i will still be 0
    // Now, it goes to this loop, where j is assigned the value of num_remind which i 2
    // strcpy(reminders[2], reminders[1]) which updates the `24 Sus...` reminder into reminders[2]
    // it will iterate again, and this time j = 1
    // strcpy(reminders[1], reminders[0]) which updates the `5 6:00...` reminder into reminders[1]
    // when j = 0, the conditional expression does not hold true, so the loop breaks out
    // and since i is 0, `5 Sat...` will be stored in reminders[0]
    for (j = num_remind; j > i; j--) {
      strcpy(reminders[j], reminders[j-1]);
    }

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

