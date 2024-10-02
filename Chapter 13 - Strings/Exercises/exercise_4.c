// Q. Modify the read_line function in each of the following ways:
//    a. Have it skip white space before beginning to store input characters.
//    b. Have it stop reading at the first white-space character. Hint: To determine whether or not a character is white-space, call the isspace function.
//    c. Have it stop reading at the first new-line character, then store the new-line character in the string.
//    d. Have it leave behind characters that it doens't have room to store.

#include <stdio.h>
#include <ctype.h>

#define STR_LEN 100

int read_line_1 (char *char_arr);
int read_line_2 (char *char_arr);
int read_line_3 (char *char_arr);
int read_line_4 (char *char_arr, int arr_size);

int main (void) {

  char s_arr[STR_LEN+1];
  int command;

  printf("Enter any choice (1-4): ");
  scanf("%d", &command);

  // this getchar is used to take the unwanted new-line character after the user enters their option.
  getchar();

  switch (command) {
    case 1:
      read_line_1(s_arr);
      printf("The input read is: %s", s_arr);
      break;
    case 2:
      read_line_2(s_arr);
      printf("The input read is: %s", s_arr);
      break;
    case 3:
      read_line_3(s_arr);
      printf("The input read is: %s", s_arr);
      break;
    case 4:
      read_line_4(s_arr, STR_LEN);
      printf("The input read is: %s", s_arr);
      break;
    default:
      printf("ERROR: Invalid command entered.\n");
      break;
  }

  return 0;
}

int read_line_1 (char *s) {
  int count = 0;
  int ch;

  while ((ch = getchar()) == ' ') {
    ;
  }

  // when ch encounter a non-space character, it will break out of the loop, so we take that character and store it first before going into next loop.
  *s++ = ch;
  count++;

  // reads characterm and stores it in s until a new-line character is encountered.
  while ((ch = getchar()) != '\n') {
    *s++ = ch;
    count++;
  }

  // adds the null character at the end.
  // we do no need to increment s as when ch is a character before the new-line character, s is post-incremented.
  *s = '\0';

  return count;
}

int read_line_2 (char *s) {
  int count = 0;
  int ch;

  // considering the possibility of having leading space in the input stream:
  while ((ch = getchar()) == ' ') {
    ;
  }
  
  *s++ = ch;
  count++;

  // isspace will return true (non-zero) if it encounter characters like ' ', '\n', '\t', '\v', '\f', and '\r'.
  // if it encounters any other characters, then it returns 0
  while (!isspace((ch = getchar()))) {
    *s++ = ch;
    count++;
  }

  *s = '\0';

  return count;
}

int read_line_3 (char *s) {
  int count = 0;
  int ch;

  // considering the possibility of having leading space in the input stream:
  while ((ch = getchar()) == ' ') {
    ;
  }
  
  *s++ = ch;
  count++;

  while ((ch = getchar()) != '\n') {
    *s++ = ch;
    count++;
  }

  *s++ = '\n';
  *s = '\0';

  return count;
}

int read_line_4 (char *s, int l) {
  int count = 0;
  int ch;

  // considering the possibility of having leading space in the input stream:
  while ((ch = getchar()) == ' ') {
    ;
  }
  
  *s++ = ch;
  count++;

  for (; count < l; count++) {
    ch = getchar();
    if (ch == '\n') {
      break;
    }
    *s++ = ch;
  }

  *s = '\0';

  return count;
}

