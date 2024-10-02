// Q. Consider the following "mystery" function:
//    void pb (int n) {
//      if (n != 0) {
//        pb(n / 2);
//        putchar('0' + n % 2);
//      }
//    }
// Trace the execution of the function by hand. Then write a program that calls the function, passing it as a number entered by the user. What does the function do?
//
// Trace (taking n as 10):
// pb(10) is called, since n is not equal to 0, the body inside if statement runs, calling pb(5) first;
//  pb(5) is called, since n is not equal to 0, the body inside if statement runs, calling pb(2) first;
//    pb(2) is called, since n is not equal to 0, the body inside the if statement runs, calling pb(1) first;
//      pb(1) is called, since n is not equal to 0, the body inside the if statement runs, calling pb(0) first;
//        pb(0) is called, since n is equal to 0, the if statement does not hold true, so the function ends here and resumes to pb(1);
//      pb(1) is resumed, the putchar statement is executed: putchar('0' + 1 % 2) -> putchar('0' + 1) -> 1, and the function ends, and resumes to pb(2);
//    pb(2) is resumed, the putchar statement is executed: putchar('0' + 2 % 2) -> putchar('0' + 0) -> 0, and the function ends, and resumes to pb(5);
//  pb(5) is resumed, the putchar statement is executed: putchar('0' + 5 % 2) -> putchar('0' + 1) -> 1, and the function ends, and resumes to pb(10);
// pb(10) is resumed, the putchar statement is executed: putchar('0' + 10 % 2) -> putchar('0' + 0) -> 0, and the function ends, and the function call from main/other-function ends.
// the final result of calling pb(10) is: 1010 (which is essentially a binary representation of the decimal number 10)
// the pb most probably stands for print_binary lol

#include <stdio.h>

void pb (int decimal_number);

int main (void) {

  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  printf("The binary representation of %d is: ", num);

  pb(num);

  printf("\n");

  return 0;
}

void pb (int n) {
  if (n != 0) {
    pb(n / 2);
    putchar('0' + n % 2);
  }
}
