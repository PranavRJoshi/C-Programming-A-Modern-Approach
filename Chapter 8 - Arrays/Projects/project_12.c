// Q. Modify Programming Project 5 from Chapter 7 so that the SCRABBLE values of the letters are stored in an array. The array will have 26 elements, corresponding to the 26 letters of the alphabet. For example, element 0 of the array will store 1 (because the SCRABBLE value of the letter A is 1), element 1 of the array will store 3 (because the SCRABBLE value of the letter B is 3), and so forth. As each character of the input word is read, the program will use the array to determine the SCRABBLE value of that character. Use an array initializer to set up the array.
// (Here are the face values: 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ.)

#include <stdio.h>
#include <ctype.h>

int main (void) {

  // store the scrabble value of each alphabet
  int scrabble_value[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  char ch;
  int scrabble_total = 0;
  
  printf("Enter a word: ");

  while ((ch = getchar()) != '\n') {
    // only consider the characters that are alphabet
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      // see #29 in this chapter's note. it illustrates how we can use characters as a subscript for an array
      scrabble_total += scrabble_value[toupper(ch) - 'A'];
    }
  }

  printf("Scrabble value: %d\n", scrabble_total);

  return 0;
}

