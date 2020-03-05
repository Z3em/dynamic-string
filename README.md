# Simple dynamic string implementation


A very simple implementation of dynamic strings in C++11.
* Written from scratch - does not use any other implementation of dynamic strings, containers or smart pointers
* Has copy constructor and concatenation operator (+)
* Supports move semantics
* Supports strings of arbitrary length through the use of calloc and free

Includes the header library containing the class (dynastring.hpp) and a sample program utilizing it (string_sorter.cpp). The sample program takes a text file as an argument and outputs its content in reverse lexicographical order. If no arguments are provided the program uses input.txt instead.