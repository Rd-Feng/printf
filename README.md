# _printf
### Overview
This project is a group project built by Holberton School students [Dennis Pham](https://twitter.com/grepdennis) and [Rui Feng](https://twitter.com/Raymond30450868). The goal of this project is to build a C function that produces output according to a format:<br/>
`int _printf(const char *format, ...);`<br/>
where `const char *format` is a character string composed of zero or more directives. The following conversion specifiers are handled:
* %
* c
* s
* d
* i

It works the same as the C standard library function `printf` except the following:
* It doesn't provide the buffer handling of the C library `printf` function
* It doesn't handle the flag characters
* It doesn't handle field width
* It doesn't handle precision
* It doesn't handle the length modifiers

### Requirements
The followings are the requirements of this project:
* All files will be compiled on `Ubuntu 14.04 LTS`
* programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra and -pedantic`
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* All code should use the [Betty Style](https://github.com/holbertonschool/Betty/wiki). It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* Usage of global variables is not allowed
* No more than 5 functions per file
* The prototypes of all functions should be included in the header file called `holberton.h`
* Don’t forget to push the header file
* All header files should be include guarded
* Authorized functions and macros:
    * `write` (`man 2 write`)
    * `malloc` (`man 3 malloc`)
    * `free` (`man 3 free`)
    * `va_start` (`man 3 va_start`)
    * `va_end` (`man 3 va_end`)
    * `va_copy` (`man 3 va_copy`)
    * `va_arg` (`man 3 va_arg`)

### Compilation
Code will be compiled in this way:<br/>
`$ gcc -Wall -Werror -Wextra -pedantic *.c`
