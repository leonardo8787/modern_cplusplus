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

initializer_list em C++ é um recurso da linguagem que permite a inicialização de objetos de forma semelhante a um array, porém com tamanho fixo e conhecido em tempo de compilação.

Essa estrutura é definida na biblioteca padrão do C++ pela classe std::initializer_list<T>, onde T é o tipo de dado que será armazenado na lista.

Para usar o initializer_list, basta criar um objeto da classe initializer_list com os valores a serem inicializados, que podem ser passados como uma lista delimitada por chaves ({}) separando os elementos por vírgulas.

Um exemplo simples de uso do initializer_list é a seguinte função que recebe uma lista de inteiros como argumento e retorna a soma dos valores:

~~~
#include <iostream>
#include <initializer_list>

int soma(std::initializer_list<int> lista) {
    int resultado = 0;
    for (auto valor : lista) {
        resultado += valor;
    }
    return resultado;
}

int main() {
    std::cout << soma({1, 2, 3, 4, 5}) << std::endl; // Output: 15
    return 0;
}
~~~

In this example, the function "soma" receives an initializer_list object of integers and iterates over the values of the list, summing them up and returning the result. In the call to the "soma" function in the main function, a list of integers delimited by braces is passed, and the result is printed to the standard output.

The use of initializer_list allows for a simple and concise initialization of objects that need to store a fixed list of values, without the need to create an array or a more complex structure. Additionally, this structure is used by many other classes in the C++ standard library, such as std::vector, std::array, and std::map, to allow for the initialization of their objects with a list of values.

<h2>literais</h2>

In C++, a literal is a sequence of characters that represents a constant value of a specific data type. Literals can be used in expressions to represent data values that do not change during program execution. There are different types of literals in C++, including numeric literals, character literals, string literals, and boolean literals.

Here are some examples of literals in C++:

Numeric literals:
 - 42: represents an integer value of 42.
 - 3.14: represents a floating-point value of 3.14.
 - 0x1F: represents a hexadecimal integer value of 31.
Character literals:
 - 'a': represents the character 'a'.
 - '7': represents the character '7'.
 - '\n': represents the newline character.
String literals:
 - "hello": represents the character sequence "hello".
 - "world": represents the character sequence "world".
Boolean literals:
 - true: represents the true boolean value.
 - false: represents the false boolean value.

Additionally, literals in C++ can have suffixes that indicate the data type they represent. For example:

~~~
int a = 42;
unsigned int b = 42u;
float c = 3.14f;
~~~

These examples illustrate the use of suffixes in literals to indicate the data type they represent.

Literals are a fundamental part of the C++ programming language, as they allow programmers to represent constant values in their programs in a simple and intuitive way.

<h2>Signal</h2>

Signal in C++ refers to a mechanism that allows a program to receive asynchronous notifications of external events outside its normal flow of execution, such as interruption signals from the operating system or hardware events. These events can include the interruption of an ongoing operation, the need to handle an exception situation, a change in the system's state, or the capture of a signal sent by another process.

The C++ standard library provides a set of predefined signals, such as SIGINT for program interruption through a keyboard signal, and SIGSEGV to notify when a memory access violation occurs.

The signal mechanism in C++ is implemented using the concept of a signal handler function, which is a registered function to handle a particular signal. When a signal is received, the operating system interrupts the normal program execution and calls the corresponding signal handler function, which is responsible for handling the event.

A simple example of using signals in C++ is as follows:

~~~
#include <iostream>
#include <csignal>

void signal_handler(int signal) {
    std::cout << "Received signal: " << signal << std::endl;
    std::exit(signal);
}

int main() {
    std::signal(SIGINT, signal_handler); // Registra a função signal_handler para o sinal SIGINT
    std::cout << "Waiting for SIGINT signal..." << std::endl;
    while (true) {} // Loop infinito para esperar o sinal
    return 0;
}
~~~

In this example, the program registers the signal_handler function to handle the SIGINT signal. When the user presses Ctrl+C, the operating system sends the SIGINT signal to the program, which interrupts normal execution and calls the signal_handler function, which prints a warning message and exits the program with the error code corresponding to the received signal.

<h2>Templates</h2>

Templates in C++ are a form of generic programming that allows you to create functions and classes that can be used with different data types without needing to rewrite the code for each specific type. A template defines a generic structure that is later instantiated with a specific type when the function or class is used in the code.

For example, a template function for addition can be written once and then used with different data types such as integers, floating point numbers, etc.:

~~~
template<typename T>
T soma(T a, T b) {
  return a + b;
}

int main() {
  int x = 1, y = 2;
  float f = 1.5, g = 2.5;
  std::cout << soma(x, y) << std::endl; // output: 3
  std::cout << soma(f, g) << std::endl; // output: 4
  return 0;
}
~~~

In this example, the template sum defines a function that takes two arguments of the same type T and returns the sum of those values. In the main function, the sum function is used with two different types: int and float. The C++ compiler creates two instances of the sum function, one for int and another for float, and generates the necessary machine code for each type automatically.


