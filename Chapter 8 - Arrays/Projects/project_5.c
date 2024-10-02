// Q. Modify the interest.c program of Section 8.1 so that it compounds interest monthly instead of annually. The form of the output shouldn't change; the balance should still be shown at annual intervals.

#include <stdio.h>
#include <strings.h>

#define NUM_RATES (int) (sizeof(amount_after_interest) / sizeof(amount_after_interest[0]))

int main (void) {

  int interest_rate;
  int number_of_years;

  // a array initialized by both element-by-element initialization and designated initialization method
  // not necessarily for anything special, just wanted to use the things I'm learning
  double amount_after_interest[5] = {100.00, 100.00, [2] = 100.00, 100.00, [4] = 100.00};

  printf("Enter monthly interest rate: ");
  scanf("%d", &interest_rate);
  printf("Enter number of years: ");
  scanf("%d", &number_of_years);

  printf("Years");
  // NUM_RATES in this case will be 5
  for (int i = 0; i < NUM_RATES; i++) {
    printf("%15d%%", NUM_RATES+i);
  }

  printf("\n");

  // keeps track of the number_of_years the interest should be computed
  for (int year = 1; year <= number_of_years; year++) {
    printf("%3d    ", year);
    // keeps track of the amount after interest for the given interest rate and the next four incremented interest rate
    for (int j = 0; j < NUM_RATES; j++) {
      // keeps track of the interest that is compounded monthly
      for (int month = 1; month <= 12; month++) {
        amount_after_interest[j] = (amount_after_interest[j] + ((((double) (interest_rate+j)) / 100) * amount_after_interest[j]));
      }
      printf("%16.2lf", amount_after_interest[j]);
    }
    printf("\n");
  }

  return 0;
}

