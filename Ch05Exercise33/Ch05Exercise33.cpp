/*
Student's Name: Eric Zimmer
Date: 04/01/2025
File Name: Ch05Exercise33.cpp
Description: This program gets the following values from the user:
    - (a) How many minutes it takes to prepare the first dish
    - (b) How many minutes longer each dish takes than the previous dish
    - (t) How many minutes there are to prepare the dish
It then calculates how many dishes can be prepared and returns that amount.
*/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    // Get a - has to be greater than 0 to avoid an infinite loop later
    int a;
    cout << "How many minutes does it take Bianca to prepare the first dish? " << endl;
    // Keep asking for input until input is valid
    while (!(cin >> a) || a <= 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid whole number greater than 0:" << endl;
    }

    // Get b
    int b;
    cout << "How many minutes longer does each following dish take than the previous dish? " << endl;
    while (!(cin >> b) || b < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid whole number greater than or equal to 0:" << endl;
    }

    // Get t
    int t;
    cout << "How many minutes does Bianca have to prepare the dish? " << endl;
    while (!(cin >> t) || t < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid whole number greater than or equal to 0:" << endl;
    }

    // Calculate the number of dishes Bianca can prepare

    // If the amount of time for the first dish is less than the total time, Bianca does not have time
    // to prepare a single dish.
    if (a > t) {
        cout << "Bianca does not have time to prepare any dishes." << endl;
        return 0;
    }

    // Track how much time there is left
    // We've already determined there is time for the first dish, so consider that
    int remaining_time = t - a;
    // Track how many dishes can be prepared
    int count = 1;
    // Track how long the current dish takes
    int currentDishTime = a;

    // As long as there is time left, see if there is enough time for another dish
    while (remaining_time > 0) {
        // Update currentDishTime
        currentDishTime += b;
        // Is there enough time for another dish?
        if (currentDishTime <= remaining_time) {
            // There is enough time for another dish
            // Add another dish
            count++;
            // Update the remaining time
            remaining_time -= currentDishTime;
        } else {
            // There is not enough time for another dish.
            break;
        }
    }

    // Print how many dishes Bianca can prepare
    if ( count == 1) {
        cout << "Bianca can only prepare one dish." << endl;
    } else {
        cout << "Bianca can prepare " << count << " dishes." << endl;
    }

    return 0;
}