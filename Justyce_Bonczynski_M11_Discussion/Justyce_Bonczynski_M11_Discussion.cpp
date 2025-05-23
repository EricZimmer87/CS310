/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M11: Discussion
Professor:      Dr. Robert Flowers
Date:           05/23/2025
File Name:      Justyce_Boncynski_M11_Discussion.cpp
Description:    This program defines a function template that combines two values
and returns the results. It demonstrates the function template by adding two numbers
and combining two strings.

This program was originally developed by Justyce Boncynski with intentional errors.
The errors were corrected by Eric Zimmer.

Developed and tested in Visual Studio 2022 (Windows).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35207.1.
*/

#include <iostream> 
#include <string>   


template <typename T> // Corrected spelling of "template" -EZ
T combine(T val1, T val2) {
    return val1 + val2; // Missing semicolon -EZ
}

int main() {
    int num1 = 5;
    int num2 = 10;
    int sum = combine(num1, num2);
    std::cout << "Combined integers: " << sum << std::endl;

    std::string s1 = "Hello";
    std::string s2 = "World";
    std::string result = combine(s1, s2);
    std::cout << "Combined strings: " << result << std::endl;

    return 0;
}