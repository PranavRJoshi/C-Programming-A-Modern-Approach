// Q. (a) Declare a tag for an enumeration whose values represent the seven days of the week.
//    (b) Use typedef to define a name for the enumeration of part (a).

#include <stdio.h>

int main (void) {

  enum days { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

  {
    typedef enum { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY } days_t;
    printf("Inside the block where a type definition of enumerator is declared as:\n"           \
           "Monday: %d\n"                                                                       \
           "Tuesday: %d\n"                                                                      \
           "Wednesday: %d\n"                                                                    \
           "Thursday: %d\n"                                                                     \
           "Friday: %d\n"                                                                       \
           "Saturday: %d\n"                                                                     \
           "Sunday: %d\n\n\n", MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY);
  }

  printf("Inside the main function where a enum of tag days is declared as:\n"                 \
         "Monday: %d\n"                                                                       \
         "Tuesday: %d\n"                                                                      \
         "Wednesday: %d\n"                                                                    \
         "Thursday: %d\n"                                                                     \
         "Friday: %d\n"                                                                       \
         "Saturday: %d\n"                                                                     \
         "Sunday: %d\n\n\n", MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY);

  return 0;
}
