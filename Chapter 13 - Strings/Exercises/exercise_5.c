// Q. a. Write a function named capitalize that capitalizes all letters in it's argument. The argument will be null-terminated string containing arbitrary characters, not just letters. Use array subscrpting to access the characters in the string. Hint: Use the toupper function to convert each character to upper-case.
//    b. Rewrite the capitalize function, this time using pointer arithmetic to access the characters in the string.

#include <stdio.h>
#include <ctype.h>

#define STR_LEN 100

char *capitalize (char *s); 

int main (void) {

  char c_arr[STR_LEN + 1];
  int count = 0, ch;

  printf("Enter a string: ");

  while ((ch = getchar()) != '\n' && count < STR_LEN) {
    c_arr[count] = ch;
    count++;
  }

  c_arr[count] = '\0';

  capitalize(c_arr);

  printf("The capitalized string is: %s\n", c_arr);

  return 0;
}

char *capitalize (char *s) {
  while (*s != '\0') {
    *s = toupper(*s);
    s++;
  }

  return s;
}
