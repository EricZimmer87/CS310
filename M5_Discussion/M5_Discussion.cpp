/*
Student's Name: Eric Zimmer
Date: 04/07/2025
File Name: M5_Discussion.cpp
Description: This program initializes a list of numbers in a random order and prints them.
It then uses the mergeSort function, which uses the merge helper function, to sort the list.
After sorting the list of numbers, it prints the list again.
It has errors. Find them.
*/

#include <iostream>
#include <vector>

using namespace std;


int main() {
    // List of numbers to sort
    vector<double> numList = {5, 3, 7, 1, 9, 4, 2, 8, 10, 6};

    // Print list of numbers before sorting
    cout << "List of numbers before sorting: ";
    for (double num : numList) {
        cout << num << " ";
    }
    cout << endl;
    
    // Sort the list using Merge Sort
    numList = mergeSort numList;
    cout << "The list has been sorted." << endl;
    
    // Print the list of numbers after sorting
    cout << "List of numbers after sorting: ";
    for (double num : numList) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

vector<double> mergeSort(numList) {
    /*
    This function uses the Merge Sort algorithm to sort a list of numbers.
    */
    // Base case: list is less than or equal to 1 in length
    if (numList.size() <= 1) {
        return numList;
    }

    // Find middle index
    size_t midIndex = numList.size() / 2;

    // Get left and right halves of the list
    vector<double> leftList;
    for (size_t i = 0; i < midIndex; i++) {
        leftList.push_back(numList[i]);
    }
    vector<double> rightList;
    for (size_t i = midIndex; i < numList.size(); i++) {
        rightList.push_back(numList[i]);
    }

    // Recursively assign left and right halves of the list
    leftList = mergeSort(leftList);
    rightList = mergeSort(rightList);

    // Merge the left and right lists
    return merge(leftList, rightList);

}

void merge(const vector<double>& list1, const vector<double>& list2) {
    /*
    This is a helper function that merges two sorted lists of numbers into one sorted list
    and returns the sorted list.
    */
   // Declare variables
    size_t i1 = 0;
    size_t i2 = 0;
    size_t list1Size = list1.size();
    size_t list2Size = list2.size();
    vector<double> result;

    // Merge the two lists until one is empty
    while (i1 < list1Size && i2 < list2Size) {
        if (list1[i1] < list2[i2]) {
            result.push_back(list1[i1]);
            i1++;
        } else {
            result.push_back(list2[i2]);
            i2++;
        }
    }

    // Add the remaining values, if any, from list1
    while (i1 < list1Size) {
        result.push_back(list1[i1]);
        i1++;
    }

    // Add the remaining values, if any, from list2
    while (i2 < list2Size) {
        result.push_back(list2[i2]);
        i2++;
    }

    return result;
}