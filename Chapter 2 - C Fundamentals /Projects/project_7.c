#include <stdio.h>

int main (void) {
    int amount = 0;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    int twenty_bill_count = amount / 20;
    amount = amount - twenty_bill_count * 20;
    // amount = amount % 20;
    int ten_bill_count = amount / 10;
    amount = amount - ten_bill_count * 10;
    // amount = amount % 10;
    int five_bill_count = amount / 5;
    amount = amount - five_bill_count * 5;
    // amount = amount % 5;
    int one_bill_count = amount / 1;
    amount = amount - one_bill_count * 1;
    // amount = amount % 1;

    printf("$20 bills: %d\n", twenty_bill_count);
    printf("$10 bills: %d\n", ten_bill_count);
    printf("$5 bills: %d\n", five_bill_count);
    printf("$1 bills: %d\n", one_bill_count);

    return 0;
}
