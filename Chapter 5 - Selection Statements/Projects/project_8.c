// Q. The following table shows the daily flights from one city to another:
//  Departure time              Arrival time
//  8:00 a.m.                   10:16 a.m.
//  9:43 a.m.                   11:52 a.m.
//  11:19 a.m.                  1:31  p.m.
//  12:47 p.m.                  3:00  p.m.
//  2:00 p.m.                   4:08  p.m.
//  3:45 p.m.                   5:55  p.m.
//  7:00 p.m.                   9:20  p.m.
//  9:45 p.m.                   11:58 p.m.
// Write a program that asks user to enter a time (expressed in hours and minutes, using the 24-hour clock). The program then displays the departure and arrival time for the flights whose departure time is closest to that entered by the user:
//  Enter a 24-hour time: 13:15
//  Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
// Hint: Convert the input into a time expressed in minutes since midnight, and compare it to the departure times, also expressed in minutes since midnight. For example, 13:15 is 13*60+15 = 795 minutes since midnight, which is closer to 12:47 p.m. (767 minutes since midnight) than to any of the other departure times.

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

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

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
