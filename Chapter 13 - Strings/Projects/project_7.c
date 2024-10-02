// Q. Modify Programminng Project 11 from Chapter 5 so that it uses arrays containing pointers to strings, instead of switch statements. For example, instead of using a switch statement to print the word for the first digit, use the digit as an index into an array that contains the strings "twenty", "thrity", and so forth.

#include <stdio.h>

int main (void) {

  int num;

  const char *twenty_to_ninety[] = {"Twenty",
                                    "Thrity",
                                    "Forty",
                                    "Fifty",
                                    "Sixty",
                                    "Seventy",
                                    "Eighty",
                                    "Ninety"};
  
  const char *ten_to_nineteen[] = {"Ten",
                                   "Eleven",
                                   "Twelve",
                                   "Thirteen",
                                   "Fourteen",
                                   "Fifteen",
                                   "Sixteen",
                                   "Seventeen",
                                   "Eighteen",
                                   "Nineteen"};
    
  const char *one_to_nine[] = {"One",
                               "Two",
                               "Three",
                               "Four",
                               "Five",
                               "Six",
                               "Seven",
                               "Eight",
                               "Nine"};

  printf("Enter a two-digit number: ");
  while (scanf("%2d", &num) != 1) {
    ;
  }

  printf("You entered the number ");
  
  int first_digit = num / 10;
  int second_digit = num % 10;

  if (first_digit == 0) {
    printf("%s\n", *(one_to_nine + second_digit - 1));
  } else if (first_digit != 1) {
    printf("%s", *(twenty_to_ninety + first_digit - 2));
    if (second_digit == 0) {
      return 0;
    } else {
      printf("-%s\n", *(one_to_nine + second_digit - 1));
    }
  } else {
    printf("%s\n", *(ten_to_nineteen + second_digit));
  }

  return 0;
}

