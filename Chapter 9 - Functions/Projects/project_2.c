// Q. Modify Programming Project 5 from Chapter 5 so that it uses a function to compute the amount of income tax. When passed an amount of taxable income, the function will return the tax due.

#include <stdio.h>

double calculate_tax (double taxable_income);

int main (void) {

  double income = 0.0;
  double tax_amount = 0.0;

  printf("Enter the income: ");
  scanf("%lf", &income);

  tax_amount = calculate_tax(income);

  printf("The tax amount for the income %.2lf is: %.2lf\n", income, tax_amount);

  return 0;
}

double calculate_tax (double income) {

  // it is not required that we make a specific variable to store the tax amount
  // we could have just used the return statement after each if statement
  // but many return statement looks rather not clean
  double tax_amount = 0.0;

  if (income < 750.00) {
      tax_amount = 0.01 * income;
  } else if (income <= 2250.00) {
      tax_amount = 7.50 + (0.02 * (income - 750.00));
  } else if (income <= 3750.00) {
      tax_amount = 37.50 + (0.03 * (income - 2250.00));
  } else if (income <= 5250.00) {
      tax_amount = 82.50 + (0.04 * (income - 3750.00));
  } else if (income <= 7000.00) {
      tax_amount = 142.50 + (0.05 * (income - 5250.00));
  } else if (income > 7000.00) {
      tax_amount = 230.00 + (0.06 * (income - 7000.00));
  }
  
  return tax_amount;
}

