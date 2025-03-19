/*
Student's Name: Eric Zimmer
Date: 3/17/2025
File Name: Ch03Exercise07.cpp
Description: This program asks the user for the net balance,
payment, number of days in the billing cycle, number of days
the payment is made before the billing cycle, and interest rate
per month. It then outputs the interest rounded to two decimal places
and using the thousands separator for the dollar amounts.
*/

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
    // Get net balance
    double netBalance;
    cout << "What is the net balance: " << endl;
    // Keep asking for input until input is valid
    while (!(cin >> netBalance) || netBalance < 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid number greater than or equal to 0:" << endl;
    }

    // Get payment
    double payment;
    cout << "What is the payment:" << endl;
    while (!(cin >> payment) || payment < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number greater than or equal to 0:" << endl;
    }

    // Get number of days in the billing cycle (d1)
    int d1;
    cout << "What is the number of days in the billing cycle:" << endl;
    while (!(cin >> d1) || d1 <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number greater than 0:" << endl;
    }

    // Get number of days payment is made before the billing cycle (d2)
    int d2;
    cout << "What is the number of days payment is made before the billing cycle:" << endl;
    while (!(cin >> d2) || d2 <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number greater than 0:" << endl;
    }

    // Get interest rate per month
    double interestRate;
    cout << "What is the interest rate per month:" << endl;
    while(!(cin >> interestRate) || interestRate < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number greater than or equal to 0:" << endl;
    }

    // Calculate the average daily balance
    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    // Calculate the interest
    double interest = averageDailyBalance * interestRate;

    // Print interest
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    cout << "\nInterest: $" << interest << endl;

    return 0;
}