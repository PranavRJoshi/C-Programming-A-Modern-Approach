// Q. Write a program that evaluates an expression:
//    Enter an expression: 1+2.5*3
//    Value of expression: 10.5
// The operands in the expression are floating-point numbers; the operators are +, -, *, and /. The expression is evaluated from left to right (no operator takes precedence over any other operator).

#include <stdio.h>

int main (void) {

  float operand_1, operand_2;
  int decimal_1, decimal_2;
  decimal_1 = 0;
  decimal_2 = 0;
  operand_1 = 0.0f;
  operand_2 = 0.0f;
  int temp_fractional;
  float fraction;
  float divisor = 1.0f;
  char ch, operator;

  printf("Enter an expression: ");

  while (1) {
    
    // This conditional statement is called only once, and later on, the result of the operation is stored in operand_1
    if (operand_1 == 0.0f) {
      // gets the inital character from the input stream
      ch = getchar();
      while ((ch >= '0' && ch <= '9') || ch == '.') {
        // checks if the character is a decimal, if yes, store it in a new variable to calculate decimal value
        if (ch == '.') {
          // The current character will be a decimal point, so we need to get the next character
          ch = getchar();
          while (ch >= '0' && ch <= '9') {
            decimal_1 = (decimal_1 * 10) + (ch - '0');
            ch = getchar();
          }
          // when all the decimal digits are accumulated, break is needed to get out of the parent loop
          break;
        }
        // this will be used to store the digits that come before the decimal point
        operand_1 = (operand_1 * 10) + (ch - '0');
        ch = getchar();
      }
      // The code below is used to adjust the decimal point in operand_1
      // like, if the number if 12.34
      // operand_1 holds 12 and decimal_1 hold 34
      // the code below results in operand_1 having the value 12.34
      temp_fractional = decimal_1;
      while (temp_fractional != 0) {
        temp_fractional /= 10;
        divisor *= 10;
      }

      fraction = decimal_1 / divisor;
      operand_1 = operand_1 + fraction;
    }

    // the code below will run till a new line is found in the input stream.

    // since the loop above terminates due to the fact that the character isn't a number or a decimal point
    // the variable ch still holds the operator sign, so we need to first put it into operator variable
    operator = ch;
    // fetch the new character for the second operand
    ch = getchar();

    while ((ch >= '0' && ch <= '9') || ch == '.') {
      // if the operand contains decimal point, the digits after the decimal point is stored here
      if (ch == '.') {
        ch = getchar();
        while (ch >= '0' && ch <= '9') {
          decimal_2 = (decimal_2 * 10) + (ch - '0');
          ch = getchar();
        }
        break;
      }
      // this stores the number that comes before the decimal point.
      operand_2 = (operand_2 * 10) + (ch - '0');
      ch = getchar();
    }
    // when this loop terminates, ideally, the character stored in ch will still be an operator (since it's the reason the loop was terminated).
    // so there's no reason to fetch another character using getchar.

    // This block of code also adjusts the decimal point to operand_2, similar to how it was done for operand_1
    divisor = 1.0f;
    temp_fractional = decimal_2;
    while (temp_fractional != 0) {
      temp_fractional /= 10;
      divisor *= 10;
    }

    fraction = decimal_2 / divisor;
    operand_2 = operand_2 + fraction;

    // the code to perform sequential arithemtic operation between operators.
    // it does not care about the operator precedence, as stated by the question.
    switch (operator) {
      case '+':
        operand_1 = operand_1 + operand_2;
        break;
      case '-':
        operand_1 = operand_1 - operand_2;
        break;
      case '*':
        operand_1 = operand_1 * operand_2;
        break;
      case '/':
        operand_1 = operand_1 / operand_2;
        break;
    }

    // if ch holds a line break symbol rather than an operator, the loop terminates.
    if (ch == '\n') {
      break;
    } 

    // these variables are refreshed as they will be used to hold future operands.
    operand_2 = 0.0f;
    decimal_2 = 0;
  }

  printf("The value of expression is: %.2f\n", operand_1);

  return 0;
}


