// Q. Declare a structure with the following members whose tag is pinball_machine:
//      name    - a string of up to 40 characters
//      year    - an integer (representing the year of the manufacture)
//      type    - an enumeration with the values EM (electromechanical) and SS (solid state)
//      players - an integer (representing the maximum number of players)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// #include <string.h>

#define PM_NAME_LEN 40
#define MAX_PM_SPEC 100

/*
 * pinball_machine: A structure having members name (char []), 
 *                  year (int), type (enum pm_type), and players (int).
*/
struct pinball_machine {
  char name[PM_NAME_LEN + 1];
  int year;
  enum pm_type { EM, SS } type;
  int players;
};

// /*
//  * pm_constructor:  A function which initializes a structure of tag pinball_machine
//  *                  with the given parameters.
// */
// struct pinball_machine pm_constructor (const char *pm_name, int pm_year, enum pm_type pm_t, int pm_players);

/*
 * read_line: Reads a line from the input with max length of len.
 *            If the input stream contains characters more than len,
 *            then remaining characters are ignored.
*/
int read_line (char *src, int len);

/*
 * clear_input_stream:  Clears the input stream and terminates 
 *                      when it encounters the new-line character.
*/
void clear_input_stream (void);

int main (void) {

  struct pinball_machine pm_arr[MAX_PM_SPEC];
  int i = 0;

  int command;

  int scanf_return_count = 0;

  for (;;) {
    printf("A program that keeps track of the pinball machine specification\n"            \
           "Enter one of the command listed below:\n"                                     \
           "      Usage                   Command\n"                                      \
           "1. Add a specification          (a)\n"                                        \
           "2. View the specification       (v)\n"                                        \
           "3. Quit the program             (q)\n"                                        \
           "Enter the command: ");

    while (isspace(command = getchar())) {
      ;
    }

    clear_input_stream();

    switch (command) {
      case 'a':
        if (i >= MAX_PM_SPEC) {
          fprintf(stderr, "[ERROR] Maximum Number of Specification Added.\n");
        } else {
          printf("Enter the name: ");
          read_line(&pm_arr[i].name[0], PM_NAME_LEN);
          for (;;) {
            printf("Enter the year: ");
            if ((scanf_return_count = scanf("%4d", &pm_arr[i].year)) != 1) {
              fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
              clear_input_stream();
              continue;
            }
            scanf_return_count = 0;
            clear_input_stream();
            break;
          }
          for (;;) {
            printf("Enter the number of players: ");
            if ((scanf_return_count = scanf("%d", &pm_arr[i].players)) != 1) {
              fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
              clear_input_stream();
              continue;
            }
            if (pm_arr[i].players < 0) {
              fprintf(stderr, "[ERROR] Players Cannot be in Negative.\n");
              continue;
            }
            scanf_return_count = 0;
            clear_input_stream();
            break;
          }
          for (;;) {
            printf("Enter the type (Electromechanical - 0, Solid State - 1): ");
            if ((scanf_return_count = scanf("%d", &pm_arr[i].type)) != 1) {
              fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
              clear_input_stream();
              continue;
            }
            if (pm_arr[i].type != 0 && pm_arr[i].type != 1) {
              fprintf(stderr, "[ERROR] Type Must be Either 0 or 1.\n");
              continue;
            }
            scanf_return_count = 0;
            clear_input_stream();
            break;
          }
          printf("[SUCCESS] The Specification Added To The Array.\n\n\n");
          i++;
        }
        break;
      case 'v':
        printf("There are %d specifications currently\n", i);
        if (i < 1) {
          fprintf(stderr, "[WARN] No Specifications Added till Now.\n\n\n");
          break;
        }
        printf("-------------------------------------------------------------------------------------\n");
        printf("\tName\t\t\t\t   Year\t\tType\t\tPlayers\n");
        for (int j = 0; j < i; j++) {
          printf("%-40s   %4d\t\t", pm_arr[j].name, pm_arr[j].year);
          if (pm_arr[j].type == EM) {
            printf("%2s\t\t%d\t\n", "EM", pm_arr[j].players);
          }
          if (pm_arr[j].type == SS) {
            printf("%2s\t\t%d\n", "SS", pm_arr[j].players);
          }
        }
        printf("-------------------------------------------------------------------------------------\n");
        break;
      case 'q':
        exit(EXIT_SUCCESS);
      default:
        fprintf(stderr, "[ERROR] Invalid Command Entered.\n");
    }
  }

  return 0;
}

// struct pinball_machine pm_constructor (const char *name, int year, enum pm_type t, int players) {
//   struct pinball_machine pm_new;
//
//   strlcpy(pm_new.name, name, PM_NAME_LEN);
//   pm_new.year = year;
//   pm_new.type = t;
//   pm_new.players = players;
//
//   return pm_new;
// }

int read_line (char *src, int len) {
  int ch;
  int index = 0;

  while (isspace(ch = getchar())) {
    ;
  }
  
  while (ch != '\n' && ch != EOF) {
    if (index < len) {
      *(src + index++) = ch;
    }
    ch = getchar();
  }
  *(src + index) = '\0';
  return index;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}
