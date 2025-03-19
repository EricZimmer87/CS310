/*
Student's Name: Eric Zimmer
Date: 3/19/2025
File Name: M2_Discussion.cpp
Description: This program asks for the user's first name and last name.
It then prints a 'hello' message and asks for the user's favorite course.
If the favorite course is not 'Programming with C++' then the program prints
"Wrong!" otherwise it prints "Correct!"
*/

#include <iostream>

using namespace std;

int main() {
    string firstName;
    string lastName;

    // Get first name
    cout << "What is your first name?" << endl;
    cin << firstName;

    // Get last name
    cout << "What is your last name?" << endl;
    cin >> lastName;

    // Clear input buffer before getline()
    cin.ignore();

    // Get favorite course
    string favoriteCourse;
    cout << "Hello, " << firstName << " " << lastName << "! What is your favorite course?" endl;
    getline(cin, favoriteCourse);

    // If favorite course is not 'Programming with C++', print wrong, else print correct
    if (favoriteCourse != "Programming with C++") {
        cout << "Wrong! Your favorite course is Programming with C++!" << endl;
    }
    else {
        cout << "Correct!" << endl;
    }

    return 0;
}
