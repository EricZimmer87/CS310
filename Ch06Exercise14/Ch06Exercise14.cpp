/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M5: Assignment
Professor:      Dr. Robert Flowers
Date:           04/09/2025
File Name:      Ch06Exercise14.cpp
Description:    This program gets the hourly rate and total consulting time from the user and then
asks the user if they have low income. It then calculates and prints the total billing amount.

Tested on macOS using CMake and:
    g++ -o Ch06Exercise14 Ch06Exercise14.cpp
    clang++ -o Ch06Exercise14 Ch06Exercise14.cpp

To compile with CMakeLists.txt:
    cmake -S . -B build
    cmake --build build

To run:
    cmake --build build --target run

To clean up build files:
    cmake --build build --target clean-all
*/

#include <iostream>
#include <limits>
#include <cctype>
#include <iomanip>

using namespace std;

double getInput(string msg);
bool getYesOrNo(string msg);
double calculateBillingAmount(double hourlyRate, double consultingTime, bool lowIncome);
void printBillingAmount(double billingAmount);

int main() {
    // Get hourly rate
    double hourlyRate = getInput("What is the hourly rate? ");
    // Get total consulting time
    double consultingTime = getInput("What is the total consulting time in minutes? ");
    // Ask user if they have low income
    bool lowIncome = getYesOrNo("Do you have low income (<= $25,000)? (y/n) ");

    // Calculate the billing amount
    double billingAmount = calculateBillingAmount(hourlyRate, consultingTime, lowIncome);

    // Print the billing amount
    printBillingAmount(billingAmount);

    return 0;
}

double getInput(string msg) {
    /*
    Gets a numeric value (double) from user that must be greater than or equal to 0.
    Pass in the message you want to print to the user before getting the input.
    */
    double userInput = 0.0;
    cout << msg << endl;
    // Keep asking for input until input is valid
    while (!(cin >> userInput) || userInput < 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid number greater than or equal to 0:" << endl;
    }
    return userInput;
}

bool getYesOrNo(string msg) {
    /*
    Asks the user for input based on the string parameter. User must enter 'y' or 'n' and the result
    is returned as a bool value.
    */
    char input = '\0';
    bool lowIncome = false;
    do {
        // Print message
        cout << msg << endl;
        // Get input
        cin >> input;
        // Ensure input is lowercase
        input = tolower(input);
        // Check for valid input
        if(input == 'y') {
            lowIncome = true;
            break;
        } else if(input == 'n') {
            lowIncome = false;
            break;
        } else {
            // Invalid input
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (true); // Keep asking for input until input is valid
    return lowIncome;
}

double calculateBillingAmount(double hourlyRate, double consultingTime, bool lowIncome) {
    /*
    This function calculates the billing amount. If the user is below the threshold for low income or not low income,
    the user is not charged anything. Otherwise, the user is charged different rates depending on whether they have low
    income or not.
    */
    // Declare constants
    const int LI_SC_THRESHOLD = 30;
    const double LI_SC_RATE = 0.4;
    const int HI_SC_THRESHOLD = 20;
    const double HI_SC_RATE = 0.7;
    double billingAmount = 0; // Amount to return
    if(lowIncome) {
        // If the user has low income and the consulting time is greater than the threshold, charge the appropriate amount
        // If the user has low income and is at or below the threshold for consulting time, there is no charge
        if(consultingTime > LI_SC_THRESHOLD) {
            billingAmount = hourlyRate * LI_SC_RATE * ((consultingTime - LI_SC_THRESHOLD) / 60.0);
        }
    } else {
        // If the user has high income and the consulting time is greater than the threshold, charge the appropriate amount
        // If the user has high income and is at or below the threshold for consulting time, there is no charge
        if(consultingTime > HI_SC_THRESHOLD) {
            billingAmount = hourlyRate * HI_SC_RATE * ((consultingTime - HI_SC_THRESHOLD) / 60.0);
        }
    }
    return billingAmount;
}

void printBillingAmount(double billingAmount) {
    /*
    This function prints the billing amount, rounding to two decimal places.
    */
    // Set output format
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    // Print the billing amount
    cout << "Billing amount: $" << billingAmount << endl;
}