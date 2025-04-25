/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M7: Discussion
Professor:      Dr. Robert Flowers
Date:           04/25/2025
File Name:      John_Barron_M7_Discussion.cpp
Description:    This program creates a 2D array and prints '#' for 1s and '.' for 0s.
Originally developed by John-Michael Barron, corrected by Eric Zimmer.

Developed and tested in Visual Studio 2022 (Windows 11).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

/* Created by John-Michael
Programming with C++ (2D arrays)
Program should display a gridded maze, 7 across, 5 down as a rectangle.
hint: my endl; seems a bit impatient. 2 errors, 1 formatting flaw */

#include <iostream>
using namespace std;

const int row = 5;
const int col = 7;

int maze[row][col] = {
    {0, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 1, 1, 0},
    {1, 1, 0, 0, 0, 0, 0}
}; // Semicolon was missing -EZ

void displayTheMaze() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (maze[i][j] == 1) {
                cout << "#";
            }
            else {
                cout << ".";
            }
        }
        cout << endl; // Moved this to the outer loop -EZ
    }
}

int main() {
    cout << "This is my maze hope ya like it!\n";
    displayTheMaze(); // Corrected the function name -EZ
    return 0;
}