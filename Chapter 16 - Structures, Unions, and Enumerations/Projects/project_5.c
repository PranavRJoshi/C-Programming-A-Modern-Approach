// Q. Modify Programming Project 8 from Chapter 5 so that the times are stored in a single array. The elements of the array will be structures, each containing a departure time and the corresponding arrival time. (Each time will be an integer, representing the number of minutes since midnight.) The program will use a loop to search the array for the departure time closest to the time entered by the user.

//  Departure time              Arrival time
//  8:00 a.m.                   10:16 a.m.
//  9:43 a.m.                   11:52 a.m.
//  11:19 a.m.                  1:31  p.m.
//  12:47 p.m.                  3:00  p.m.
//  2:00 p.m.                   4:08  p.m.
//  3:45 p.m.                   5:55  p.m.
//  7:00 p.m.                   9:20  p.m.
//  9:45 p.m.                   11:58 p.m.

#include <stdio.h>
#include <stdbool.h>

// struct flight {
//   int departure_time;
//   int arrival_time;
// } flight_time[] = {[0].departure_time = 8  * 60,       [0].arrival_time = 10 * 60 + 16,
//                    [1].departure_time = 9  * 60 + 43,  [1].arrival_time = 11 * 60 + 52,
//                    [2].departure_time = 11 * 60 + 19,  [2].arrival_time = 13 * 60 + 31,
//                    [3].departure_time = 12 * 60 + 47,  [3].arrival_time = 15 * 60,
//                    [4].departure_time = 14 * 60,       [4].arrival_time = 16 * 60 + 8,
//                    [5].departure_time = 15 * 60 + 45,  [5].arrival_time = 17 * 60 + 55,
//                    [6].departure_time = 19 * 60,       [6].arrival_time = 21 * 60 + 20,
//                    [7].departure_time = 21 * 60 + 45,  [7].arrival_time = 23 * 60 + 58};

struct flight {
  int departure_time;
  int arrival_time;
};

const struct flight flight_time[] = {{8  * 60,       10 * 60 + 16},
                                     {9  * 60 + 43,  11 * 60 + 52},
                                     {11 * 60 + 19,  13 * 60 + 31},
                                     {12 * 60 + 47,  15 * 60},
                                     {14 * 60,       16 * 60 + 8},
                                     {15 * 60 + 45,  17 * 60 + 55},
                                     {19 * 60,       21 * 60 + 20},
                                     {21 * 60 + 45,  23 * 60 + 58}};


void search_departure_time (int current_time);

/*
 * clear_input_stream:  Clears the current input stream if there are any characters 
 *                      left in the input buffer. Also works for file have EOF.
*/
void clear_input_stream (void);

int main (void) {

  int scanf_return_count = 0;
  int hour = 0, minute = 0;
  int current_time = 0;

  for (;;) {
    printf("Enter a 24-hour format time (in hh:mm): ");
    if ((scanf_return_count = scanf("%d:%d", &hour, &minute)) != 2) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    if (hour < 0 || hour > 23) {
      fprintf(stderr, "[ERROR] Hour Entered is Invalid.\n");
      clear_input_stream();
      continue;
    }
    if (minute < 0 || minute > 59 ) {
      fprintf(stderr, "[ERROR] Minute Entered is Invalid.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  current_time = hour * 60 + minute;

  search_departure_time(current_time);


  return 0;
}

void search_departure_time (int ct) {
  int i;
  int departure_hour, departure_minute, arrival_hour, arrival_minute;

  int time_diff_1, time_diff_2;
  int arr_size = (int) (sizeof(flight_time) / sizeof(flight_time[0]));
  bool is_edge_case = true;

  for (i = 1; i < arr_size; i++) {
    time_diff_1 = ct - flight_time[i - 1].departure_time;
    time_diff_2 = flight_time[i].departure_time - ct;
    if (time_diff_1 < time_diff_2) {
      departure_hour    = flight_time[i-1].departure_time / 60;
      departure_minute  = flight_time[i-1].departure_time % 60;
      arrival_hour      = flight_time[i-1].arrival_time   / 60;
      arrival_minute    = flight_time[i-1].arrival_time   % 60;
      printf("The closest departure time is: %.2d:%.2d, arriving at: %.2d:%.2d\n", departure_hour, departure_minute, arrival_hour, arrival_minute);
      is_edge_case = false;
      break;
    } 
  }

  if (is_edge_case) {
    departure_hour    = flight_time[arr_size - 1].departure_time / 60;
    departure_minute  = flight_time[arr_size - 1].departure_time % 60;
    arrival_hour      = flight_time[arr_size - 1].arrival_time   / 60;
    arrival_minute    = flight_time[arr_size - 1].arrival_time   % 60;
    printf("The closest departure time is: %.2d:%.2d, arriving at: %.2d:%.2d\n", departure_hour, departure_minute, arrival_hour, arrival_minute);
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

