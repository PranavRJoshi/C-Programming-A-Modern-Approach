// Q. Modify Programming Project 1 from Chapter 10 so that it uses the stack ADT described in Section 19.4. You may use any of the implementations of the ADT described in that section.

#include <stdio.h>
#include <stdbool.h>
#include "stackADT.h"

bool is_nested_properly;

int main (void) {

  Stack s;

  s = create();
  
  char ch;
  char popped_item;
  is_nested_properly = true;

  printf("Enter parantheses and/or braces: ");

  ch = getchar();

  while (ch != '\n') {
    if (!is_nested_properly) {
      break;
    }
    switch (ch) {
      case '(': case '{':
        push(s, ch);
        break;
      case ')': case '}':
        popped_item = pop(s);
        if (popped_item != '(' && popped_item != '{') {
          break;
        }
        if ((popped_item == '(' && ch != ')') || (popped_item == '{' && ch != '}')) {
          is_nested_properly = false;
        }
        break;
    }
    ch = getchar();
  }

  if (is_empty(s)) {
    if (is_nested_properly) {
      printf("Parantheses/braces are nested properly\n");
    } else {
      printf("Parantheses/braces are not nested properly\n");
    }
  } else {
    printf("Parantheses/braces are not nested properly\n");
  }

  destroy(s);

  return 0;
}

