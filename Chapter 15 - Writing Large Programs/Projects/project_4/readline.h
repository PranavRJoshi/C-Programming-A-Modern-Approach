#ifndef READLINE_H
#define READLINE_H

/* read_line: takes an array of character arr and its
 *            size 'size' as parameter, and reads the 
 *            input character until a new-line character
 *            is found. If there exists characters in the 
 *            input stream more than the size, then it is
 *            read, but not stored in the array. Returns the
 *            count of characters that are stored in the array.
*/
int read_line (char *arr, int size);

#endif 
