// Q. Programming Project 8 in Chapter 2 asked you to write a program that calculates the remaining balance on a loan after the first, second, and third monthly payments. Modify the program so that it also asks the user to enter the number of payments and then displays the balance remaining after each of these payments.

#include <stdio.h>

int main (void) {

  float loan = 0.0f, interest_rate = 0.0f, monthly_payment = 0.0f;
  int num_of_months;

  printf("Enter amount of loan: ");
  scanf("%f", &loan);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);
  printf("Enter the number of monthly payments: ");
  scanf("%d", &num_of_months);

  float monthly_interest_rate = (interest_rate / 100) / 12;
  printf("Monthly interest rate is: %f\n", monthly_interest_rate);

  for (int i = 1; i <= num_of_months; i++) {
    loan = loan + loan * monthly_interest_rate - monthly_payment;
    printf("Balance remaining after the end of month %d: %.2f\n", i, loan);
  }

  return 0;
}

