// Q. Improve the planet.c program of Section 13.7 by having it ignore case when comparing command-line arguments with strings in the planets array.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void make_title_case (char *char_arr);

int main (int argc, char **argv) {

  const char *planets[] = {"Mercury",
                           "Venus",
                           "Earth",
                           "Mars",
                           "Jupiter",
                           "Saturn",
                           "Uranus",
                           "Neptune"};

  char **p;
  bool is_planet = false;

  for (int i = 1; i < argc; i++) {
    p = (argv + i);
    is_planet = false;
    make_title_case(*p);
    for (int i = 0; i < 8; i++) {
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

void make_title_case (char *c) {
  *c = toupper(*c);
  c++;

  while (*c != '\0') {
    *c = tolower(*c);
    c++;
  }
}
