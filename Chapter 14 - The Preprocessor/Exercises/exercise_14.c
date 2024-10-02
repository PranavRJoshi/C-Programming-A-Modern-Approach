// Q. Show what the following program will look like after preprocessing. Some lines of the program may cause compilation errors; find all such errors.
//
//      #define N = 100
//      #define INC(x) x+1
//      #define SUB (x,y) x-y
//      #define SQR(x) ((x)*(x))
//      #define CUBE(x) (SQR(x) * (x))
//      #define M1(x,y) x##y
//      #define M2(x,y) #x #y
//
//      int main(void) 
//      {
//        int a[N], i, j, k, m;
//
//        #ifdef N 
//          i = j;
//        #else 
//          j = i;
//        #endif 
//
//        i = 10 * INC(j);
//        i = SUB(j, k);
//        i = SQR(SQR(j));
//        i = CUBE(j);
//        i = M1(j, k);
//        puts(M2(i, j));
//
//        #undef SQR
//          i = SQR(j);
//        #define SQR
//          i = SQR(j);
//
//          return 0;
//      }
//
//    The output of the program may be (after we fix some errors in #define directive and executing the program without any initialization for variables used in calculation):
//      -> ij
//      
//    The preprocessor's output for the faulty code:
        // # 1 "exercise_14.c"
        // # 1 "<built-in>" 1
        // # 1 "<built-in>" 3
        // # 400 "<built-in>" 3
        // # 1 "<command line>" 1
        // # 1 "<built-in>" 2
        // # 1 "exercise_14.c" 2
        // # 50 "exercise_14.c"
        //     int main(void)
        //     {
        //      int a[= 100], i, j, k, m;
        //
        //
        //
        //
        //        i = j;
        //
        //
        //
        //
        //      i = 10 * j+1;
        //      i = j-k;
        //      i = ((((j)*(j)))*(((j)*(j))));
        //      i = (((j)*(j))*(j));
        //      i = jk;
        //      puts("i" "j");
        //
        //
        //        i = SQR(j);
        //
        //        i = (j);
        //
        //        return 0;
        //     }
//      

#include <stdio.h>

#define N 100
#define INC(x) ((x)+1)
#define SUB(x,y) ((x)-(y))
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main(void) 
{
 int a[N], i, j, k, m;

// #undef N

 #ifdef N 
   i = j;
 #else 
   j = i;
 #endif 

 i = 10 * INC(j);
 i = SUB(j, k);
 i = SQR(SQR(j));
 i = CUBE(j);
 // i = M1(j, k);        // creates an identifier jk
 puts(M2(i, j));         // missing stdio library

 #undef SQR
   // i = SQR(j);          // cannot call a macro that is undefined
 #define SQR
   i = SQR(j);

   return 0;
}

