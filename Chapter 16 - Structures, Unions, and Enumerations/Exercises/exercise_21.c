// Q. What are the integer values of the enumeration constants in each of the following declarations?
//    a. enum { NUL, SOH, STX, ETX };
//    b. enum { VT = 11, FF, CR };
//    c. enum { SO = 14, ST, DLE, CAN = 24, EM };
//    d. enum { ENQ = 45, ACK, BEL, LF = 37, ETB, ESC };
// 
// My Answer:
// The corresponding integer constant for the enumeration constants are:
//  a.  NUL: 0
//      SOH: 1
//      STX: 2
//      ETX: 3
//  b.  VT: 11
//      FF: 12
//      CR: 13
//  c.  SO:   14
//      ST:   15
//      DLE:  16
//      CAN:  24
//      EM:   25
//  d.  ENO:  45 
//      ACK:  46
//      BEL:  47
//      LF:   37
//      ETB:  38
//      ESC:  39
// Actual Output: As Expected.

#include <stdio.h>

int main (void) {

  {
    enum { NUL, SOH, STX, ETX };
    printf("The enumerations constants and their corresponding integer constant are:\n"             \
           "NUL: %d\n"                                                                              \
           "SOH: %d\n"                                                                              \
           "STX: %d\n"                                                                              \
           "ETX: %d\n\n", NUL, SOH, STX, ETX);
  }
  
  {
    enum { VT = 11, FF, CR };
    printf("The enumerations constants and their corresponding integer constant are:\n"             \
           "VT: %d\n"                                                                               \
           "FF: %d\n"                                                                               \
           "CR: %d\n\n", VT, FF, CR);
  }

  {
    enum { SO = 14, ST, DLE, CAN = 24, EM };
    printf("The enumerations constants and their corresponding integer constant are:\n"             \
           "SO:   %d\n"                                                                             \
           "ST:   %d\n"                                                                             \
           "DLE:  %d\n"                                                                             \
           "CAN:  %d\n"                                                                             \
           "EM:   %d\n\n", SO, ST, DLE, CAN, EM);
  }

  {
    enum { ENQ = 45, ACK, BEL, LF = 37, ETB, ESC };
    printf("The enumerations constants and their corresponding integer constant are:\n"             \
           "ENQ:  %d\n"                                                                             \
           "ACK:  %d\n"                                                                             \
           "BEL:  %d\n"                                                                             \
           "LF:   %d\n"                                                                             \
           "ETB:  %d\n"                                                                             \
           "ESC:  %d\n\n", ENQ, ACK, BEL, LF, ETB, ESC);
  }

  return 0;
}

