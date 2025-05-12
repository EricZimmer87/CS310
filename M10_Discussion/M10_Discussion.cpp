/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M10: Discussion
Professor:      Dr. Robert Flowers
Date:           05/12/2025
File Name:      M10_Discussion.cpp
Description:    This program creates a Linked Lists struct, builds 5 nodes, assigns the
data values to 1-5, then prints the contents of each node's data.
It has three intentional errors related to pointers. Find them.

Developed and tested (before errors) in Visual Studio 2022 (Windows).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>

using namespace std;

// Node struct for a Linked List
struct Node {
    int data;
    Node* next;
};

int main() {
    const int LINKED_LIST_SIZE = 5;

    // Initialize a linked list
    Node* head; // Store head of the linked list
    Node* current = nullptr;

    // Use a loop to create 5 nodes and assign their data
    // values (1 through 5)
    for (int i = 1; i <= LINKED_LIST_SIZE; i++) {
        // Assign a pointer to a new Node location in memory
        Node* newNode = nullptr;
        (*newNode).data = i;
        (*newNode).next = nullptr;

        // If this is the first iteration, head is nullptr
        if (head == nullptr) {
            // Head becomes the first new node
            head = newNode;
            // Set current to point to the same node as head
            // (used to add more nodes)
            current = head;
        }
        else {
            // Link the previous node's next to this new node
            (*current).next = newNode;
            // Update the current to this new node for next iteration
            current = newNode;
        }
    }

    // Print each node's data contents of the linked list
    cout << "Linked List contents:" << endl;
    // Track the current node to print
    Node curr = head;
    // When we hit a nullptr, that's the end of the linked list
    while (curr != nullptr) {
        // Print the data value
        cout << (*curr).data << " ";
        // Move curr to the next node
        curr = (*curr).next;
    }
    cout << endl;

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = (*head).next;
        delete temp;
    }


    return 0;
}