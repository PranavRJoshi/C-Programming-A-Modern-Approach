// Q. Functions can often--but not always--be written as parameterized macros. Discuss what characteristics of a function would make it unsuitable as a macro.
//
// Definition of a function that is defined as a macro has some limitations. Like we discussed in the Chapter, one of the reason is:
//    1. A function that is defined through a macro cannot have a parameter that is of type pointer to the respective data type.
// Some other limitations that i can think of is:
//    2. A function can return not only basic types, but also of return type that is a pointer to the respective data type. Say, a function prototype is of the form:
//        char *strcat (char *dst, const char *src);
//      This function expects two parameters, dst--a pointer to character variable, and src--a pointer to const character variable. When the function reaches the end of it's function block, the return type is a pointer to character. 
//      Making a function like this using parameterized macros is not suitable as we cannot return a pointer when defining a function.
//    3. A function that returns one type while having side effect on another variable--pointer to variables that are passed as an argument--is not possible to define using macros.
//    4. A function that deals with modifying a string is not suitable to be defined using a macro, as string, in it's purest form is an array of characters that has a null character as it's terminating character.
//    5. In short, any function that involves the side effect on its argument, provided that the argument is a pointer to a certain data type, is not feasible to be defined using a macro.

// #include <stdio.h>

// this macro is used to increment all elements in an array
// obviously this will not work, as the indirection operation is not fully utilized when creating a macro
// the error that is generated when invoking the macro is shown below when the macro is invoked.
//
// #define GENERIC_INC_ARR_ELEMENTS(type)        \
// type *type##_inc_arr (type *a) {              \
//   int size = sizeof(*a) / sizeof(*(a + 0));   \
//   int index = 0;                              \
//   for (;index < size; index++) {              \
//     a[index]++;                               \
//   }                                           \
//   return a;                                   \
// }

// suspicious use of sizeof pointer 'sizeof(T*) / sizeof(T)'
// GENERIC_INC_ARR_ELEMENTS(int)

int main (void) {

  return 0;
}

