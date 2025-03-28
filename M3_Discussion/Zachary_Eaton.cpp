/*
Date: 3/27/2025
File Name: Zachary_Eaton.cpp
Description: This is Zachary Eaton's original program, errors corrected by
Eric Zimmer.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string dayOfWeek;

    // Input
    cout << "Enter the day of the week (i.e Monday, Tuesday, etc.): ";
    cin >> dayOfWeek;

    // Selection control
    if (dayOfWeek == "Sunday") { // Changed "=" to "==" -Eric Zimmer
        cout << "Weekly assignments are due today, better get to it!" << endl;
    }
    else {
        cout << "You still have time to complete your weekly assignments!" << endl;
    }

    return 0; // Changed "O" to "0"
}