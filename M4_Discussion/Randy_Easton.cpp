//
// Created by Randy Easton on 3/31/2025.
// Errors corrected by Eric Zimmer on 04/03/2025
// Hint: there are 4 errors, 2 Easy, 1 medium, 1 Hard GL | Not anymore -Eric Zimmer

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Variables
    int num;
    vector<int> numbers;
    string userName;

    // Input
    cout << "Enter your first name: ";
    cin >> userName;

    // Errors in this while loop section that gets numbers from user:
    // I moved "cin >> num" into the while condition and added the "&& operator"
    // The while loop was missing the first left curly bracket "{"
    // Before moving the "cin >> num", the variable num was not initialized to anything, causing an error
    cout << "Enter a number (enter -1 to stop): ";
    while (cin >> num && num != -1) {
        numbers.push_back(num);
    }

    cout << "You entered " << numbers.size() << " numbers." << endl;

    // Output numbers using a loop
    cout << "Here are your numbers: ";
    for (int i = 0; i < numbers.size(); i++) { // Changed "<=" to "<"
        cout << numbers[i] << " "; // Changed "x" to "i" for the numbers index
    }

    cout << endl;
    return 0;
}