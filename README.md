# Book: C Programming - A Modern Approach
# Author: K.N. King

## Description

The repo contains my solution to the exercises and projects given in the book. The answers--although provides the expected answers--is still prone to unexpected input.

## Understanding the Code

The code provided are documented. Since there are plenty of exercises which refers to the previous ones, the logic of the code is documented in the preceeding exercises. For instance, there may be some exercise/project in, say, Chapter 10,  which refers to modifying the program from, say, Chapter 5. For such programs, the documentation is provided in Chapter 5 and is not found in the program of Chapter 10. This helps documenting the code easier and no redundant comments are there.

## Running the Program

Each sub-directories has `Makefile` which can prepare the executable for the contents in the respective sub-directories. The provided `Makefile` is basic to say the least, but it performed as wanted on my machine. To test out a program, simply change the directory to the given sub-directory and enter the `make` command on the shell. Example:

```bash
# Change to the required sub-directory.
cd Chapter\ 19\ -\ Program\ Design/Exercises/exercise_3

# makes the program, target is usually optional. 
make <target>

# After done with the program, clean up executable and object files by entering:
make clean
```

## A Word of Caution

The code provided is not tested for various inputs that can be provided. Most programs in the later chapters contains some mechanism to only take the desired input and discard the unwanted ones. 

## Support the Author

K.N. King has provided a concise yet descriptive book that provides insight on the C programming language. The book provides exercises and projects to the readers as challenges while reading the book. The exercises and projects are not *too* difficult yet provides usuage of projects on real world applications. The book can be purchased from [here](http://knking.com/books/c2/index.html).