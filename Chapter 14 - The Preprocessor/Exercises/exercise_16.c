// Q. (C99) Assume that the following macro definitions are in effect:
//      #define IDENT(x) PRAGMA(ident #x) 
//      #define PRAGMA(x) _Pragma(#x)
//  What will the following line look like after macro expansion? 
//      IDENT(foo)
//
//  The expansion will look like this (see #66 of Chapter's notes): 
//    IDENT(foo) ---> PRAGMA(ident #foo) ---> PRAGMA(ident "foo") ---> _Pragma("ident "foo"") ---> _Pragma("ident \"foo\"") ---> #pragma ident "foo"

#include <stdio.h>

#define IDENT(x) PRAGMA(ident #x) 
#define PRAGMA(x) _Pragma(#x)

int main (void) {

  IDENT(foo)

  return 0;
}
