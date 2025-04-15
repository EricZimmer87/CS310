/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M6: Discussion
Professor:      Dr. Robert Flowers
Date:           04/15/2025
File Name:      M6_Discussion.cpp
Description:    This program asks the user how long they've been studying LeetCode, determines
the user's level, then prints a message based off the user's level.
It has errors. Find them.

Tested on macOS (before errors) using both:
    g++ -o M6_Discussion M6_Discussion.cpp
    clang++ -o M6_Discussion M6_Discussion.cpp
*/

#include <iostream>
#include <limits>

using namespace std;

// Enum for LeetCode level
enum LeetCodeLevel {
    BEGINNER = 2,
    AMATEUR = 4,
    NOVICE = 6
    EXPERT = 999
}

int main() {
    // Get months studied from user
    int monthsStudied = 0;
    cout << "How many months have you studied LeetCode?" << endl;
    // Keep asking for input until input is valid
    while (!(cin >> monthsStudied) || monthsStudied < 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid whole number greater than or equal to 0:" << endl;
    }

    // If the user has studied 0 months, print message and exit program
    if (monthsStudied == 0) {
        cout << "0 months? Bold strategy. Let's see how it works out." << endl;
        return 0;
    }

    // Assign the user's level based off the months they've studied using the enum we created
    currentLevel = BEGINNER;
    if (monthsStudied <= BEGINNER) {
        currentLevel = BEGINNER;
    } else if (monthsStudied <= AMATEUR) {
        currentLevel = AMATEUR;
    } else if (monthsStudied <= NOVICE) {
        currentLevel = NOVICE;
    } else {
        currentLevel = EXPERT;
    }

    // Print appropriate message based off the user's level
    switch(currentLevel) {
        case BEGINNER:
            cout << "You're a beginner. Welcome to the club. Say goodbye to sanity." << endl;
            break;
        case AMATEUR:
            cout << "You're an amateur. Congratulations, now you can Google faster." << endl;
            break;
        case NOVICE:
            cout << "You're a novice. Hardwork or obsession? Either way, it's starting to pay off." << endl;
            break;
        case EXPERT:
            cout << "You're an expert. I'm not worthy! I'm not worthy!" << endl;
            break;
        default:
            cout << "Unable to determine your level. Try restarting your computer." << endl;
    }
    
    return 0;
}