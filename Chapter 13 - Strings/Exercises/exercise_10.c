#include <stdio.h>
#include <string.h>

char *duplicate (const char *p);

int main (void) {
  
  char p[100] = "Erroneous Code!";

  char *q = duplicate(p);

  printf("The value stored in q is: %s", q);

  return 0;
}

char *duplicate (const char *p) {
  char *q;

  strcpy(q, p);
  return q;
}

