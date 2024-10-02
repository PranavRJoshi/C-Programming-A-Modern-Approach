// Q. a. Show what the program will look like after preprocessing. You may ignore any lines added to the program as a result of including the <stdio.h> header.
//      #include <stdio.h>
//
//      #define N 100
//
//      void f(void);
//
//      int main(void) 
//      {
//        f();
//      #ifdef N 
//      #undef N 
//      #endif
//
//        return 0;
//      }
//
//      void f(void) 
//      {
//        #if defined(N)
//          printf("N is %d\n", N);
//        #else 
//          printf("N is undefined\n");
//        #endif
//      }
//    b. What will be the output of this program?

// a. The program after the preprocessing will be (in its simplest form--remove stdio library and its functions and add a random variable initialization inside the function call):
        // # 1 "exercise_13.c"
        // # 1 "<built-in>" 1
        // # 1 "<built-in>" 3
        // # 400 "<built-in>" 3
        // # 1 "<command line>" 1
        // # 1 "<built-in>" 2
        // # 1 "exercise_13.c" 2
        // # 41 "exercise_13.c"
        // void f(void);
        //
        // int main(void)
        // {
        //  f();
        //
        //
        //
        //
        //  return 0;
        // }
        //
        // void f(void)
        // {
        //
        //
        //
        //
        //
        //    int x = 10;
        //
        // }
        //
//      
//      The actual question's output:
        //      stdio's content
        //      ...
        //
        // extern int __vsnprintf_chk (char * restrict, size_t, int, size_t,
        //        const char * restrict, va_list);
        // # 417 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdio.h" 2 3 4
        // # 68 "exercise_13.c" 2
        //
        //
        //
        // void f(void);
        //
        // int main(void)
        // {
        //  f();
        //
        //
        //
        //
        //  return 0;
        // }
        //
        // void f(void)
        // {
        //
        //
        //
        //
        //    printf("N is undefined\n");
        //
        //
        // }
        //
        //
// b. The output of the program will be:
//      -> N is undefined
//

#include <stdio.h>

#define N 100

void f(void);

int main(void) 
{
 f();
#ifdef N 
#undef N 
#endif

 return 0;
}

void f(void) 
{
 #if defined(N)
   printf("N is %d\n", N);
   int y = 20;
 #else 
   printf("N is undefined\n");
   // int x = 10;
 #endif
}
