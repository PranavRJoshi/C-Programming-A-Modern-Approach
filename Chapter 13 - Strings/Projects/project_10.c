// Q. Modify Programming Project 11 from Chapter 7 so that it includes the following function:
//    void reverse_name (char *name);
// The function expects name to point to a string containing a first name followed by a last name. It modifies the string so that the last name comes first, followed by a comma, a space, the first initial, and a period. The original string may contain extra spaces before the first name, between the first and last names, and after the last name.

#include <stdio.h>
#include <ctype.h>

#define NAME_LEN 100

void reverse_name (char *name);

int main (void) {

  char name[NAME_LEN + 1];
  char *name_ptr = name;

  printf("Enter a first and last name: ");
  
  while ((*name_ptr++ = getchar()) != '\n') {
    ;
  }

  *--name_ptr = '\0';
  
  // printf("[LOG] The string that is stored is: %s\n", name);

  reverse_name(name);

  printf("The reverse name is: %s\n", name);

  return 0;
}

void reverse_name (char *name) {
  char first_initial = *name;
  // char temp_arr[NAME_LEN];
  // char *temp = temp_arr;
  char *temp = name;
  int j = 0;

  // this hassle is done purely for the fact that we need to have only one parameter in the function and the funcion needs to change the aray that is sent as an argument.
  // This while loop will traverse throguh the array name, and copies the content to the temp_arr array while temp is a pointer that will be pointing to the null character before the loop terminates
  // while (1) {
  //   *temp = *(name + i);
  //   if ((*(name + i)) == '\0') {
  //     break;
  //   } 
  //   temp++;
  //   i++;
  // }
  
  // updated version
  while (*temp++) {
    ;
  }

  // makes it point to the null character at the end of the string.
  temp--;

  // this loop is used to check if there are any leading spaces before the first name
  for (j = 0; isspace(*(name + j)); j++) {
    ;
  }

  // j acts as an subscript which--when the upper for loop terminates--will be holding the index to the element which is a non-space characater.
  first_initial = *(name + j);

  // this is done as temp previously will be pointing to the null character in temp_arr array
  temp--;

  // this loop ensures that if there exists any white-space character after the last name, then the pointer will decrement until it finds a non-white-space character
  while (isspace(*temp)) {
    temp--;
  }

  // this loop ensures that after we have reached the last letter of the last name, then we must go back again and start to search for the earliest space-character symbol, as it ensures that the character right next to it will be the first letter of the last name.
  while (!isspace(*temp--)) {
    ;
  }

  // this is done as the upper while loop has the postfix operator used to decrement the address. When temp is a space, temp-- would make it point to the character to the left of the space-character. So we need to re-adjust the pointer. (which makes it point to the white-space character)
  temp++;
  
  // this loop ensures that until we find a white-space character, it will keep on incrementing the address. Like stated above, as temp will be pointing to a white-space character, we need to first increment the address to make it point to the non-white-space character next to it, hence the use of pre-increment operator. Also, since we need to modify the argument by changing it into: `<last name>, <first initial>.`, we start adding the letters from the last name into the array name, and increment it.
  while (!isspace(*++temp)) {
    if (*temp == '\0') {
      break;
    }
    *name = *temp;
    name++;
  }

  *name++ = ',';
  *name++ = ' ';
  *name++ = first_initial;
  *name++ = '.';
  *name = '\0';
}

