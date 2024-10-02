// Q. The program is designed to check a series to see which ones are names of planet. When the program is run, the user will put the strings to be tested on the command line:
//    planet Jupiter venus Earth fred
// The program will indicate whether or not each string is a planet name; if it is, the program will also display the planet's numbers (with planet 1 being the one closest to the Sun:
//    Jupiter is planet 5
//    venus is not a planet
//    Earth is planet 3
//    fred is not a planet
// Notice that the program doesn't recognize a string as a planet name unless its first letter is upper-case and its remaining letters are lower-case.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main (int argc, char *argv[]) {

  char *planets[] = {"Mercury",
                     "Venus",
                     "Earth",
                     "Mars",
                     "Jupiter",
                     "Saturn",
                     "Uranus",
                     "Neptune"};

  char **p;
  bool is_planet = false;

  // printf("The total arguments is: %d\n", argc);

  // &argv[1] is a pointer that points to another pointer which points to character, so we need to declare a pointer variable that points to a pointer which points to a character
  // *p != NULL as argv[argc] will point to a NULL pointer
  // p++ is pointer arithmetic that appends p such that it points to another pointer that points to different characters of a different string
  for (p = &argv[1]; *p != NULL; p++) {
    is_planet = false;
    for (int i = 0; i < 8; i++) {
      // *p points to the string from the argv while *(planets + i) points to the pointer that is stored in the variable planets
      // (planets + 0) will point to the string "Mercury", and so on...
      // and *(planets + 0) is a char * variable which is, a string.
      if (strcmp(*p, *(planets + i)) == 0) {
        printf("%s is planet number %d.\n", *p, i + 1);
        is_planet = true;
        break;
      }
    }
    if (!is_planet) {
      printf("%s is not a planet.\n", *p);
    }
  }

  return 0;
}

