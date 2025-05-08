/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M9: Discussion
Professor:      Dr. Robert Flowers
Date:           05/08/2025
File Name:      Jay_Fisher_M9_Discussion.cpp
Description:    This program was originally developed by Jay Fisher with intentional errors
that I corrected.

Developed and tested in Visual Studio 2022 (Windows).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

/*
*Student Name: Jay Fisher
*File Name: M8_Discussion.cpp
*Data: 05/08/2025
*Visual C++ 2022   00476 - 80000 - 00000 - AA685
*Microsoft Visual C++ 2022
*/

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//  -----------------------------------------------------------------------------------------
//  This program uses inheritance to create a base class called instrument 
//  and two derived classes: guitar and Piano.  There are three intentional errors in the program.
//  Can you find them?
//  -----------------------------------------------------------------------------------------

//  Base class for all musical instruments
class instrument {

    //  Protected used to allow derived classes to access these members
private:
    string brand;
    string model;
    float price;
    int year;

    //  Public used to allow access to these members from outside the class
public: // Changed this to public -EZ
    //  Constructor for the base class
    instrument(string b, string m, float p, int year) :
        brand(b), model(m), price(p), year(year) {
    }

    //  This is a virtual function that can me mimicked by derived classes
    virtual void showDetails() const { // Made this method virtual & const -EZ
        cout << brand << " " << model << " (" << year << ")" << endl;
        cout << "  Value: $" << price << endl;

    }

    // Getters added by Eric Zimmer:
    string getBrand() const {
        return brand;
    }
    string getModel() const {
        return model;
    }
    float getPrice() const {
        return price;
    }
    int getYear() const {
        return year;
    }
};

//  Derived class for guitars
class guitar : public instrument {
private:
    string type_strings;
    int num_strings;

public:
    guitar(string b, string m, float p, int year, string strings, int count)
        : instrument(b, m, p, year) {
        type_strings = strings;
        num_strings = count;

    }

    //  Play function for the guitar
    void play() {
        // Used getBrand() method instead of 'brand' -EZ
        cout << "  Playing " << num_strings << "-string " << getBrand() << " guitar" << endl;
        cout << "  Sounds good connected to the amp" << endl;
    }

    //  Tune function for the guitar
    void tune() {
        cout << "  Tuned to EADGBE" << endl;

    }
};

//  Derived class for pianos
class Piano : public instrument {
private:
    int num_keys;


public:
    Piano(string b, string m, float p, int year, int keys)
        : instrument(b, m, p, year) {
        num_keys = keys;

    }

    //  Play function for the piano
    void play() { // Return type was missing -EZ
        // Used getBrand() method instead of 'brand' -EZ
        cout << "  Playing " << num_keys << "-key " << getBrand() << " piano" << endl;
        cout << "  Sounds good and using reverb" << endl;
    }

    //  Tune function for the piano
    void tune() {
        cout << "  Electric piano, digitally tuned " << endl;
    }
};

//  Main program
int main() {

    //  Create instances of guitar and piano
    guitar myguitar("  PRS", "Custom 24", 1000.00, 2023, "Steel", 6);
    Piano myPiano("  Roland", "FP-30X", 750.00, 2024, 88);

    //  Display the details of the instruments
    cout << "  \n\n  Inventory of my instruments" << endl;
    cout << "  ---------------------------" << endl;
    cout << "\n  My Guitar" << endl;
    cout << "  ---------------------------" << endl;
    myguitar.showDetails();
    myguitar.play();
    myguitar.tune();

    cout << "\n  My Piano" << endl;
    cout << "  ---------------------------" << endl;
    myPiano.showDetails();
    myPiano.play();
    myPiano.tune();

    //  End of program
    cout << "\n  Press any key to continue..." << endl;
    (void)_getch();
    return 0;
}