/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M7: Assignment
Professor:      Dr. Robert Flowers
Date:           04/25/2025
File Name:      Ch08Exercise07.cpp
Description:    This program gets candidates' last names and votes received. It calculates the percent of total
votes for each candidate, determines the winner, and prints the results.

Developed and tested in Visual Studio 2022 (Windows 11).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

inline string trim(const string& s);
void getCandidatesInfo(string candidatesNames[], int candidatesVotes[]);
void calculatePercentageVotes(const int candidatesVotes[], double candidatesVotesPercent[], const int votesSum);
int getVotesSum(const int candidatesVotes[]);
vector<int> determineWinners(const int candidatesVotes[]);
void printResults(const string candidatesNames[], const int candidatesVotes[], const double candidatesVotesPercent[], const vector<int>& winners, const int votesSum);

constexpr int N_CANDIDATES = 5; // Global constant for number of candidates
constexpr int MAX_NAME_LENGTH = 20; // Global constant for max length of last name

int main() {
    // Get candidates' names & votes
    string candidatesNames[N_CANDIDATES] = {}; // Store names in an array
    int candidatesVotes[N_CANDIDATES] = {}; // Store votes in an array
    getCandidatesInfo(candidatesNames, candidatesVotes);

    // Get sum of all votes
    int votesSum = getVotesSum(candidatesVotes);

    // Calculate percentage of the total votes received by each candidate
    double candidatesVotesPercent[N_CANDIDATES] = {}; // Store votes percent in an array
    calculatePercentageVotes(candidatesVotes, candidatesVotesPercent, votesSum);

    // Determine winner(s)
    vector<int> winners = determineWinners(candidatesVotes);

    // Print results
    printResults(candidatesNames, candidatesVotes, candidatesVotesPercent, winners, votesSum);

    return 0;
}

inline string trim(const string& s) {
    /*
    This is a helper function that trims leading and trailing whitespace from a string.
    */
    // Whitespace includes: space, tab, carriage return, line feed, form feed, or vertical tab.
    const char* whitespace = " \t\n\r\f\v";
    size_t begin = s.find_first_not_of(whitespace);
    if (begin == string::npos) {
        return string{};
    }
    size_t end = s.find_last_not_of(whitespace);
    return string{ s.substr(begin, end - begin + 1) };
}

void getCandidatesInfo(string candidatesNames[], int candidatesVotes[]) {
    /*
    This function gets the candidates' names and votes. The parameters are the arrays to store the inputs.
    Parallel arrays are used to keep track of names and corresponding votes.
    */
    cout << "Please enter candidates' last names and votes for " << N_CANDIDATES << " candidates." << endl;
    cout << "You will be prompted to enter the name first and then the amount of votes for each candidate.\n" << endl;

    string candidateName = "";
    for (int i = 0; i < N_CANDIDATES; i++) {
        // Get names
        while (true) {
            // Print message
            cout << "Enter candidate " << i + 1 << "'s last name: ";

            // Get input
            getline(cin, candidateName);

            // Trim leading and trailing whitespace
            candidateName = trim(candidateName);

            // Check for empty input
            if (candidateName.empty()) {
                cout << "Invalid input: Empty string." << endl;
                continue;
            }

            // Name cannot be greater than set length
            if (candidateName.size() > MAX_NAME_LENGTH) {
                cout << "Invalid input: Name is too long. Please limit the name's length to " << MAX_NAME_LENGTH << " characters." << endl;
                continue;
            }

            // Valid input
            break;
        }
        // Store name
        candidatesNames[i] = candidateName;

        // Get votes
        int candidateVote = 0;
        cout << "Enter " << candidatesNames[i] << "'s votes: ";
        // Keep asking for input until input is valid
        while (!(cin >> candidateVote) || candidateVote < 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a whole number greater than or equal to 0." << endl;
        }
        // Clear cin contents so getline() works properly to get the next name
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Print a blank line to make it easier to distinguish different candidates
        cout << endl;

        // Store vote
        candidatesVotes[i] = candidateVote;
    }
}

int getVotesSum(const int candidatesVotes[]) {
    /*
    This is a helper function to calculate the total sum of all the votes.
    */
    int votesSum = 0;
    for (int i = 0; i < N_CANDIDATES; i++) {
        votesSum += candidatesVotes[i];
    }
    return votesSum;
}

void calculatePercentageVotes(const int candidatesVotes[], double candidatesVotesPercent[], const int votesSum) {
    /*
    This function calculates the percentage of total votes for each candidate.
    */
    // Handle the edge case if there are 0 total votes to avoid a division by 0 error
    if (votesSum == 0) {
        for (int i = 0; i < N_CANDIDATES; i++) {
            // If there are no votes, assign all vote percents to 0
            candidatesVotesPercent[i] = 0.0;
        }
        return;
    }

    // Calculate percentage for each vote
    for (int i = 0; i < N_CANDIDATES; i++) {
        candidatesVotesPercent[i] = (static_cast<double>(candidatesVotes[i]) / votesSum) * 100;
    }
}

vector<int> determineWinners(const int candidatesVotes[]) {
    /*
    This function determines and returns the index value(s) for the winner(s). It finds the max value in
    candidatesVotes and then checks which candidates have that amount of votes, and then adds each candidate's
    index to the return vector.
    */
    int maxVotes = candidatesVotes[0];
    vector<int> winnerIndices;

    // Find max votes
    for (int i = 0; i < N_CANDIDATES; i++) {
        if (candidatesVotes[i] > maxVotes) {
            maxVotes = candidatesVotes[i];
        }
    }

    // Determine which candidates have the max votes
    for (int i = 0; i < N_CANDIDATES; i++) {
        if (candidatesVotes[i] == maxVotes) {
            winnerIndices.push_back(i);
        }
    }
    return winnerIndices;
}

void printResults(const string candidatesNames[], const int candidatesVotes[], const double candidatesVotesPercent[], const vector<int>& winners, const int votesSum) {
    /*
    This function prints the results in a table with columns for the candidates, votes, and % of votes.
    It sets a column width to keep each column aligned for proper formatting.
    (Matches the picture in assignment's instructions.)
    */
    // Set column widths
    const int COL_W = MAX_NAME_LENGTH;

    // Print header
    cout << left << setw(COL_W) << "Candidate"
        << setw(COL_W) << "Votes Received"
        << setw(COL_W) << "% of Total Votes" << endl;

    // Print Candidate | Votes Received | % of Total Votes for each candidate
    for (int i = 0; i < N_CANDIDATES; i++) {
        cout << left << setw(COL_W) << candidatesNames[i]
            << setw(COL_W) << candidatesVotes[i]
                << setw(COL_W) << fixed << setprecision(2) << candidatesVotesPercent[i] << endl;
    }

    // Print total votes
    cout << left << setw(COL_W) << "Total"
        << setw(COL_W) << votesSum << endl;

    // Print winner(s)
    if (votesSum == 0) {
        cout << "\nNobody voted, so there is no winner." << endl;
    }
    // Check for a tie
    else if (winners.size() > 1) {
        cout << "\nTie! The winners are:" << endl;
        // Print all the winners
        for (int winner : winners) {
            cout << candidatesNames[winner] << endl;
        }
    }
    // Only one winner - no tie
    else {
        cout << "\nThe Winner of the Election is " << candidatesNames[winners[0]] << "." << endl;
    }
}
