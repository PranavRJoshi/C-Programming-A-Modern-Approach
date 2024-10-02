// Q. Modify Programming Porject 8 from Chapter 5 so that the departure times are stored in an array and the arrival times are stored in a second array. (The times are integers, representing the number of minutes since midnight.) The program will use a loop to search the array of departure times for the one closest to the time entered by the user.

/*
 *
 *  Departure time              Arrival time
 *  8:00 a.m.                   10:16 a.m.
 *  9:43 a.m.                   11:52 a.m.
 *  11:19 a.m.                  1:31  p.m.
 *  12:47 p.m.                  3:00  p.m.
 *  2:00 p.m.                   4:08  p.m.
 *  3:45 p.m.                   5:55  p.m.
 *  7:00 p.m.                   9:20  p.m.
 *  9:45 p.m.                   11:58 p.m.
 * 
 * */

#include <stdio.h>

int main (void) {

  // store the departure time 
  int departure_time[8] = {8*60, 9*60+43, 11*60+19, 12*60+47, 14*60, 3*60+45, 19*60, 21*60+45};
  // store the arrival time
  int arrival_time[8] = {10*60+16, 11*60+52, 13*60+31, 15*60, 16*60+8, 17*60+55, 21*60+20, 23*60+58};

  // store the hour and minute entered by the user
  int hour, minute;
  // calculate the current user time from hour and minute
  int user_current_time;
  // these three variables are used to store the closest departure time, it's hour and minute
  int user_closest_departure = 0;
  int user_departure_hour = 0;
  int user_departure_minute = 0;
  // these three variables store the index for the respective arrival time, it's hour and minute 
  int arrival_time_index = 0;
  int arrival_time_hour = 0;
  int arrival_time_minute = 0;

  printf("Enter time in 24 hour format (hh:mm): ");
  scanf("%d:%d", &hour, &minute);

  user_current_time = hour * 60 + minute;

  for (int i = 1; i < 8; i++) {
    // if we found the departure time that is closest to the user given time, we store the respective departure time and 
    // the index of the corresponding arrival time and break out of the loop
    if (user_current_time - departure_time[i-1] < departure_time[i] - user_current_time) {
      user_closest_departure = departure_time[i-1];
      arrival_time_index = i-1;
      break;
    }
  }

  // convert the arrival time to hour and minute, in 24 hour format
  arrival_time_hour = arrival_time[arrival_time_index] / 60;
  arrival_time_minute = arrival_time[arrival_time_index] % 60;

  // convert the departure time to hour and minute, in 24 hour format
  user_departure_hour = user_closest_departure / 60;
  user_departure_minute = user_closest_departure % 60;

  printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", user_departure_hour, user_departure_minute, arrival_time_hour, arrival_time_minute);

  return 0;
}

