// Q. The Q&A section at the end of this chapter shows how the strcmp function might be written using array subscripting. Modify the function to use pointer arithmetic instead.

#include <stdio.h>

#define STR_LEN 100

int my_strcmp (char *first_string, char *second_string);

int main (void) {

  char str_1[STR_LEN + 1];
  char str_2[STR_LEN + 1];

  int check;

  printf("Enter two words separated by a space: ");
  // it does not matter if we write the format specifier inside scanf as: scanf("%s %s", str_1, str_2);
  // having a space in the format specifier specifies that there can be one or more space between the words
  // but even if there is no space, scanf will ignore all the leading spaces that it will encounter before reading the second word.
  scanf("%s%s", str_1, str_2);

  check = my_strcmp(str_1, str_2);

  if (check == 0) {
    printf("The two words are same.\n");
  } else if (check > 0) {
    printf("The first mismatched character in the first word is greater.\n");
  } else {
    printf("The first mismatched character in the second word is greater.\n");
  }

  return 0;
}

int my_strcmp (char *s, char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

