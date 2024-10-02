// Q. Add a loop to the broker.c program of Section 5.2 so that the user can enter more than one trade and the program will calculate the commission on each. The program should terminate when the user enters 0 as the trade value:
//    Enter value of trade: 30000
//    Commission: $166.00
//
//    Enter value of trade: 20000
//    Commission: $144.00
//
//    Enter value of trade: 0

#include <stdio.h>

int main (void) {

  float transaction_size, commission_rate = 0;

  for (;;) {
    printf("Enter value of trade: ");
    scanf("%f", &transaction_size);

    if (transaction_size == 0.00f)
      break;

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

    printf("Commission: %.2f\n\n", commission_rate);
  }

  return 0;
}

