/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M12: Assignment
Professor:      Dr. Robert Flowers
Date:           05/27/2025
File Name:      Ch14Exercise01.cpp
Description:    This program gets feet and inches from the user, then converts
the length to centimeters and prints the results. It demonstrates the use
of custom exception classes to handle negative and invalid number inputs.

Developed and tested in Visual Studio 2022 (Windows 11).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35207.1.
*/

#include <iostream>
#include <exception>
#include <iomanip>

// Custom exception class for negative number
// Inherits from std::exception to follow standard C++ exception handling
class negativeNumber : public std::exception {
public:
    /*
    This overrides the what() method from std::exception. It returns a pointer to the beginning of a null-terminating
    string of the message. The return type is const because the message should not be modified. noexcept is used to ensure
    it doesn't throw. At this point, all we need to do is return a message because the exception has already been thrown.
    */
    const char* what() const noexcept override {
        return "Negative number. Please enter a number greater than or equal to 0.\n";
    }
};

// Custom exception class for invalid number
class nonNumber : public std::exception {
public:
    const char* what() const noexcept override {
        return "Not a valid number. Please enter a valid number.\n";
    }
};

static double getInput(const std::string& msg) {
    /*
    This function gets input from the user as a double, validates the input, and returns it.
    */
    double input = 0.0;
    // Keep asking for input until valid
    while (true) {
        try {
            // Print the message passed in
            std::cout << msg;

            // If it's not a valid number, throw nonNumber() exception
            if (!(std::cin >> input)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw nonNumber();
            }
            // If the number is negative, throw negativeNumber() exception
            if (input < 0) {
                throw negativeNumber();
            }
            // Valid input
            return input;
        }
        catch (const nonNumber& e) {
            std::cerr << "Error occurred: " << e.what() << std::endl;
        }
        catch (const negativeNumber& e) {
            std::cerr << "Error occurred: " << e.what() << std::endl;
        }
    }
}

int main() {
    // Print welcome message
    std::cout << "Welcome!\nThis program converts feet and inches to centimeters.\nPlease enter feet first and then inches." << std::endl;

    // Get feet from user
    double feet = getInput("\nPlease enter feet: ");
    // Get inches from user
    double inches = getInput("Please enter inches: ");

    // Convert feet and inches to centimeters
    double centimeters = (inches + (feet * 12)) * 2.54;

    // Print results, rounded to 2 decimal places
    std::cout << "\n" << feet << " feet and " << inches << " inches is "
        << std::fixed << std::setprecision(2) << centimeters << " centimeters." << std::endl;

    return 0;
}