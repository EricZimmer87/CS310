/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M11: Discussion
Professor:      Dr. Robert Flowers
Date:           05/20/2025
File Name:      M11_Discussion.cpp
Description:    This program creates a function template that computes and returns
the average from a numeric vector.
It has two intentional errors. Find them.

Developed and tested (before errors) in Visual Studio 2022 (Windows).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35207.1.
*/

#include <iostream>
#include <vector>

// Function template
template <typename T>
int average(const std::vector<T>& nums) {
    /*
    This function takes in a vector of any numeric data type, calculates the
    average of the numbers and returns it.
    */
    // Edge case: empty vector
    if (nums.empty()) return T{};

    T sum = T{};
    // Iterate through the vector
    for (const T& val : nums) {
        // Add the current element to the running sum
        sum += val;
    }

    // Return average: sum / length of vector
    return sum / static_cast<T>(nums.size());
}

int main() {
    // Initialize an int vector and a double vector
    std::vector<int> intNums{ 1, 2, 3, 4, 5 };
    std::vector<T> doubleNums{ 1.2, 3.4, 5.6, 7.8 };


    // The average function template is used on both int and double vectors
    std::cout << "Average (int): " << average(intNums) << "\n";
    std::cout << "Average (double): " << average(doubleNums) << "\n";

    return 0;
}

