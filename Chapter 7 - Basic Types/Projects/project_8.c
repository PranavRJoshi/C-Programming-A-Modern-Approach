// Modify Programming Project 8 from Chapter 5 so that the user enters a time using the 12-hour clock. The input will have the form hours: minutes followed by either A, P, AM, or PM (either lower-case or upper-case). White space is allowed (but not required) between the numerical time and the AM/PM indicator. Examples of valid input:
//    1:15P
//    1:15PM
//    1:15p
//    1:15pm
//    1:15 P
//    1:15 PM
//    1:15 p
//    1:15 pm
// You may assume that the input has one of these forms; there's no need to test for errors.

#include <stdio.h>

int main (void) {

  // declare departure time variables
  int departure_1, departure_2, departure_3, departure_4;
  int departure_5, departure_6, departure_7, departure_8;

  // initialize deprature time in minutes
  departure_1 = 8 * 60;
  departure_2 = 9 * 60 + 43;
  departure_3 = 11 * 60 + 19;
  departure_4 = 12 * 60 + 47;
  departure_5 = 14 * 60;
  departure_6 = 15 * 60 + 45;
  departure_7 = 19 * 60;
  departure_8 = 21 * 60 + 45;

  int hour, minute;
  int user_current_time;
  char ch;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &hour, &minute, &ch);

  if (ch == 'p' || ch == 'P') {
    hour += 12;
    if (hour == 24)
      hour = 12;
  }

  user_current_time = hour * 60 + minute;

  if ((user_current_time - departure_1) < (departure_2 - user_current_time)) {
      printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.");
  } else if ((user_current_time - departure_2) < (departure_3 - user_current_time)) {
      printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.");
  } else if ((user_current_time - departure_3) < (departure_4 - user_current_time)) {
      printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.");
  } else if ((user_current_time - departure_4) < (departure_5 - user_current_time)) {
      printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.");
  } else if ((user_current_time - departure_5) < (departure_6 - user_current_time)) {
      printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.");
  } else if ((user_current_time - departure_6) < (departure_7 - user_current_time)) {
      printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.");
  } else if ((user_current_time - departure_7) < (departure_8 - user_current_time)) {
      printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.");
  } else {
      printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.");
  }

  return 0;
  
}

