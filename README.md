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

## Some Interesting Projects

Here are some of the exercises/projects that may be interesting to understand:

1. [Queue using Abstract Data Type (ADT)](./Chapter%2019%20-%20Program%20Design/Exercises/exercise_3/). It points to the exercise_3 directory which contains two different implementations of the queue ADT (using an array and a linked list).
2. [Stack ADT which has the "generic" type](./Chapter%2019%20-%20Program%20Design/Projects/project_4/). There are various implementation of the stack ADT (using defined type specifier, type definiton, and such).
3. [Understanding "complex" variable declaration](./Chapter%2018%20-%20Declarations/Exercises/exercise_12.c). The program illustrates one "complex" variable declaration, but understanding one can easily make the reader realize how variable declarations work. [This](./Chapter%2018%20-%20Declarations/Exercises/exercise_8.c) and [this](./Chapter%2018%20-%20Declarations/Exercises/exercise_10.c) can be useful for the reader too.
4. [Function returns and array elements](./Chapter%2018%20-%20Declarations/Exercises/exercise_11.c). This illustrates how we can use the functions to returns type not supported by the language. For instance, a function can't return an array, nor can it return another function. Likewise, an array cannot store function as its elements.
5. [Basic inventory program that doubles the size of the array at runtime](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Projects/project_1/project_1.c). This is one of many `inventory` programs which can be studied to understand various language features. Programming Project 2 and 3 are also part of the `inventory` program with features as described in the question found at the top of the source file.
6. [Sorting various words obtained from standard input](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Projects/project_5/project_5.c). There is also an modification to this program that uses built-in `qsort` library function to sort words which can be found [here](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Projects/project_6/project_6.c).
7. [Reminder program that utilizes flexible array members in a structure](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Projects/project_7/project_7.c). Similar to the `inventory` program, the `reminders` program is used in various chapters and this is one of the latest which includes new features like the usage of `flexible array members` in a structure.
8. [Linked list Implementation](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Exercises/exercise_14.c). This has one functionality added to the linked list described in the Chapter. [Exercise 12](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Exercises/exercise_12.c) and [Exercise 13](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Exercises/exercise_13.c) has some functionality for the linekd list as well.
9. [Very basic "class" in C (sort of)](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Exercises/exercise_19.c). The word "class" in used in a very vague way here. It just means that we created a structure with members such as variables and pointers.
10. [Malloc wrapper](./Chapter%2017%20-%20Advanced%20Uses%20of%20Pointers/Exercises/exercise_1.c). This basic program illustrate the creation of a "wrapper" function for the library function `malloc`.
11. [Mapping country codes](./Chapter%2016%20-%20Structures,%20Unions,%20and%20Enumerations/Projects/project_1.c). This program checks whether the country code entered by the user using the standard input exists in the array of structures. If the country exists, the corresponding country code is shown to the user.
12. [Inventory with price](./Chapter%2016%20-%20Structures,%20Unions,%20and%20Enumerations/Projects/project_4/project_4.c). As stated eariler, this is another one of `inventory` program which requires some modifications as indicated by the question.
13. [Working with dates](./Chapter%2016%20-%20Structures,%20Unions,%20and%20Enumerations/Projects/project_6.c). This program is a modification of previous program (mentioned in the source file), which uses the concept of structure to store dates.
14. [Departure time](./Chapter%2016%20-%20Structures,%20Unions,%20and%20Enumerations/Projects/project_5.c). Another one of the recurring question which uses various concepts as we move on to later chapters. 
15. [Chess](./Chapter%2016%20-%20Structures,%20Unions,%20and%20Enumerations/Exercises/exercise_18.c). This program shows the "chess board" configuration. Also, [this one](./Chapter%2016%20-%20Structures,%20Unions,%20and%20Enumerations/Exercises/exercise_22.c) is also regarding chess...
16. [Working with fractions](./Chapter%2016%20-%20Structures,%20Unions,%20and%20Enumerations/Exercises/exercise_7.c). This program utilizes the idea of structure to make rational numbers which is then used for basic mathematical operations like addition, subtraction, multiplication, and division.
17. [Justifiy THIS!](./Chapter%2015%20-%20Writing%20Large%20Programs/Projects/project_1/project_1.c). The `justify` set of programs are interesting to understand. As the name implies, the program is used to justify the unformatted text which is provided to the program. NOTE: To use this program, first prepare the executable by using the `make` command. Then, use the input redirection (`<`) to feed the program the input, i.e. use `./project_1 < quote`. If you want to the formatted text to be output somewhere apart from the standard output, use the output redirection (`>`), i.e. `./project_1 < quote > test_test`.
18. [Split the sort](./Chapter%2015%20-%20Writing%20Large%20Programs/Projects/project_3/project_3.c). This program illustrates breaking the source file into multiple files. Make sure to read the `Makefile` to get some more understanding. Small thing regarding the "magic symbols" in `Makefile`. You may encounter `Makefile`s with symbols like `$@`, `$<`, and `$^`. Before jumping into these symbols, Makfile has the following structure:

    ```make
    target: prerequisite
        commands        # make requires tabs, not spaces.
    ```

    Here, `$@` will be replaced by the "target", `$<` will be replaced by the first prerequisite, and `$^` will be replaced by all the prerequisite specified.

19. [Macro expansion](./Chapter%2014%20-%20The%20Preprocessor/Exercises/exercise_14.c). This program is useful to understand basic macro expansion along with concept of conditional compilation. NOTE: Use the `-E` flag in compilation to generate the source file after preprocessor processes the macros and directives. [This program](./Chapter%2014%20-%20The%20Preprocessor/Exercises/exercise_13.c) also showcase the program before and after preprocessing. To learn about macro and function, [Exercise 10](./Chapter%2014%20-%20The%20Preprocessor/Exercises/exercise_10.c) provides some basic understanding.
20. ["Generic" macros](./Chapter%2014%20-%20The%20Preprocessor/Exercises/exercise_7.c). This program provides a basic macro expansion for a macro that's "generic". It just expands into function definition which can be used later in the program.