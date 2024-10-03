// Q. Write the following function:
//    void split_time (long total_sec, int *hr, int *min, int *sec);
// total_sec is a time represented as the number of seconds since midnight. hr, min, and sec are pointers to variables in which the variables in which the function will store the equivalent time in hours (0-23), minutes (0-59), and seconds (0-59), respectively.

#include <stdio.h>

void split_time (long total_sec, int *hr, int *min, int *sec);

int main (void) {

  long total_time;
  int hour, minute, second;

  printf("Enter a time in seconds since midnight: ");
  scanf("%ld", &total_time);

  split_time(total_time, &hour, &minute, &second);

  printf("The time in hr:min:sec is: %2d:%2d:%2d\n", hour, minute, second);

  return 0;
}

void split_time (long total_sec, int *hr, int *min, int *sec) {
  *hr = *min = *sec = 0;

  *hr = total_sec / (60 * 60);
  total_sec %= (60 * 60);
  *min = total_sec / 60;
  total_sec %= 60;
  *sec = total_sec;
}
