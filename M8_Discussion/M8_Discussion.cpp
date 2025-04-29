/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M8: Discussion
Professor:      Dr. Robert Flowers
Date:           04/29/2025
File Name:      M8_Discussion.cpp
Description:    This program defines two classes, 'Friend' and 'Foe', then instatiates
Mario and Goomba. The Mario object interacts with the Goomba object via the 'Friend' method 'stomp()'.
It has four errors. Find them.

Developed and tested (before errors) in Visual Studio 2022 (Windows).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>
#include <string>

using namespace std;

class Foe {
private:
    // Attributes
    string name;

public:
    // Constructor
    Foe(const string& name) {
        this->name = name;
    }

    // Getter
    string getName() const {
        return name;
    }
};

class Friend {
private:
    // Attributes
    string name;

public:
    // Constructor
    Friend(const string& name) {
        this->name = name;
    }

    // Getter
    string getName() const {
        return name;
    }

    // Stomp method
    void stomp(const Foe& foe) const {
        cout << name << " stomps " << foe.name << "!" << endl;
    }
};

int main() {
    // Create a friend and foe object (Mario and Goomba)
    Friend("Mario") mario;
    Foe("Goomba") goomba;

    // Call the stomp method (Mario stomps Goomba!)
    stomp(goomba);

    return 0;
}