// Q. Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-xxxx and then displays the number in the form xxx.xxx.xxxx:
// Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
// You entered 404.817.6900

#include <stdio.h>

int main (void) {
    int code, first_place, second_place;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &code, &first_place, &second_place);

    printf("You entered %d.%d.%d", code, first_place, second_place);

    return 0;
}
