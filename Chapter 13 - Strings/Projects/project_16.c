// Q. Modify Programming Project 1 from Chapter 12 so that it includes the following function:
//    void reverse (char *messsage);
// The function reverses the string pointed to by message. Hint: Use two pointers, one initially pointing to the first character of the string and the other initially pointing to the last character. Have the function reverse these characters and then move the pointers toward each other, repeating the process until the pointers meet.

#include <stdio.h>

void reverse (char *message);

#define MSG_SIZE 50

int main (void) {

  char message[MSG_SIZE];
  char *msg_ptr = message;
  int message_count = 0;

  printf("Enter a message: ");

  while ((*(msg_ptr+message_count) = getchar()) != '\n' && message_count <= MSG_SIZE) {
    message_count++;
  }

  // doing this to remove the new-line character from the string and replacing it with a null character
  *(msg_ptr + message_count) = '\0';

  // printf("[LOG] The variable message holds: %s\n", message);

  reverse(message);

  printf("Reversal is: %s\n", message);

  return 0;
}

void reverse (char *m) {
  char *temp_ptr = m;
  char store_temp;

  // printf("[LOG] The variable temp_ptr points to the string: %s\n", temp_ptr);

  while (*temp_ptr++) {
    ;
  }

  temp_ptr--;

  // SO STUPID OF ME
  // DO NOT BOTHER READING THE TEXT BELOW IF YOU UNDERSTAND HOW INEQUALITY OPERATORS WORKS
  // SINCE APPARENTLY I DON'T KNOW HOW 
  // BOTTOM LINE: USE != ONLY IF YOU KNOW WHAT YOU'RE DOING

  // suprisingly, this lines of code will not work
  // to decrement the pointer such that temp_ptr will point to one character before the null character
  // temp_ptr--;
  //
  // while (m != temp_ptr) {
  //   store_temp = *m;
  //   *m = *temp_ptr;
  //   *temp_ptr = store_temp;
  //   m++;
  //   temp_ptr--;
  // }
  //
  // [NOTE] THIS IS FOR WHEN THE NUMBER OF CHARACTERS BEING ODD ONLY
  // okay, so after a bit of speculation, there is a reason why this would not work (when the message is 13 characters long--including the null character--and the pointer m points to the first character while temp_ptr points to the last character before the null character, the two pointers m and temp_ptr will not meet each other.
  //
  // consider an example, an input of "hello worlds", which is of 12 characters, 13 when we include the null character
  //
  // using the wrong process, the pointers will be as follows (swapped characters inside parantheses):
  // Iteration    m       temp_ptr            m (new)           temp (new)
  // 0            h         s(h)              e                   d
  // 1            e         d(e)              l                   l
  // 2            l         l(l)              l                   r
  // 3            l         r(l)              o                   o
  // 4            o         o(o)            <space>               w
  // 5          <space>     w(<space>)        w                   o
  //
  // as we can see, the pointers will not meet, so the loop will never stop, hence the seg fault.
  //
  // when we use the method below, the following things will happen:
  // Iteration    m       temp_ptr            m (new)           temp (new)
  // 0            h         s(h)              e                   s
  // 1            e         d(e)              l                   d
  // 2            l         l(l)              l                   l
  // 3            l         r(l)              o                   r
  // 4            o         o(o)            <space>               o
  // 5          <space>     w(<space>)        w                   w
  //
  // as we can see, the pointers will meet eventually, so the loop will terminate
  // one of the important thing i noticed is the use of pre-increment operator, which is useful in this context to make the two pointers meet eventually.
  // it wouldn't matter if we make the pointer temp_ptr point to the null character or the character before it. I have tried this, but this would not work either. Too lazy to verify it tho :) 
  // If you have read all of this, don't you feel stupid as well :)

  while (m <= temp_ptr) {
    // printf("[LOG] The character at m and temp_ptr are: %c and %c\n", *m, *temp_ptr);
    store_temp = *m;
    *m++ = *--temp_ptr;
    *temp_ptr = store_temp;
  }
}
