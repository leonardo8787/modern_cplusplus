# modern_cplusplus
Repositório do estudo de C++ moderno.

<h2>Sumário</h2>

 - templates
 - signal
 - literais
 - initializer_list
 - bigInt
 - argv

<h2>Argv</h2>

In C++, the argv variable is also used to access the command-line arguments passed to a program. Like in C, argv is typically declared as char *argv[] in C++.

Here's an example of how argv can be used in a C++ program:

~~~
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "The name of the program is " << argv[0] << std::endl;
    if (argc > 1) {
        std::cout << "The first argument is " << argv[1] << std::endl;
    }
    return 0;
}
~~~

In this example, argc represents the number of command-line arguments passed to the program, including the program name itself. argv is an array of char pointers that holds the actual arguments as C-style strings.

The program first prints out the name of the program by accessing argv[0]. It then checks if there is at least one additional argument (argc > 1), and if so, it prints out the first argument by accessing argv[1].

Note that argv is a mutable array of pointers to non-const characters. If you need to modify the contents of the command-line arguments, you should copy them to a new buffer or string.

<h2>bigInt</h2>

<h4>Sum</h4>
If the two strings you need to add are too large to be represented as integers in C++, you can add them character by character, as if they were column numbers.

The algorithm for adding two strings of big numbers would be as follows:

 - Initialize two number strings, let's say str1 and str2.
 - Check which string is larger in size. If necessary, swap the strings so that str1 is always the larger one.
 - Add zeros to the left of the smaller string so that they both have the same size.
 - Create an empty third string, let's call it result.
 - Initialize a carry variable with a value of zero.
 - Traverse the strings from right to left, adding the digits in the same position and the value of carry. Add the result to the result string and update carry with the value of the sum divided by 10 (rounded down).
 - If there is any value left in carry at the end of the sum, add it to the beginning of the result string.
 - The final result will be the result string.
 
 <h4>subtraction</h4>
 
 To subtract two number strings in C++, you can follow a similar algorithm to addition, but with some important differences.

The algorithm for subtracting two number strings would be as follows:

 - Initialize two number strings, let's say str1 and str2.
 - Check which string is larger in size. If necessary, swap the strings so that str1 is always the larger one.
 - Add zeros to the left of the smaller string so that they both have the same size.
 - Create an empty third string, let's call it result.
 - Initialize a borrow variable with a value of zero.
 - Traverse the strings from right to left, subtracting the digits in the same position and the value of borrow. Add the result to the result string and update borrow with the value of the subtraction. If the value of borrow is negative, add 10 to it and subtract 1 from the next digit.
 - If the result string starts with zeros, remove them.
 - If the strings are equal, return a "0" string. Otherwise, the final result will be the result string.
 
 <h4>multiplication</h4>
 
 To multiply two number strings in C++, you can follow a similar algorithm to hand multiplication, but with some important differences.

The algorithm for multiplying two number strings would be as follows:

 - Initialize two number strings, let's say str1 and str2.
 - Check which string is larger in size. If necessary, swap the strings so that str1 is always the larger one.
 - Initialize an empty string, let's call it result, to store the multiplication result.
 - Traverse the smaller string from right to left and, for each digit, multiply the larger string by that digit and add the result to the result string.
 - After the multiplication, add zeros to the right of the result string according to the position of the multiplier digit.
 - Add up all the values in the result string.
 - If the result string starts with zeros, remove them.
 - If one of the strings is "0", return a "0" string. Otherwise, the final result will be the result string.
 
 <h4>subtraction</h4>

<h2>Initializer_list</h2>

<h2>literais</h2>

<h2>Signal</h2>

<h2>Templates</h2>
