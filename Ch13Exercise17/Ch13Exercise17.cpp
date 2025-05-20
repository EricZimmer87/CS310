/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M11: Assignment
Professor:      Dr. Robert Flowers
Date:           05/20/2025
File Name:      Ch13Exercise17.cpp
Description:    This program generates 25 random real numbers between 10-100, stores them in
an array, and then prints them.

Developed and tested in Visual Studio 2022 (Windows 11).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35207.1.
*/

#include <iostream>
#include <random>
#include <iomanip>

int main() {
    // Amount of numbers to generate
    const int SIZE = 25;
    // Array to store the random numbers
    double numbers[SIZE] = {};

    // Get a random seed from the system
    std::random_device rdevice{};
    // Use the default random engine
    std::default_random_engine num{ rdevice() };
    // Real numbers between 10-100, inclusive of 10, exclusive of 100
    std::uniform_real_distribution<double> randomNum{ 10, 100 };

    // Generate the random numbers
    for (unsigned int i = 0; i < SIZE; i++) {
        numbers[i] = randomNum(num);
    }

    // Print the numbers, rounded to two decimal places
    std::cout << std::fixed << std::setprecision(2);
    for (unsigned int i = 0; i < SIZE; ++i) {
        std::cout << "Number " << i + 1 << ":\t" << numbers[i] << std::endl;
    }

    return 0;
}