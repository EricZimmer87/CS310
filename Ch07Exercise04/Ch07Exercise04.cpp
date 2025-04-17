/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M6: Assignment
Professor:      Dr. Robert Flowers
Date:           04/17/2025
File Name:      Ch07Exercise04.cpp
Description:    This program gets a string from the user, ensures it is not empty,
removes vowels from the string, compares the before and after strings to determine
if there were vowels, then prints the modified string.

Tested on macOS using CMake and:
    g++ -o Ch07Exercise04 Ch07Exercise04.cpp
    clang++ -o Ch07Exercise04 Ch07Exercise04.cpp

To compile with CMakeLists.txt:
    cmake -S . -B build
    cmake --build build

To run:
    cmake --build build --target run

To clean up build files:
    cmake --build build --target clean-all
*/

#include <iostream>
#include <cctype> // for tolower() function
#include <string>

using namespace std;

string getInput(const string& msg);
string removeVowels(const string& s);
bool isVowel(char c);
char my_tolower(char ch);

int main() {
    // Get user input
    string userInputBefore = getInput("Please enter a string (one line):");
    // Print user input
    cout << "You entered: " << userInputBefore << endl;
    cout << "Processing..." << endl;

    // Remove vowels (if there are any)
    string userInputAfter = removeVowels(userInputBefore);

    // Determine if any vowels have been removed
    if(userInputBefore == userInputAfter) {
        // No vowels were removed, print appropriate message
        cout << "The string entered contained no vowels, thus remains unchanged: " << userInputAfter << endl;
    } else {
        // Vowels were removed, print appropriate message
        cout << "Your string after removing vowels: " << userInputAfter << endl;
    }

    return 0;
}

string getInput(const string& msg) {
    /*
    Gets and returns a string input from the user.
    Pass in the message you want to print to the user before getting the input.
    */
   // std::string automatically ensures a null terminator at the end of the string - no need to manually check
    string userInput = "";
    // Ask user for input until input is valid
    while (true) {
        // Prints the message passed in
        cout << msg << endl;
        // Get user input
        getline(cin, userInput);
        // Determine if the input is empty
        if (userInput.empty()) {
            // Input is empty, print message and wait for input again
            cout << "Invalid input." << endl;
            continue;
        }
        // Valid input
        break;
    }
    // Return the validated input
    return userInput;
}

string removeVowels(const string& s) {
    /*
    This function removes all vowels from a string.
    */
   // New string to return
   string result = "";

   // Iterate through the string
   for(size_t i = 0; i < s.length(); i++) {
        // If the current character is not a vowel, add the character to the new string
        if (!isVowel(s[i])) {
            // Concatenate the non-vowel character from string 's' at index 'i' as a substring of length 1
            result += s.substr(i, 1);
        }
   }
    // Return the new string
    return result;
}

char my_tolower(char ch) {
    /*
    This is a helper function to safely convert any character to lower case.
    */
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

bool isVowel(char c) {
    /*
    This function determines if the character is a vowel and returns true if it is a vowel, else false.
    */
    // Ensure the character is lowercase
    c = my_tolower(c);
    // Check if the character is a vowel
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
