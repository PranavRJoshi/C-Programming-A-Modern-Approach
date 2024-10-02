#ifndef UTILS_H
#define UTILS_H

/*
 * read_line: Reads the line from the input buffer, and stores n character in the character array str.
 *            If the input stream contains more than n characters, remaining characters are discarded.
 *            Note that str should be an array of n + 1 character, as the function assumes storage of 
 *            n characters while having a space for a null character.
*/
int read_line (char *str, int n);

/*
 * my_strcmp: Compares two strings str_1 and str_2. If the provided strings are same, returns 0, else 
 *            returns the ASCII difference of str_2 from str_1. Note that the str_1 and str_2 should
 *            be null terminated since it is the terrminating condition.
*/
int my_strcmp (const char *str_1, const char *str_2);

#endif /* UTILS_H */
