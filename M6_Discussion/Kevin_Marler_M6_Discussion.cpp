/*
Student's Name: Eric Zimmer
Originally by:  Kevin Marler
Course:         CS310-T301 Programming with C++
Assignment:     M6: Discussion
Professor:      Dr. Robert Flowers
Date:           04/16/2025
File Name:      M6_Discussion.cpp
Description:    This program creates an enum and prints a message based on its value.
This program was originally created by Kevin Marler with errors fixed by Eric Zimmer.

Tested on macOS using both:
    g++ -o M6_Discussion M6_Discussion.cpp
    clang++ -o M6_Discussion M6_Discussion.cpp
*/


#include <iostream>
#include <string> // Changed "stringz" to "string" however, this is not needed so could be removed -EZ
using namespace std;

// For what ever reason I keep thinking about ice cream and want to eat a bunch of it.
enum iceCream_flavor { Vanilla, Mint, Chocolate, Strawberry, RockyRoad };

int main()
{
	iceCream_flavor favFlavor = RockyRoad; // Initialized variable to a value upon declaration. -EZ

    if (favFlavor == RockyRoad)
    {  
        // I moved the below comment inside the curly brackets and split it on two lines for easier reading. -EZ
        // do not argue with me on this point my code my preference rocky road is where it is at how ever
        // I will allow for vanilla becuase rootbeer floats....
        cout << "Rocky Road is the best!" << endl; // Changed '>>' to '<<' -EZ
    }
    else
    {
        cout << "Not Rocky Road" << endl;
    }

    // this makes me feel fat because yea I am now just thinking about different types of ice cream .
    return 0;
}