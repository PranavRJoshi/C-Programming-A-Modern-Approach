// Q. Suppose that f and p are declared as follows:
//    struct {
//      union {
//        char a, b;
//        int c;
//      } d;
//      int e[5];
//    } f, *p = &f;
// Which of the following statements are legal?
//    a. p->b = ' ';
//    b. p->e[3] = 10;
//    c. (*p).d.a = '*';
//    d. p->d->c = 20;

#include <stdio.h>

int main (void) {
  
  struct {
    union {
     char a, b;
     int c;
    } d;
    int e[5];
  } f, *p = &f;

  /* For a */
  // p->b = ' ';              /* Illegal Operation */
  p->d.b = ' ';               /* Legal Operation */
  printf("Member b of union d of structure pointer p is: %c\n", p->d.b);
  
  /* For b */
  p->e[3] = 10;               /* Legal Operation */
  // *((p->e) + 3) = 100;     /* Roguh equivalence */
  printf("Element 3 of member e of structure pointer p is: %d\n", p->e[3]);
  
  /* For c */
  (*p).d.a = '*';             /* Legal Operation */
  printf("Member a of union d of structure pointer p is: %c\n", (*p).d.a);

  /* For d */
  // p->d->c = 20;            /* Illegal Operation */
  p->d.c = 20;                /* Legal Operation */
  printf("Member c of union d of structure pointer p is: %d\n", p->d.c);

  return 0;
}

