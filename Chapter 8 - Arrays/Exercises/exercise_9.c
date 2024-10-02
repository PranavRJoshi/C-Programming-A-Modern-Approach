// Q. Using the array of Exercise 8, write a program fragment that computes the average temperature for a month (averaged over all days of the month and all hours of the day).

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define OUTER_SIZE (int) (sizeof(temperature_readings) / sizeof(temperature_readings[0]))
#define INNER_SIZE (int) (sizeof(temperature_readings[0]) / sizeof(temperature_readings[0][0]))

int main (void) {

  int temperature_readings[30][24] = {0};
  double average_temperature = 0.0;

  // gonna add random temperature for now, using time as a seed for srand and generating random numbers using the rand function
  srand((unsigned int) time(NULL));

  for (int i = 0; i < OUTER_SIZE; i++) {
    for (int j = 0; j < INNER_SIZE; j++) {
      temperature_readings[i][j] = rand() % 101;    /* adjusting the temperature in the range of 0 to 100 */
      average_temperature += temperature_readings[i][j];
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

  // calculate the average temperature over the span of 30 days for temperatures recorded hourly
  average_temperature /= (OUTER_SIZE * INNER_SIZE);

  printf("The average temperature throughout the month is: %.2lf\n", average_temperature);

  return 0;
}

