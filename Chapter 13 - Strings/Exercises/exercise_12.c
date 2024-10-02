// Q. Write the following function:
//    void get_extension (const char *file_name, char *extension);
// file_name points to a string containing a file name. The function should store the extenion of the file name in the string pointed to by extension. For example, if the file name is "memo.txt", the function will store "txt" in the string pointed to by extension. If the file name doesn't have an extension, the function should store an empty string (a single null character) in the string pointed to by extension. Keep the function as simple as possible by having it use the strlen and strcpy functions.

#include <stdio.h>
#include <string.h>

#define FILE_NAME_LEN 100
#define EXTENSION_LEN 5

void get_extension (const char *file_name, char *extension);

int main (void) {

  char file_name[FILE_NAME_LEN + 1];
  char file_extension[EXTENSION_LEN + 1];
  char *extension = file_extension;

  printf("Enter the file name (along with the extension): ");
  scanf("%s", file_name);

  get_extension(file_name, extension);

  if (*extension == '\0') {
    printf("WARN: The given file name does not have any extension.\n");
  } else {
    printf("The extension of the file is: %s\n", extension);
  }

  return 0;
}

void get_extension (const char *fn, char *e) {
  int i;

  strcpy(e, "");

  for (i = 0; i < (int) strlen(fn); i++) {
    if (*(fn + i) == '.') {
      strcpy(e, (fn + i + 1));
    }
  }
}
