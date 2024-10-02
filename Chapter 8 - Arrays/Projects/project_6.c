// Q. The prototypical Internet newbie is a fellow named B1FF, who has a unique way of writing messages. Here's a typical B1FF communiqué:
//    H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
// Write a "B1FF filter" that reads a message entered by the user and translates it into B1FF-speak:
//    Enter message: Hey dude, C is rilly cool
//    In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
// Your program should convert the message to upper-case letters, substitute digits for certain letters (A->4, B->8, E->3, I->1, O->0, S->5), and then append 10 or so exclamation marks. Hint: Store the original message in an array of characters, then go back through the array, translating and printing characters one-by-one.

#include <stdio.h>
#include <ctype.h>

#define MSG_LENGTH 100

int main (void) {

  int i = 0, j = 0;
  char ch;
  char message[MSG_LENGTH];

  printf("Enter a message: ");

  // fetches the character that are entered by the user and i keeps track of the count of characters that has been entered
  // consider an input of aey, ch first stores a, it is not new-line character, so it goes inside the loop body
  // when the loop body is executed, i is incremented to 1 and ch gets the next character, i.e. e
  // it also goes inside the loop body, and once it's over, i is incremented to 2, and ch gets the next character
  // when it fetches y, it also goes inside the loop body and once that is over, i is incremented to 3, and ch gets the next character
  // since the final character is '\n', it does not go inside the loop body, by the value of i is 3. 
  // this is useful for the next loop that adds exclamation marks
  for (i = 0, ch = getchar(); ch != '\n'; i++, ch = getchar()) {
    message[i] = ch;
    // first convert the character to uppercase, if it's not a alaphabet, toupper does nothing
    // change the message to B1FF speak accordingly
    switch (toupper(message[i])) {
      case 'A':
        message[i] = '4';
        break;
      case 'B':
        message[i] = '8';
        break;
      case 'E':
        message[i] = '3';
        break;
      case 'I':
        message[i] = '1';
        break;
      case 'O':
        message[i] = '0';
        break;
      case 'S':
        message[i] = '5';
        break;
      default:
        message[i] = toupper(message[i]);
        break;
    }
  }

  // add the extra exclamation marks, can be adjusted as needed
  for (j = i; j < i + 10; j++) {
    message[j] = '!';
  }

  // adds a NULL character at the end of the character array
  message[j] = '\0';

  // display the modified characters
  printf("In B1FF-speak:   ");
  for (int i = 0; i < j; i++) {
    printf("%c", message[i]);
  }
  
  printf("\n");
 
  return 0;
}

