// To illustrate the technique that we've just discussed, let's apply it to a small text-formatting program named justify. As a sample input to justify, we'll use a file named quote that contains the following (poorly formatted) quotation from "The development of the C programming language" by Dennis M. Ritchie (in History of Programming Languages II, edited by T. J. Bergin, Jr., and R.G. Gibson, Jr., Addison-Wesley, Reading, Mass., 1996, pages 671-687):
//          C    is quirky,   flawed,       and   an 
//    enormous   success.       Although accidents of     history 
//      surely  helped,   it evidently    satisfied     a     need
//
//        for   a     system  implementation      language      efficient 
//        enough    to  displace        assembly        language,
//          yet sufficiently    abstract    and fluent    to describe     
//         algorithms   and     interactions    in a    wide variety    
//      of    environments.
//                                --        Dennis      M.      Ritchie
// To run the program from a UNIX or Windows prompt, we'd enter the command
//    justify <quote
// The < symbol informs the operating system that justify will read from the file quote instead of accepting input from the keyboard. This feature, supported by UNIX, Windows, and other operating systems, is called ***input redirection***. When given the quote file as input, the justify program will produce the following output:
//    C is quirky,  flawed,  and  an  enormous  success.  Although 
//    accidents of history surely helped, it evidently satisfied a 
//    need for a system implementation language  efficient  enough 
//    to displace assembly language, yet sufficiently abstract and
//    fluent to describe algorithms and  interactions  in  a  wide
//    variety of environments. -- Dennis M. Ritchie
// 
// The output of justify will normally appear on the screen, but we can save it in a file by using ***output redirection***:
//    justify <quote >newquote
//
// The output of justify will go into another file newquote.
//
// In general, justify's output should be identical to its input, except that extra spaces and blank lines are deleted, and lines are filled and justified. "Filling" a line means adding words until one more word would cause the line to overflow. "Justifying" a line means adding extra spaces between words so that each line has exactly the same length (60 characters). Justification must be done so that the space between words in a line is equal (or as nearly equal as possible). The last line of the output won't be justified.
//
// We'll assume that no word is longer than 20 characters. (A punctuation mark is considered part of the word to which it is adjacent.) That's a but restrictive, of course, but once the program is written and debugged we can easily increase this limit to point that it would virtually never be exceeded. If the program encounters a longer word, it must ignore all characters after the first 20, replacing them with a single asterisk. For example, the word
//    antidisestablishmentarianism 
// would be printed as 
//    antidisestablishment*
//
// Now that we understand what the program should do, it's time to think about a design. We'll start by observing that the program can't write the words one by one as they're read. Instead, it will have to store them in a "line buffer" until there are enough to fill a line. After further reflection, we decide that the heart of the program will be a loop that goes inside something like this: 
//    for (;;) {
//      read_word;
//      if (can't read word) {
//        write content of line buffer without justification;
//        terminate program;
//      }
//      if (word doesn't fit in line buffer) {
//        write contents of line buffer with justification;
//        clear line buffer;
//      }
//      add word to line buffer;
//    }
//
// Since we'll need functions that deal with words and functions that deal with line buffer, let's split the program into three source files, putting all functions related to words in one file (word.c) and all functions related to line buffer in another file (line.c). A third file (justify.c) will contain the main funciton. In addition to these files, we'll need two header files, word.h and line.h. The word.h file will contain prototypes for the functions in word.c; line.h will play a similar role for line.c. 
// By examining the main loop, we see that the only read-related function that we'll need is a read_word function. (If read_word can't read a word because it's reached the end of the input file, we'll have it signal the main loop by pretending to read an "empty" word.) Consequently, the word.h file is a small one.
//
// The line.h file won't be as short as word.h. Our outline of the main loop reveals the need for functions that perform the following operations:
//    1. Write contents of line buffer without justification
//    2. Determine how many characters are left in line buffer
//    3. Write contents of line buffer with justification
//    4. Clear line buffer
//    5. Add word to line buffer
// We'll call these functions flush_line, space_remaining, write_line, clear_line, and add_word.
//
// Before we write the word.c and line.c file, we can use the functions declared in word.h and line.h to write justify.c, the main program. Writing this file is mostly a matter of translating our original loop design into C.

/* Formats a file of text */

#include <string.h>
#include "word.h"
#include "line.h"

#define MAX_WORD_LEN 20

int main (void) {
  char word[MAX_WORD_LEN + 2];
  int word_len;

  clear_line();

  for (;;) {
    // the word is stored from index 0 to 20, resulting in 21 characters. The reason we have +2 in word array is the last character that is stored by read_word will be a null character.
    read_word(word, MAX_WORD_LEN + 1);
    word_len = strlen(word);
    // word_len is 0 only when the read_word encounters the EOF, so, flush_line--a function that writes the line without any justification--is run and the program is exited.
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    // if the word read is more than MAX_WORD_LEN (20), then replace the last character by * indicating that the word is longer than estimated. 
    if (word_len > MAX_WORD_LEN) {
      word[MAX_WORD_LEN] = '*';
    }
    // space_remaining is a function that returns MAX_LINE_LEN - line_len, where line_len is essentially the current length of line. So this if statement essentially checks if the word that is recently read is able to fit into the line, if it does not fit, then first print the current line, clear the line, and then only add the word.
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    // add the word, which includes the space at the end, followed by a null character in the line.
    add_word(word);
  }

  return 0;
}

// Including both word.h and line.h gives the compiler access to the function prototypes in both files as it compiles justify.c 
//
// main uses a trick to handle words that exceeds 20 characters. When it calls read_word, main tells it to truncate any word that exceeds 21 characters. After read_word returns, main checks whether word contains a string that's longer than 20 characters. If so, the word that was read must have been at least 21 characters long (before truncation), so main replaces the word's 21st character by an asterisk.
//
// The only file left is line.c, which supplies definitions of the functions declared in the line.h file. line.c will also need variables to keep track of the state of the line buffer. One variable, line, will store the characters in the curret line. Strictly speaking, line is the only variable need. For speed and convenience, however, we'll use two other variables: line_len (the number of characters in the current line) and num_words (the number of words in the current line).

