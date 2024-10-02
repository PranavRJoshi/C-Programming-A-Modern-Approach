// Q. Our next program prints a table showing a value of $100 invested at different rates of interest over a period of years. The user will enter an interest rate and the number of years the money will be invested. The table will show the value of the money at one-year intervals--at that interest rate and the next four higher rates--assuming that interest is compounded once a year. Here's what a session with the program will look like:
//    Enter interest rate: 6
//    Enter number of years: 5
//
//    Years       6%        7%        8%        9%        10%
//      1       106.00    107.00    108.00    109.00    110.00
//      2       112.36    114.49    116.64    118.81    121.00
//      3       119.10    122.50    125.97    129.50    133.10
//      4       126.25    131.08    136.05    141.16    146.41
//      5       133.82    140.26    146.93    153.86    161.05
// Clearly, we can use for statement to print the first row. The second row is a little trickier, since it's values depend on the numbers in the first row. Our solution is to store the first row in an array as it's computed, then use the values in the array to compute the second row. Of course, this process can be repeated for the third and later rows. We'll end up with two for statements, one nested inside the other. The outer loop will count from 1 to the number of years requested by the user. The inner loop will increment the rate of interest from it's lowest value to it's highest value.

#include <stdio.h>
#include <strings.h>

#define NUM_RATES (int) (sizeof(amount_after_interest) / sizeof(amount_after_interest[0]))

int main (void) {

  int interest_rate;
  int number_of_years;

  // a array initialized by both element-by-element initialization and designated initialization method
  // not necessarily for anything special, just wanted to use the things I'm learning
  double amount_after_interest[5] = {100.00, 100.00, [2] = 100.00, 100.00, [4] = 100.00};

  printf("Enter interest rate: ");
  scanf("%d", &interest_rate);
  printf("Enter number of years: ");
  scanf("%d", &number_of_years);

  printf("Years");
  // NUM_RATES in this case will be 5
  for (int i = 0; i < NUM_RATES; i++) {
    printf("%6d%%", NUM_RATES+i);
  }

  printf("\n");

  for (int year = 1; year <= number_of_years; year++) {
    printf("%3d    ", year);
    for (int j = 0; j < NUM_RATES; j++) {
      amount_after_interest[j] = (amount_after_interest[j] + ((((double) (interest_rate+j)) / 100) * amount_after_interest[j]));
      printf("%7.2lf", amount_after_interest[j]);
    }
    printf("\n");
  }

  return 0;
}

