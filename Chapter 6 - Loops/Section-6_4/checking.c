// Develop a program that maintains a checkbook balance. The program will offer the user a menu of cmds: clear the account balance, credit money to the account, debit money from the account, display the current balance, and exit the program. The choices are represented by the integers 0, 1, 2, 3, and 4 respectively. 

#include <stdio.h>

int main (void) {

  float balance = 0.00f, money = 0.00f;
  int cmd;

  printf("*** ACME checkbook-balancing program ***\n");
  printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");

  for (;;) {
    printf("Enter command: ");
    scanf("%d", &cmd);

    // The program runs on an infinte loop whenever we enter any non-integer character. [Opinion] This is because the character entered is first given to the switch statement, since it does not match any of the defined case, it goes to the default option, but since the character cannot be stored in an integer variable, cmd does not even store the non-integer character entered, but the input buffer contains the character so it runs on an infinite loop
    // Enter command -> *Enters non-integer character* -> scanf puts the non-integer character back to input buffer -> switch command is called -> cmd has initial garbage value -> goes to default label -> breaks from switch -> again enters the printf and scanf statement -> since the non-integer character is still present -> repeats everthing again

    switch (cmd) {
      case 0:
        balance = 0.00f;
        break;
      case 1:
        printf("Enter amount of credit: ");
        scanf("%f", &money);
        balance += money;
        break;
      case 2:
        printf("Enter amount of debit: ");
        scanf("%f", &money);
        balance -= money;
        break;
      case 3:
        printf("Current balance: %.2f\n", balance);
        break;
      case 4:
        return 0;
      default:
        printf("ERROR: Invalid command detected, please use one of the specified command.\n");
        break;
    }
  }

  return 0;
}

