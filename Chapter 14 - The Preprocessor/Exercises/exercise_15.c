// Q. Suppose that a program needs to display messages in either English. French, or Spansih. Using conditional compilation, write a program fragment that displays one of the following three messages, depending on whether or not the specified macro is defined:
//      Insert Disk 1       (if ENGLISH is defined)
//      Inserez Le Disque 1 (if FRENCH is defined)
//      Inserte El Disco 1  (if SPANISH is defined)
// 

#include <stdio.h>

// #define ENGLISH 
#define FRENCH 
#define SPANISH

#define ERR_MSG(msg)              \
fprintf(stderr, "ERROR: " #msg " not defined\n")

int main (void) {

  int option;

  printf("Select Language (displays all by default):\n1. English\n2. French\n3. Spanish\nChoose your option: ");
  while (scanf("%d", &option) != 1) {
    ;
  }
  
  switch(option) {
    case 1:
      #ifdef ENGLISH 
        printf("Insert Disk 1\n");
      #else 
        ERR_MSG(English);
      #endif  /* ENGLISH */
      break; 
    case 2:
      #ifdef FRENCH 
        printf("Inserez Le Disque 1\n");
      #else 
        ERR_MSG(French);
      #endif  /* FRENCH */
      break; 
    case 3:
      #ifdef SPANISH 
        printf("Inserte El Disco 1\n");
      #else 
        ERR_MSG(Spanish);
      #endif  /* SPANISH */
      break; 
    default:
      #if defined(ENGLISH) && defined(FRENCH) && defined(SPANISH) 
        printf("Insert Disk 1\nInserez Le Disque 1\nInserte El Disco 1\n");
      #else 
        #ifndef ENGLISH 
          ERR_MSG(English);
        #endif  /* !ENGLISH */
        #ifndef FRENCH 
          ERR_MSG(French);
        #endif  /* !FRENCH */
        #ifndef SPANISH
          ERR_MSH(Spanish);
        #endif  /* !SPANISH */
      #endif  /* ENGLISH && FRENCH && SPANISH */
      break; 
  }

  return 0;
}
