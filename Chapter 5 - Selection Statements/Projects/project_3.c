// Q. Modify the broker.c program of Section 5.2 by making both of the following changes:
// a. Ask the user to enter the number of shares and the price per share, instead of the value of the trade 
// b. Add statements that compute the commission charged by a rival broker ($33 plus 3 cent per share for fewer than 2000 shares; $33 plus 2 cent per share for 2000 shares or more). Display the rival's commission as well as the commission charged by the original broker.

#include <stdio.h>

int main (void) {

    int share_count;
    float price_per_share, transaction_value;
    float commission_original = 0.00f, commission_rival = 33.00f;

    printf("Enter the number of shares: ");
    scanf("%d", &share_count);

    printf("Enter the price per share: ");
    scanf("%f", &price_per_share);

    // Calculating original commission fee (from Section 5.2)

    transaction_value = share_count * price_per_share;

    if (transaction_value < 2500) {
        commission_original = 30.00f + 0.017f * transaction_value;
    } else if (transaction_value < 6250) {
        commission_original = 56.00f + 0.0066f * transaction_value;
    } else if (transaction_value < 20000) {
        commission_original = 76.00f + 0.0034f * transaction_value;
    } else if (transaction_value < 50000) {
        commission_original = 100.00f + 0.0022f * transaction_value;
    } else if (transaction_value < 500000) {
        commission_original = 155.00f + 0.0011f * transaction_value;
    } else if (transaction_value >= 500000) {
        commission_original = 255.00f + 0.0009f * transaction_value;
    }

    if (commission_original < 39.00f) {
        commission_original = 39.00f;
    }

    // Calculating rival commission fee

    if (share_count < 2000) {
        commission_rival += (0.03f * share_count);
    } else {
        commission_rival += (0.02f * share_count);
    }

    printf("Commision from the original broker: %.2f\n", commission_original);
    printf("Commision from the rival broker: %.2f\n", commission_rival);

    return 0;
}
