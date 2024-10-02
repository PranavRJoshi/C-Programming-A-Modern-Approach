// Q. In Section 18.4, we saw that the following declarations are illegal:
//    int f(int)[];       /* functions can't return arrays */
//    int g(int)(int);    /* functions can't return functions */
//    int a[10](int);     /* array elements can't be functions */
// We can, however, achieve similar effects by using pointers: a function can return a pointer to the first element in an array, a function can return a pointer to a function, and the elements of an array can be pointers to functions. Revise each of these declarations accordingly.

#include <stdio.h>
#include <stdlib.h>

#define MALLOC_IS_NULL(addr)                                          \
if(!(addr)) {                                                         \
  fprintf(stderr, "[ERROR] Memory Allocation Failed. Exiting.\n");    \
  exit(EXIT_FAILURE);                                                 \
}

/* function which returns pointer to array of type int */
int (*fixed_size_array_ptr (int num))[10];
int (*unkonwn_size_array_ptr (int num))[];

/* function which returns pointer to function which takes in an arugment of type pointer to an integer, and returns void (nothing) */
static void set_secret_number (int *secret_number);
int ret_fcn_ptr (const char *fcn_caller, void (**ret_addr) (int *store_secret_number));
void (*ptr_to_fcn_ptr (const char *fcn_caller)) (int *store_secret_number);
static int print_number (int num);
int (*acc_to_question (int num_1)) (int num_2);

int main (void) {
  
  printf("\n***************************ARRAY***************************\n");
  /* First example */
  int (*fixed_size_ptr_to_arr)[10] = fixed_size_array_ptr(100);
  printf("[LOG] The address of the variable fixed_size_ptr_to_arr is: %p\n", (void *) fixed_size_ptr_to_arr);

  for (int i = 0; i < 10; i++) {
    printf("Element %d has the value: %d\n", i, (*fixed_size_ptr_to_arr)[i]);
  }
  free(fixed_size_ptr_to_arr);
  fixed_size_ptr_to_arr = NULL;
  /* Second example */
  int (*temp_unknown_array)[] = unkonwn_size_array_ptr(5);
  printf("[LOG] The address of the variable temp_unknown_array is: %p\n", (void *) temp_unknown_array);

  for (int i = 0; i < 5; i++) {
    printf("Element %d has the value: %d\n", i, (*temp_unknown_array)[i]);
  }

  free(temp_unknown_array);
  temp_unknown_array = NULL;
  printf("\n***************************ARRAY***************************\n");

  printf("\n*************************FUNCTION**************************\n");
  /* First example */
  int secret_number = 0;
  int fcn_addr_flag = -1;
  void (*get_fcn_addr) (int *);
  fcn_addr_flag = ret_fcn_ptr(__func__, &get_fcn_addr);
  if (!fcn_addr_flag) {
    printf("[LOG] The value stored in get_fcn_addr is: %p\n", (void *) get_fcn_addr);
    get_fcn_addr(&secret_number);
    printf("The secret number is: %d\n", secret_number);
  }
  /* Second example */
  void (*get_fcn_again) (int *);
  get_fcn_again = ptr_to_fcn_ptr(__func__);
  int another_secret_number;
  (*get_fcn_again)(&another_secret_number);
  printf("The secret number (again) is: %d\n", another_secret_number);
  /* Third example */
  int (*get_fcn) (int);
  get_fcn = acc_to_question(10);
  (*get_fcn)(100);
  printf("\n*************************FUNCTION**************************\n");

  printf("\n****************ARRAY OF FUNCTION POINTERS*****************\n");
  int (*arr_of_fcn_ptrs[2]) (int);
  arr_of_fcn_ptrs[0] = print_number;
  printf("The address stored in the first element is: %p\n", (void *) arr_of_fcn_ptrs[0]);
  
  printf("\n****************ARRAY OF FUNCTION POINTERS*****************\n");

  return 0;
}

int (*fixed_size_array_ptr (int num))[10] {
  int (*temp)[10] = malloc(sizeof(int) * (10));
  MALLOC_IS_NULL(temp);
  // printf("[LOG] The address of temp is: %p\n", (void *) temp);
  for (int i = 0; i < 10; i++) {
    (*temp)[i] = num;
  }

  return temp;
}

int (*unkonwn_size_array_ptr (int num))[] {
  int (*temp)[] = malloc(sizeof(int) * num);
  MALLOC_IS_NULL(temp);
  // printf("[LOG] The address of temp is: %p\n", (void *) temp);
  for (int i = 0; i < num; i++) {
    (*temp)[i] = i * i;
  }

  return temp;
}

static void set_secret_number (int *secret_number) {
  // printf("[LOG] The address of function %s is: %p\n", __func__, (void *) set_secret_number);
  *secret_number = 10;
}

int ret_fcn_ptr (const char *fcn_caller, void (**ret_addr) (int *store_secret_number)) {
  printf("[LOG] The function which called function %s is: %s\n", __func__, fcn_caller);

  *ret_addr = set_secret_number;
  if (*ret_addr == set_secret_number) {
    return 0;
  } else {
    return -1;
  }
  // printf("The returned address is: %p\n", (void *) *ret_addr);
}

void (*ptr_to_fcn_ptr (const char *fcn_caller)) (int *store_secret_number) {
  printf("[LOG] The function which called function %s is: %s\n", __func__, fcn_caller);

  return set_secret_number;
}

static int print_number (int num) {
  printf("[LOG] The function %s was provided argument: %d\n", __func__, num);
  return 0;
}

int (*acc_to_question (int num_1)) (int num_2) {
  printf("[LOG] The function %s was called with argument: %d\n", __func__, num_1);
  // printf("The address of print_number is: %p\n", (void *) print_number);
  return print_number;
}
