// Q. Modify Programming Project 7 from Chapter 2 so that it includes the following function:
//    void pay_amount (int dollars, int *twneties, int *tens, int *fives, int *ones);
// The function determines the smallest number of $20, $10, $5, and $1 bills necessary to pay the amount represented by the dollars parameter. The twenties parameter points to a variable in which the function will store the number of $20 bills required. The tens, fives, and ones parameter are similar.

#include <stdio.h>

void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones);

int main (void) {

  int dollars, twenties_bill, tens_bill, fives_bill, ones_bill;

  printf("Enter the amount in dollar: ");
  scanf("%d", &dollars);

  pay_amount(dollars, &twenties_bill, &tens_bill, &fives_bill, &ones_bill);

  printf("The amount split into 20, 10, 5, and 1 dollar bills.\n");
  printf("20 dollar bills: %d\n", twenties_bill);
  printf("10 dollar bills: %d\n", tens_bill);
  printf(" 5 dollar bills: %d\n", fives_bill);
  printf(" 1 dollar bills: %d\n", ones_bill);

  return 0;
}

void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones) {
  *twenties = dollars / 20;
  dollars = dollars - (20 * (*twenties));
  *tens = dollars / 10;
  dollars = dollars - (10 * (*tens));
  *fives = dollars / 5;
  dollars = dollars - (5 * (*fives));
  *ones = dollars / 1;
  dollars = dollars - (1 * (*ones));
}
