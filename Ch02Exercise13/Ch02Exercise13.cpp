/*
CS310-T301 Programming with C++
Professor Robert Flowers
M1: Assignment 1.2
Eric Zimmer
March 7, 2025
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Get original price of the item sold.
    double originalItemPrice;
    cout << "Original price of the item sold: ";
    cin >> originalItemPrice;

    // Get percentage of the marked-up price
    double percentageMarkUp;
    cout << "Percentage of the marked-up price: ";
    cin >> percentageMarkUp;

    // Get the sales tax rate
    double salesTaxRate;
    cout << "Sales tax rate: ";
    cin >> salesTaxRate;

    // Calculate the store's selling price of the item
    double sellingPrice = originalItemPrice * (1 + (percentageMarkUp / 100));

    // Calculate sales tax
    double salesTax = sellingPrice * (salesTaxRate / 100);

    // Calculate final price of the item
    double finalPrice = sellingPrice + salesTax;

    // Output
    cout << fixed << setprecision(2);
    cout << "\nOriginal price of the item: $" << originalItemPrice << endl;
    cout << "Percentage of mark-up: " << percentageMarkUp << "%" << endl;
    cout << "Store's selling price of the item: $" << sellingPrice << endl;
    cout << "Sales tax rate: " << salesTaxRate << "%" << endl;
    cout << "Sales tax: $" << salesTax << endl;
    cout << "Final price of the item: $" << finalPrice << endl;

    return 0;
}
