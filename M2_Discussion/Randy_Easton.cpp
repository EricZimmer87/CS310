//
// Created by Randy Easton on 3/11/2025.
//

/*
Create a simple C++ program using input/output processes and at least two errors.
The program should not execute and there should be at least two errors in the code.
 */

 // Errors corrected by Eric Zimmer 03/19/2025


 #include <iostream>
 #include <iomanip>
 #include <ios>
 #include <locale> // Added this -Eric Zimmer
 
 using namespace std; // Had 'stad' instead of 'std' -Eric Zimmer
 int main(){
    string name;
    int age;
 
    // Prompting user for input
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;
 
    // Intentional Errors
    cout << "Hello, " << name << "! You are " << age << " years old." << endl; // Missed semicolon -Eric Zimmer
    cout << fixed << setprecision(2); // Had a period instead of "<<", didn't have "<< fixed", "precision" instead of "setprecision" -Eric Zimmer
    cout.imbue(locale("en_US.UTF-8"));
    cout << "America Owes you the worker at least: " << showbase << put_money("123456789") << '\n';
 
 }