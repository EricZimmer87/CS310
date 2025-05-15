/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M10: Discussion
Professor:      Dr. Robert Flowers
Date:           05/15/2025
File Name:      Kevin_Marler_M10_Discussion.cpp
Description:    This program was originally developed by Kevin Marler with intentional errors
that I corrected. It demonstrates how to use pointers to change the value of an int
variable indirectly, by modifying the value at its memory address.

Developed and tested in Visual Studio 2022 (Windows).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>

int main() {
    // Let's start with a itsy bitsy integer.
    int theNumber = 25;

    // Now, let's declare a pointer. a kind of special variable if you will.
    // this is what holds the memory address of another variable. so it may hold it over it forever
    int* myPointer;

    // We use the '&' (address-of) operator to get the memory location of 'theNumber' i feel like this also needs some like dun dun dun type music just a side note
    // and then we assign that address to our pointer, 'myPointer'.
    myPointer = &theNumber;

    // Let's take a looky loo at what we've got.
    std::cout << "The initial value tucked away in our number variable: " << theNumber << std::endl;
    std::cout << "Where in memory our number variable resides: " << &theNumber << std::endl;
    std::cout << "The memory address our pointer, 'myPointer', is currently holding: " << myPointer << std::endl;
    std::cout << "Ah, and here's the value we can find by 'dereferencing' the pointer "
        << "(using the '*' operator) - it's the value at that memory address: " << *myPointer << std::endl;

    // Now for a little demonstration of the power of pointers.
    // By dereferencing 'myPointer' and assigning a new value, we're actually
    // changing the value of the original 'theNumber' variable!  i am trying and not doing great at keeping these super short
    *myPointer = 50; // Changed to '*myPointer' - added the asterisk. -EZ

    // Let's see the result of our pointer manipulation.
    std::cout << "\nAfter using the pointer to change things up, the new value of our number is: " << theNumber << std::endl; // Change to 'endl' -EZ
    std::cout << "And just to confirm, the value we get by dereferencing the pointer now reflects that change: " << *myPointer << std::endl;

    // All done here. Returning 0 signals successful execution.
    return 0;
}