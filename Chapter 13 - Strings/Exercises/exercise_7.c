#include <stdio.h>
#include <string.h>

int main (void) {

  char str[10] = "To C";
  
  // *str = 0;          /* true */
  // str[0] = '\0';     /* true */
  // strcpy(str, "");   /* true */
  strcat(str, "");      /* false */

  if (str[0] == '\0') {
    printf("The first character is a null character.\n");
  } else {
    printf("The first character is not a null character.\n");
  }

  
  return 0;
}
