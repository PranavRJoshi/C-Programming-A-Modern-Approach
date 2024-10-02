#include <stdio.h>

int main (void) {
    float loan = 0.0f, interest_rate = 0.0f, monthly_payment = 0.0f;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    float monthly_interest_rate = (interest_rate / 100) / 12;
    printf("Monthly interest rate is: %f\n", monthly_interest_rate);

    loan = loan + loan * monthly_interest_rate - monthly_payment;
    printf("Balance remaining after first payment: %.2f\n", loan);
    loan = loan + loan * monthly_interest_rate - monthly_payment;
    printf("Balance remaining after second payment: %.2f\n", loan);
    loan = loan + loan * monthly_interest_rate - monthly_payment;
    printf("Balance remaining after third payment: %.2f\n", loan);

    return 0;
}
