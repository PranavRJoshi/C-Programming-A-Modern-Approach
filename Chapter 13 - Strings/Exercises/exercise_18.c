// Q. Write the following function:
//    void remove_filename (char *url);
// url points to a string containing a URL (Uniform Resource Locator) that ends a file name (such as "http://www.knking.com/index.html"). The function should modify the string by removing the file name and the preceding slash. (In this example, the result will be "http://www.knking.com".) Incorporate the "serach for the end of a string" idiom into your function. Hint: Have the function replace the last slash in the string by a null character.

#include <stdio.h>

#define URL_LEN 100

void remove_filename (char *url);

int main (void) {

  char url[URL_LEN + 1];

  printf("Enter an url: ");
  // scanf will return 1 when it successfully stores the input stream in the character array url
  // scanf will return i, where i indicates the successful amount of conversion specification that has been carried out from the format string. 
  while (scanf("%s", url) != 1);

  remove_filename(url);

  printf("After removing the file name: %s\n", url);

  return 0;
}

void remove_filename (char *url) {

  while (*url++) {
    ;
  }

  while (*--url != '/') {
    ;
  }
  
  *url = '\0';
}

