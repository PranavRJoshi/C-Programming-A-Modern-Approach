// Q. Write declarations for the following variables and functions:
//    a. p is a pointer to a function with a character pointer argument that returns a character pointer.
//    b. f is a function with two arguments: p, a pointer to a structure with tag t, and n, a long integer. f returns a pointer to a function that has no arguments and returns nothing.
//    c. a is an array of four pointers to functions that have no arguments and returns nothing. The elements of a initially point to functions named insert, search, update, and print.
//    d. b is an array of 10 pointers to functions with two int arguments that return structures with tag t.

#include <stdio.h>
#include <stdlib.h>

/* Question 10(a) */
char *print_and_return_string(char *str);

/* Question 10(b) */
struct t {
  int n;
};

void do_nothing(void);

void (*f(struct t *p, long n))(void);

/* Question 10(c) */
void insert (void);
void search (void);
void update (void);
void print (void);

/* Question 10(d) */
struct t return_struct (int num_1, int num_2);

int main (void) {

  /* Question 10(a) */
  char *return_ptr;
  char *(*p)(char *);
  p = print_and_return_string;
  return_ptr = (*p)("Hello, World!");
  printf("The returned string is: %s\n", return_ptr);

  /* Question 10(b) */
  // void (*f(struct t *p, long n))(void);
  struct t *main_temp = NULL;
  main_temp = malloc(sizeof(struct t));
  if (!main_temp) {
    fprintf(stderr, "[ERROR] Memory Allocation Failed.\n");
    exit(EXIT_FAILURE);
  }
  main_temp->n = 10;
  void (*do_nothing_ptr)(void) = f(main_temp, 100);
  do_nothing();
  (*do_nothing_ptr)();
  free(main_temp);
  main_temp = NULL;

  /* Question 10(c) */
  void (*a[4])(void) = { insert, search, update, print };
  a[0]();
  a[1]();
  a[2]();
  a[3]();

  /* Question 10(d) */
  struct t (*b[10])(int, int);
  b[0] = return_struct;
  b[0](1, 10);

  return 0;
}

char *print_and_return_string (char *str) {
  printf("The string passed to %s function is: %s\n", __func__, str);

  return str;
}

void do_nothing (void) {
  printf("The function %s has the address: %p\n", __func__, (void *) do_nothing);
}

void (*f(struct t *p, long n))(void) {
  printf("The number stored inside the structure of tag t is: %d\n", p->n);
  printf("The value of the long variable is: %ld\n", n);

  return do_nothing;
}

void insert (void) {
  printf("Called the %s function.\n", __func__);
}

void search (void) {
  printf("Called the %s function.\n", __func__);
}

void update (void) {
  printf("Called the %s function.\n", __func__);
}

void print (void) {
  printf("Called the %s function.\n", __func__);
}

struct t return_struct (int num_1, int num_2) {
  struct t temp = {num_1};

  printf("Added the %d to the structure. Ignored %d\n", num_1, num_2);

  return temp;
}
