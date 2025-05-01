/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M8: Discussion
Professor:      Dr. Robert Flowers
Date:           05/01/2025
File Name:      Norman_Cervantes_M8_Discussion.cpp
Description:    This program defines a BankAccount and TransactionLogger class. It uses these classes to
create an account, deposit into the account, withdraw from the account, and print the transaction logs.

Developed and tested in Visual Studio 2022 (Windows 11).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// CLASS 1: BankAccount
class BankAccount {
private:
    string ownerName;
    double balance;
public:
    BankAccount(string name, double initialBalance) {
        ownerName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit amount.\n";
    }

    void withdraw(double amount) {
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    string getOwner() const {
        return ownerName;
    }

    void printInfo() const {
        cout << "Account Owner: " << ownerName << ", Balance: $" << balance << endl;
    }
};

// CLASS 2: TransactionLogger
class TransactionLogger {
private:
    vector<string> logs;
public:
    void logTransaction(string description) {
        logs.push_back(description);
    }

    void printLogs() const {
        for (int i = 0; i < logs.size(); i++) { // Corrected "<=" to "<" to avoid index out of bounds error -EZ
            cout << logs[i] << endl;
        }
    }

    size_t totalTransactions() const { // Return type was missing -EZ
        return logs.size();
    }
};

int main() {
    BankAccount acc("Norman", 500.00);
    TransactionLogger logger;

    acc.deposit(150.0);
    logger.logTransaction("Deposited $150");

    acc.withdraw(700.0);
    logger.logTransaction("Withdrew $700");

    acc.printInfo();
    logger.printLogs();

    cout << "Total Transactions: " << logger.totalTransactions() << endl; // Used the totalTransactions() method to get log count, as 'logCount' was undefined -EZ

    return 0;
}