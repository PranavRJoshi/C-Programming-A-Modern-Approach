// Q. When stocks are sold or purchased through a broker, the broker's commission is often computed using a sliding scale that depends upon the value of the stocks traded. Let's say that a broker charges the amounts shown in the following table:
// Transaction size             Commission rate
// Under $2,500                 $30 + 1.7%
// $2,500-$6,250                $56 + 0.66%
// $6,250-$20,000               $76 + 0.34%
// $20,000-$50,000              $100 + 0.22%
// $50,000-$500,000             $155 + 0.11%
// Over $500,000                $255 + 0.09%
// The minimum charge is $39. Our next program asks the user to enter the amount of the trade, then displays the amount of the commission:
// Enter value of trade: 30000
// Commission: $166.00
// The heart of the program is a cascaded if statement that determines which range the trade falls into

#include <stdio.h>

int main (void) {

    float transaction_size, commission_rate = 0;

    printf("Enter value of trade: ");
    scanf("%f", &transaction_size);

    if (transaction_size < 2500) {
        commission_rate = 30.00f + 0.017f * transaction_size;
    } else if (transaction_size >= 2500 && transaction_size < 6250) {
        // the frist expression is kinda redundant, so it won't matter if "transaction_size >= 2500" is written or not. Same goes for below expressions too.
        commission_rate = 56.00f + 0.0066f * transaction_size;
    } else if (transaction_size >= 6250 && transaction_size < 20000) {
        commission_rate = 76.00f + 0.0034f * transaction_size;
    } else if (transaction_size >= 20000 && transaction_size < 50000) {
        commission_rate = 100.00f + 0.0022f * transaction_size;
    } else if (transaction_size >= 50000 && transaction_size < 500000) {
        commission_rate = 155.00f + 0.0011f * transaction_size;
    } else if (transaction_size >= 500000) {
        commission_rate = 255.00f + 0.0009f * transaction_size;
    }

    if (commission_rate < 39.00f) {
        commission_rate = 39.00f;
    }

    printf("Commission: %.2f\n", commission_rate);

    return 0;
}
