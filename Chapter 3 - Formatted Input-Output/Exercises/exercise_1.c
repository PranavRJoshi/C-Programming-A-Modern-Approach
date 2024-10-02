// Expected Outputs (underscore represents blank space):
// a. printf("%6d,%4d", 86, 1040) -> ____86,1040
// b. printf("%12.5e", 30.253) -> ___3.0253x10 // i forgot x10 is not a form of floating point, we use e instead
// c. printf("%.4f", 83.162) -> 81.1620
// d. printf("%-6.2g", .0000009979) -> 9.979e-6(?) // bad at figuring out the value of e for decimal values

// Actual o/p code

#include <stdio.h>

int main (void) {
    printf("%6d,%4d\n", 86, 1040);
    printf("%12.5e\n", 30.253);
    printf("%.4f\n", 83.162);
    printf("%-6.2g\n", .0000009979);

    return 0;
}

// output:
//     86,1040
//  3.02530e+01
// 83.1620
// 1e-06
