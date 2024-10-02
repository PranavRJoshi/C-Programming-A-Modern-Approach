// Q. Write the following function:
//    bool test_extension (const char *file_name, const char *extension);
// file_name points to a string containing a file name. The function should return true if the file's extension matches the string pointed to by extension, ignoring the case of letters. For example, the call test_extension("memo.txt", "TXT") would return true. Incorporate the "search for the end of the string" idiom into your function. Hint: Use the toupper function to convert characters to upper-case before comparing them.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define FILE_NAME_LENGTH 100

bool test_extension (const char *file_name, const char *extension);

int main (void) {

  char file_name[FILE_NAME_LENGTH + 1];
  char extension[FILE_NAME_LENGTH + 1 - 90];
  char *file_name_ptr = file_name;
  bool is_extension_valid = false;

  printf("Enter a file name: ");
  while((*file_name_ptr++ = getchar()) != '.') {
    ;
  }

  // handles the condition when the extension contains trailing spaces instead of new-line character.
  while(!isspace((*file_name_ptr++ = getchar()))) {
    ;
  }

  *--file_name_ptr = '\0';

  printf("Enter the extension: ");
  scanf("%s", extension);

  is_extension_valid = test_extension(file_name, extension);

  if (is_extension_valid) {
    printf("Extension matches the one that is provided in the file name.\n");
  } else {
    printf("Extension does not match the one that is provided in the file name.\n");
  }

  return 0;
}

bool test_extension (const char *fn, const char *e) {
  while (*fn++ != '.') {
    ;
  }

  while (*fn || *e) {
    if (toupper(*fn++) != toupper(*e++)) {
      return false;
    }
  }

  return true;
}
