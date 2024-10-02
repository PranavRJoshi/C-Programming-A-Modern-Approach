// Q. This program does the following:
//    Enter a message: don't get mad, get even.
//    Reversal is: even. get mad, get don't

#include <stdio.h>

#define MSG_COUNT 10
#define MSG_SIZE 50

int main (void) {

  char message[MSG_COUNT][MSG_SIZE];
  // declaring a character pointer that points to an array of character
  char (*msg_ptr)[MSG_SIZE] = message;
  // keep track of the words that appear in the message and the characters per word
  int word_count = 0;
  int message_count = 0;
  char ch;

  printf("Enter a message: ");
  ch = getchar();

  // loop will run until we find the new line character or if word_count == MSG_COUNT
  while (ch != '\n' && word_count < MSG_COUNT) {
    // loop until we find a space, or if we encounter the last word (which has new line character after the last word)
    while ((ch != ' ' && ch != '\n') && message_count < MSG_SIZE) {
      // store the characters in the array
      // (*(msg_ptr + word_count))[message_count++] points to the word_count row and the message_count index of the msg_ptr pointer (which is the same as message[word_count][message_count++]). message_count is incremented after the sequence point. 
      (*(msg_ptr + word_count))[message_count++] = ch;
      ch = getchar();
    }
    // if we encounter the last word and the next character is '\n', we add the NULL character ('\0') to the message_count index (notice that message_count is incremented before breaking out of the top while loop, so message_count is still at an index where no character is stored. We increment word_count as well, since we use the pre-decrement operator in the upcoming for loop
    if (ch == '\n') {
      (*(msg_ptr + word_count))[message_count] = '\0';
      word_count++;
      break;
    } else {
      // if we encounter only a space, then we add the NULL character in the message_count index of (*(msg_ptr + word_count)) row. we get the next character after the space, and reset the message_count while incrementing the word_count. 
      (*(msg_ptr + word_count))[message_count] = '\0';
      ch = getchar();
      message_count = 0;
      word_count++;
    }
  }

  printf("Reversal is: ");

  // since word_count is pointing to the row which doesn't have any characters stored, we need to decrement it before accessing the row. 
  // we also need to check if the msg_ptr is used till we encounter the 0th row of the two-dimensional array
  // msg_ptr-- decrements the current address stored in msg_ptr by (sizeof(*msg_ptr))
  // sizeof(*msg_ptr) gives the 1 byte * MSG_SIZE (1 byte since char takes up one byte), and msg_ptr holds the array of characters.
  for (msg_ptr = &message[--word_count]; msg_ptr >= &message[0]; msg_ptr--) {
    int i = 0;
    // *(msg_ptr)[i] gives the i'th column of the row pointed to by msg_ptr
    while ((*msg_ptr)[i] != '\0') {
      putchar((*msg_ptr)[i++]);
    }
    printf(" ");
  }

  printf("\n");

  return 0;
}

