// Q. Write a program that computes the factorial of a positive integer:
//    Enter a positive integer: 6
//    Factorial of 6: 720
// a. Use a short variable to store the value of the factorial. What is the largest value of n for which the program correctly prints the factorial of n?
// b. Repeat part (a), using an int variable instead.
// c. Repeat part (a), using a long variable instead.
// d. Repeat part (a), using a long long variable instead (if your compiler supports the long long type).
// e. Repeat part (a), using a float variable instead.
// f. Repeat part (a), using a double variable instead.
// g, Repeat part (a), using a long double variable instead.
// In cases (e)-(g), the program will display a close approximation of the factorial, not necessarily the exact value.
// Largest number for which the factorial will be not give garbage value:
// short int: 7 -> 5040
// int: 15 -> 2004310016
// long: 20 -> 2432902008176640000
// long long: 20 -> 2432902008176640000
// float: 34 -> 295232822996533287161359432338880069632
// double: 170 -> 7257415615307994045399635715589591467896184117242257803405544211755693246215271577444614997868077640013184176271985826801597743247247979077995336619429980685793285768053360886112149825437081356365699043287884614002788490694530469661753007801896962563721104619242357348735986883814984039817295623520648167424.000000
// long double: 170 -> 7257415615307994045399635715589591467896184117242257803405544211755693246215271577444614997868077640013184176271985826801597743247247979077995336619429980685793285768053360886112149825437081356365699043287884614002788490694530469661753007801896962563721104619242357348735986883814984039817295623520648167424.000000
// For reference, check point #12 (since my machine is of 64-bit architecture), #15, and #41 to get a gist of maximum values for the implemented data types.


#include <stdio.h>

int main (void) {

  int option;
  int count = 1;

  printf("Welcome to the factorial calculator!\n");
  printf("Choose any of the following type to calculate factorial:\n");
  printf("1. Short Integer\n");
  printf("2. Integer\n");
  printf("3. Long Integer\n");
  printf("4. Long Long Integer\n");
  printf("5. Float\n");
  printf("6. Double\n");
  printf("7. Long Double\n");

  printf("Enter an option (1-7): ");
  scanf("%d", &option);

  printf("Enter a positive integer: ");

  switch (option) {
    case 1: {
      short s;
      short result = 1;           // no need to specify the constant specifier
      scanf("%hd", &s);
      while (count <= s) {
        result = result * (short int) count;    // need to explicity convert this as it might get converted to int during the multiplication and then again to short when storing in result variable. No need to explicitly define in other cases as other types are not narrower than int (which is the type of count)
        printf("Count %d and the value is: %hd\n", count, result);
        count++;
      }
      printf("Factorial of %hd is: %hd\n", s, result);
      break;
    }
    case 2: {
      int i;
      int result = 1;               // no need to specify as compiler implicitly defines the types of the constant as integer.
      scanf("%d", &i);
      while (count <= i) {
        result = result * count;
        printf("Count %d and the value is: %d\n", count, result);
        count++;
      }
      printf("Factorial of %d is: %d\n", i, result);
      break;
    }
    case 3: {
      long l;
      long result = 1l;             // or result = 1l
      scanf("%ld", &l);
      while (count <= l) {
        result = result * count;
        printf("Count %d and the value is: %ld\n", count, result);
        count++;
      }
      printf("Factorial of %ld is: %ld\n", l, result);
      break;
    }
    case 4: {
      long long ll;
      long long result = 1ll;       // or result = 1LL
      scanf("%lld", &ll);
      while (count <= ll) {
        result = result * count;
        printf("Count %d and the value is: %lld\n", count, result);
        count++;
      }
      printf("Factorial of %lld is: %lld\n", ll, result);
      break;
    }
    case 5: {
      float f;
      float result = 1.0f;          // or result = 1.0F
      scanf("%f", &f);
      while (count <= f) {
        result = result * count;
        printf("Count %d and the value is: %f\n", count, result);
        count++;
      }
      printf("Factorial of %f is: %f\n", f, result);
      break;
    }
    case 6: {
      double d;
      double result = 1.0;          // no need for suffix as the compiler implicitly defines the constant as double
      scanf("%lf", &d);
      while (count <= d) {
        result = result * count;
        printf("Count %d and the value is: %lf\n", count, result);
        count++;
      }
      printf("Factorial of %lf is: %lf\n", d, result);
      break;
    }
    case 7: {
      long double ld;
      long double result = 1.0l;    // or reuslt = 1.0L
      scanf("%Lf", &ld);
      while (count <= ld) {
        result = result * count;
        printf("Count %d and the value is: %Lf\n", count, result);
        count++;
      }
      printf("Factorial of %Lf is: %Lf\n", ld, result);
      break;
    }
  }

  return 0;
}

