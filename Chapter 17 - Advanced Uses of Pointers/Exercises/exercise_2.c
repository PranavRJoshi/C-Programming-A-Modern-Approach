// Q. Write a function named duplicate that uses dynamic storage allocation to create a copy of a string. For example, the call 
//    p = duplicate(str);
// would allocate space for a string of the same length as str, copy the content of str into the new string, and return a pointer to it. Have duplocate return a null pointer if memory allocation fails.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_SIZE 100

/*
 * duplicate: Returns a memory address that allocates the number of bytes 
 *            equivalent to the one in str_s and copies the content of sts_s
 *            to the memory address.
*/
char *duplicate (const char *str_s);

/*
 * read_line: Reads an input line from the input string, and stores n characters 
 *            and stores it in the string str. If the input buffer exceeds n character
 *            limit, the remaining characters are read but not stored until new-line 
 *            character or EOF is encountered.
*/
int read_line(char *str, int n);

int main (void) {
  
  char original_str[STR_SIZE + 1];
  char *duplicate_str;

  printf("Enter a sentence to be duplicated: ");
  read_line(original_str, STR_SIZE);

  duplicate_str = duplicate(original_str);

  printf("The duplicated string/sentence is:\n%s\n", duplicate_str);
  
  return 0;
}

char *duplicate (const char *str) {
  char *temp_str;
  size_t str_size = strlen(str) + 1;    /* one more to account for the null character */

  printf("[LOG] The size of the string is: %zu\n", str_size);

  temp_str = malloc(str_size);
  if (temp_str == NULL) {
    fprintf(stderr, "[ERROR] Memory allocation failed when calling function %s\n", __func__);
    exit(EXIT_FAILURE);
  }
  // function prototype: size_t strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
  // strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.
  strlcpy(temp_str, str, str_size);

  return temp_str;
}

int read_line (char str[], int len) {
  int ch, i = 0;

  while (isspace(ch = getchar())) {
    ;
  }

  while (ch != '\n' && ch != EOF) {
    if (i < len) {
      str[i++] = ch;
    }
    ch = getchar();
  }
  str[i] = '\0';
  return i;
}

