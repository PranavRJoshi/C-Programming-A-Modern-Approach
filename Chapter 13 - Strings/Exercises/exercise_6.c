// Q. Write a function named censor that modifies a string by replacing every occurance of foo by xxx. For example, the string "food fool" would become "xxxd xxxl". Make the function as short as possible without sacrificing claruity.

#include <stdio.h>

#define STR_LEN 100

void censor (char *char_array);

int main (void) {

  char c_arr[STR_LEN + 1];
  int ch, count = 0;

  printf("Enter a string: ");

  while ((ch = getchar()) != '\n' && count < STR_LEN) {
    c_arr[count++] = ch;
  }

  c_arr[count] = '\0';

  censor(c_arr);

  printf("The censored string is: %s\n", c_arr);

  return 0;
}

void censor (char *s) {
  while (*s != '\0') {
    // The short circuit evaluation done inside the if statement prevents the testing when *s reaches a null character.
    if (*s == 'f' && *(s + 1) == 'o' && *(s + 2) == 'o') {
      *s = *(s+1) = *(s+2) = 'x';
    }
    s++;
  }
}
