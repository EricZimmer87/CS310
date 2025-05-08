/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M9: Assignment
Professor:      Dr. Robert Flowers
Date:           05/08/2025
File Name:      Ch11Exercise13.cpp
Description:    This program defines a 'bankAccount' class with 'checkingAccount'
and 'savingsAccount' subclasses. It then demos these accounts in the main function.

Developed and tested in Visual Studio 2022 (Windows 11).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class bankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Constructor
    bankAccount(int accountNumber = 0, double balance = 0.0)
        : accountNumber(accountNumber), balance(balance) {
    }

    // Default destructor in case a class object is deleted
    virtual ~bankAccount() = default;

    // Getters
    int getAccountNumber() const {
        return accountNumber;
    }
    double getBalance() const {
        return balance;
    }

    // Setters
    void setAccountNumber(int x) {
        if (x > 0) {
            accountNumber = x;
        }
    }

    // Deposit method
    void deposit(double amount) {
        // Amount deposited must be greater than 0
        if (amount > 0) {
            balance += amount;
        }
    }

    // Withdraw method. Returns true if successful, else false.
    virtual bool withdraw(double amount) {
        // Amount withdrawn must be greater than 0
        if (amount > 0) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Print account information
    virtual void printAccountInformation() const {
        cout << "Account number: " << getAccountNumber() << "\n"
            << fixed << setprecision(2) << "Account balance: $" << getBalance() << "\n";
    }

};

class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minBalance;
    double serviceCharges;

    // Check if balance is below minimum
    bool isBalanceBelowMin() const {
        return getBalance() < getMinBalance();
    }

    // Apply service charge
    void applyServiceCharges() {
        bankAccount::withdraw(serviceCharges);
    }

public:
    // Constructor
    checkingAccount(int accountNumber = 0,
        double balance = 0.0,
        double interestRate = 0.0,
        double minBalance = 0.0,
        double serviceCharges = 0.0)
        : bankAccount(accountNumber, balance)
        , interestRate(interestRate)
        , minBalance(minBalance)
        , serviceCharges(serviceCharges) {
    }

    // Getters
    double getInterestRate() const {
        return interestRate;
    }
    double getMinBalance() const {
        return minBalance;
    }
    double getServiceCharges() const {
        return serviceCharges;
    }

    // Setters
    void setInterestRate(double rate) {
        // Interest rate must be 0-1 (inclusive)
        if (rate >= 0 && rate <= 1) {
            interestRate = rate;
        }
    }
    void setMinBalance(double amount) {
        if (amount >= 0) {
            minBalance = amount;
        }
    }
    void setServiceCharges(double amount) {
        if (amount >= 0) {
            serviceCharges = amount;
        }
    }

    // Withdraw method
    bool withdraw(double amount) override {
        if (!bankAccount::withdraw(amount)) {
            return false;
        }
        // Apply service charge if balance falls below the minimum
        if (isBalanceBelowMin()) {
            applyServiceCharges();
            cout << "Balance is below required minimum. Service charges of $" << getServiceCharges() << " applied." << endl;
        }
        // Withdraw successful
        return true;
    }

    // Post interest on balance
    void postInterest() {
        // Calculate the interest amount, then add it to the balance
        double interest = getBalance() * getInterestRate();
        deposit(interest);
    }

    // Write a check method
    void writeCheck(double amount) {
        // For the sake of this assignment, writing a check immediately withdraws the amount from the account.
        if (withdraw(amount)) {
            cout << "Check for $" << fixed << setprecision(2) << amount << " written." << endl;
        }
        else {
            cout << "Check for $" << amount << " bounced!" << endl;
        }
    }

    // Print account info
    void printAccountInformation() const override {
        // Print bankAccount's info
        bankAccount::printAccountInformation();
        // Print remaining info for checkingAccount
        cout << defaultfloat << "Interest rate: " << getInterestRate()
            << fixed << setprecision(2) << "\nMinimum balance: $" << getMinBalance()
            << fixed << setprecision(2) << "\nService charges: $" << getServiceCharges() << endl;
    }

};

class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    // Constructor
    savingsAccount(int accountNumber = 0, double balance = 0.0, double interestRate = 0.0)
        : bankAccount(accountNumber, balance), interestRate(interestRate) {
    }

    // Getters
    double getInterestRate() const {
        return interestRate;
    }

    // Setters
    void setInterestRate(double rate) {
        // The interest rate must be 0-1 (inclusive)
        if (rate >= 0 && rate <= 1) {
            interestRate = rate;
        }
    }

    // Post interest rate to balance
    void postInterest() {
        // Calculate the interest then add it to the balance
        double interest = getBalance() * getInterestRate();
        deposit(interest);
    }

    // Withdraw method
    bool withdraw(double amount) override {
        // Savings account balance cannot go below 0
        if (amount <= getBalance()) {
            return bankAccount::withdraw(amount);
        }
        return false;
    }

    // Print account information
    void printAccountInformation() const override {
        // Print bankAccount's info
        bankAccount::printAccountInformation();
        // Print savingsAccount info
        cout << defaultfloat << "Interest rate: " << getInterestRate() << endl;
    }

};

int main() {
    // Create a checking account
    checkingAccount checking = checkingAccount(10000, 100, .005, 10, 25);

    // Print checking account info
    cout << "Checking account created:" << endl;
    checking.printAccountInformation();

    // Deposit into checking account
    cout << "\nDepositing $100 into checking account..." << endl;
    checking.deposit(100);

    // Write a check
    cout << "\nWriting a check for $250 from checking account..." << endl;
    checking.writeCheck(250);

    // Withdraw from checking account
    cout << "\nWithdrawing $210 from checking account..." << endl;
    if (checking.withdraw(210)) {
        cout << "Withdrawal successful." << endl;
    }
    else {
        cout << "Withdrawal failed: Insufficient funds." << endl;
    }

    // Post interest to checking account
    cout << "\nPosting interest..." << endl;
    checking.postInterest();

    // Print updated checking account info
    cout << "\nUpdated checking account info:" << endl;
    checking.printAccountInformation();

    cout << "\n---" << endl; // Breakup reading

    // Create a savings account
    savingsAccount savings(20000, 50, 0.02);
    cout << "\nSavings account created:" << endl;

    // Print savings account info
    savings.printAccountInformation();

    // Withdraw $75 from savings account
    cout << "\nWithdrawing $75 from savings..." << endl;
    if (savings.withdraw(75)) {
        cout << "Withdrawal successful" << endl;
    }
    else {
        cout << "Withdrawal failed: Insufficient funds." << endl;
    }

    // Deposit $25 into savings account
    cout << "\nDepositing $25 into savings account..." << endl;
    savings.deposit(25);

    // Post interest to savings account
    cout << "\nPosting interesting to savings account..." << endl;
    savings.postInterest();

    // Print updated savings account information
    cout << "\nUpdated savings account information:" << endl;
    savings.printAccountInformation();

    return 0;
}
