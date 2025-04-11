/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M5: Discussion
Professor:      Dr. Robert Flowers
Date:           04/10/2025
File Name:      Zachary_White_M5_Discussion.cpp
Description:    This program was originally written by Zachary White and modified by Eric Zimmer.
This program gets the length and width of a rectangle, calculates the area
and then prints the results.

Tested on macOS using both:
    g++ -o Zachary_White_M5_Discussion Zachary_White_M5_Discussion.cpp
    clang++ -o Zachary_White_M5_Discussion Zachary_White_M5_Discussion.cpp
*/

#include <iostream>
#include<limits>

using namespace std;

// Primary function to calculate the area
int calculateArea(int length, int width) {
    return length * width;
}

// Secondary to display results
void displayResult(int area) {
    cout << "The area of the rectangle is: " << area << endl; // Semicolon was missing
}

int main() {
    // Get length from user with input validation
	int l = 0;
    cout << "Please enter the length of the rectangle: ";
    // Keep asking for input until input is valid
    while (!(cin >> l) || l <= 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter an integer greater than 0 for length:" << endl;
    }

    // Get width from user with input validation
	int w = 0;
    cout << "Please enter the width of the rectangle: "; // Please was misspelled "Pleas"
    while (!(cin >> w) || w <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer greater than 0 for width:" << endl;
    }

    // Calculate area of rectangle
    int area = calculateArea(l, w); // Changed calculatearea to calculateArea
    // Print results
    displayResult(area);

    return 0;
}