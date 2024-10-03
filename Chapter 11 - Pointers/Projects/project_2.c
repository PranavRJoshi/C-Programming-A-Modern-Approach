// Q. Modify Programming Project 8 from Chapter 5 so that it includes the following function:
//    void find_closest_flight (int desired_time, int *departure_time, int *arrival_time);
// This function will find the flight whose departure time is closest to desired_time (expressed in minutes since midnight). It will store the departure and arrival times of this flight (also expressed in minutes since midnight) in the variables pointed to by departure_time and arrival_time, respectively.

#include <stdio.h>
#include <stdbool.h>

void find_closest_flight (int desired_time, int *departure_time, int *arrival_time);

int main (void) {

  int user_time = 0;
  int hour, min;

  int departure_time, arrival_time;

  printf("Enter the time in 24 hour format (hh:mm): ");
  scanf("%d:%d", &hour, &min);

  user_time = hour * 60 + min;

  find_closest_flight(user_time, &departure_time, &arrival_time);

  printf("The closest departure time is %.2d:%.2d and the corresponding arrival time is: %.2d:%.2d\n", departure_time / 60, departure_time % 60, arrival_time / 60, arrival_time % 60);

  return 0;
}

void find_closest_flight (int desired_time, int *departure_time, int *arrival_time) {
  // store the departure time 
  int departure_time_arr[8] = {8*60, 9*60+43, 11*60+19, 12*60+47, 14*60, 15*60+45, 19*60, 21*60+45};
  // store the arrival time
  int arrival_time_arr[8] = {10*60+16, 11*60+52, 13*60+31, 15*60, 16*60+8, 17*60+55, 21*60+20, 23*60+58};

  bool is_edge_case = true;

  for (int i = 1; i < 8; i++) {
    // if we found the departure time that is closest to the user given time, we store the respective departure time and 
    // the index of the corresponding arrival time and break out of the loop
    if (desired_time - departure_time_arr[i-1] < departure_time_arr[i] - desired_time) {
      *departure_time = departure_time_arr[i-1];
      *arrival_time = arrival_time_arr[i-1];
      is_edge_case = false;
      break;
    }
  }

  if (is_edge_case) {
    *departure_time = departure_time_arr[7];
    *arrival_time   = arrival_time_arr[7];
  }
}

