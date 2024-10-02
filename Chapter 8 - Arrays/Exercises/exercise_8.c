// Q. Write a declaration for a two-dimensional array named temperature_readings that stores one month of hourly temperature readings. (For simplicity, assume that a month has 30 days.) The rows of the array should represent days of the month; the columns should represent hours of the day.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define OUTER_SIZE (int) (sizeof(temperature_readings) / sizeof(temperature_readings[0]))
#define INNER_SIZE (int) (sizeof(temperature_readings[0]) / sizeof(temperature_readings[0][0]))

int main (void) {

  int temperature_readings[30][24] = {0};

  // gonna add random temperature for now, using time as a seed for srand and generating random numbers using the rand function
  srand((unsigned int) time(NULL));

  for (int i = 0; i < OUTER_SIZE; i++) {
    for (int j = 0; j < INNER_SIZE; j++) {
      temperature_readings[i][j] = rand() % 101;    /* adjusting the temperature in the range of 0 to 100 */
    }
  }

  // display the temperatures that were added
  for (int i = 0; i < OUTER_SIZE; i++) {
    printf("The temperature of day %3d is: ", i+1);
    for (int j = 0; j < INNER_SIZE; j++) {
      printf("%3d ", temperature_readings[i][j]); 
    }
    printf("\n");
  }

  return 0;
}

