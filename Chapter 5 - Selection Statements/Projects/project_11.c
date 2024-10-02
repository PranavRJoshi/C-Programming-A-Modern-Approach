// Q. Write a program that asks the user for a two-digit number, then prints the English word for the number:
//  Enter a two-digit number: 45
//  You entered the number forty-five.
// Hint: Break the number into two digits. Use one switch statement to print the word for the first digit ("twenty", "thrity", and so forth). Use a second switch statement to print the word for the second digit. Don't forget that the numbers between 11 and 19 require special treatment.

#include <stdio.h>

int main (void) {

    int num;

    printf("Enter a two-digit number: ");
    scanf("%2d", &num);

    printf("You entered the number ");

    switch (num / 10) {
        case 9:
            printf("ninety");
            break;
        case 8:
            printf("eighty");
            break;
        case 7:
            printf("seventy");
            break;
        case 6:
            printf("sixty");
            break;
        case 5:
            printf("fifty");
            break;
        case 4:
            printf("forty");
            break;
        case 3:
            printf("thirty");
            break;
        case 2:
            printf("twenty");
            break;
        // special case for when number from 10 to 19
        case 1:
            switch (num % 10) {
                case 0:
                    printf("Ten");
                    return 0;
                case 1:
                    printf("Eleven");
                    return 0;
                case 2:
                    printf("Twelve");
                    return 0;
                case 3:
                    printf("Thirteen");
                    return 0;
                case 4:
                    printf("Fourteen");
                    return 0;
                case 5:
                    printf("Fifteen");
                    return 0;
                case 6:
                    printf("Sixteen");
                    return 0;
                case 7:
                    printf("Seventeen");
                    return 0;
                case 8:
                    printf("Eighteen");
                    return 0;
                case 9:
                    printf("Nineteen");
                    return 0;
            }
    }

    // check if the number is two digits and ends with 0
    if ((num / 10 != 0) && (num % 10 == 0)) {
        return 0;
    } else {
        printf("-");
    }

    switch (num % 10) {
        case 9:
            printf("nine");
            break;
        case 8:
            printf("eight");
            break;
        case 7:
            printf("seven");
            break;
        case 6:
            printf("six");
            break;
        case 5:
            printf("five");
            break;
        case 4:
            printf("four");
            break;
        case 3:
            printf("three");
            break;
        case 2:
            printf("two");
            break;
        case 1:
            printf("one");
            break;
        case 0:
            printf("zero");
            break; 
    }

    return 0;
}
