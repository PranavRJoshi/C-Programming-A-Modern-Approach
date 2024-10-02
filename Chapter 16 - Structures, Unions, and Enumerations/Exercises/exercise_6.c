// Q. Write the following function, assuming that the time structure contains three members: hours, minutes, and seconds (all of type int).
//      struct time split_time (long total_seconds);
// total_seconds is a time represented as the number of seconds since midnight. The function returns a structure containing the equivalent time in hours (0-23), minutes (0-59), and seconds (0-59).

#include <stdio.h>

/*
 * time:  A structure that contains the members hours (int), minutes (int),
 *        and hours (int).
*/
struct time {
  int hours;
  int minutes;
  int seconds;
};

/*
 * split_time:  total_seconds is a time represented as the number of seconds since
 *              midnight. The function returns a structure containing the equivalent
 *              time in hours (0-23), minutes (0-59), and seconds (0-59).
*/
struct time split_time (long total_seconds);

/*
 * clear_imput_stream:  clears the standard input stream. will also work
 *                      for files that have EOF as the last character.
*/
void clear_input_stream (void);

int main (void) {

  long total_seconds = 0;

  printf("Enter the time elapsed in seconds: ");
  while (scanf("%ld", &total_seconds) != 1 || total_seconds < 0 || total_seconds > 86400) {
    if (total_seconds < 0) {
      printf("[ERROR] Input time underflow.\nTry Again: ");
      continue;
    }
    if (total_seconds > 86400) {
      printf("[ERROR] Input time overflow.\nTry Again: ");
      continue;
    }
    printf("[ERROR] Not all input field provided.\nTry Again: ");
    clear_input_stream();
  }

  struct time t;

  t = split_time(total_seconds);

  printf("The time in hh:mm:ss format is: %.2d:%.2d:%.2d\n", t.hours, t.minutes, t.seconds);

  return 0;
}

struct time split_time (long ts) {
  struct time temp;

  temp.hours = (int) ((ts / 60) / 60);
  ts = ts % (60 * 60);
  temp.minutes = (int) (ts / 60);
  ts = ts % 60;
  temp.seconds = (int) ts;

  return temp;
}

void clear_input_stream (void) {
  int ch = getchar();
  
  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

