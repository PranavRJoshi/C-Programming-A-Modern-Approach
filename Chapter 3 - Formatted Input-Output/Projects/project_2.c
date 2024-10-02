// Q. Write a program that formats product information entered by the user. A session with the program should look like this:
// Enter item number: 583
// Enter unit price: 13.5
// Enter purchase date (mm/dd/yyyy): 10/24/2010

//  Item        Unit            Purchase
//              Price           Date
//  583         $   13.50       10/24/2010
// The item number and date should be left justified; the unit price should be right justified. Allow dollar amounts up to $9999.99. Hint: Use tabs to line up columns.

#include <stdio.h>

int main (void) {
    int item_number, date, month, year;
    float unit_price;

    printf("Enter item number: ");
    scanf("%d", &item_number);
    printf("Enter unit price: ");
    scanf("%f", &unit_price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &date, &year);

    printf("Item\tUnit Price\tPurchase Date\n");
    printf("%-d\t$%7.2f\t%-2.2d/%-2.2d/%-d\n", item_number, unit_price, month, date, year);

    return 0;
}
