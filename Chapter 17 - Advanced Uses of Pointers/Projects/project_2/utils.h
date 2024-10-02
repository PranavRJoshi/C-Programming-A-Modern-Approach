#ifndef UTILS_H
#define UTILS_H

/*
 * read_line: Reads a line from an input string till the new-line character (\n) is found.
 *            Reads n characters and stores it in character array str. If the input stream
 *            contains more than n characters, remaining characters are read but not stored.
*/
int read_line (char *str, int n);

/*
 * clear_input_stream:  Clears the input stream. That is, reads the input till the new-line
 *                      character is found.
*/
void clear_input_stream (void);

#endif

