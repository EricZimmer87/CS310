/*
Student's Name: Eric Zimmer
Date: 3/27/2025
File Name: Ch04Exercise16.cpp
Description: This program gets the net price and estimated number of copies of a novel
that will be sold. It then prints the three options for payment. It then determines
the best option and prints a message displaying which option is the best.
*/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    // Get net price
    double netPrice;
    cout << "What is the net price of each copy of the novel: " << endl;
    // Keep asking for input until input is valid
    while (!(cin >> netPrice) || netPrice < 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid number greater than or equal to 0:" << endl;
    }

    // Get estimated number of copies that will be sold
    int estimatedCopiesSold;
    cout << "What is the estimated number of copies that will be sold: " << endl;
    while (!(cin >> estimatedCopiesSold) || estimatedCopiesSold < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number greater than or equal to 0:" << endl;
    }

    // Set output format
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    /*
     In the first option, the author is paid $5,000 upon delivery of the final manuscript
     and $20,000 when the novel is published.
    */
   // Calculations for option 1
    const double MANUSCRIPT_PAYMENT = 5000;
    const double PUBLICATION_PAYMENT = 20000;
    const double OPTION1_PAYMENT = MANUSCRIPT_PAYMENT + PUBLICATION_PAYMENT;
    // Print option 1
    cout << "\nThe first option does not mention royalties, "
     << "so the total payment would be a flat rate of $" << OPTION1_PAYMENT << "." << endl;

    /*
    In the second option, the author is paid 12.5% of the net price of the novel for each
    copy of the novel sold. 
    */
   // Calculations for option 2
   const double ROYALTY_RATE2 = 0.125;
   double option2Payment = (ROYALTY_RATE2 * netPrice) * estimatedCopiesSold;
    // Print option 2
    cout << "\nThe total royalties for the second option will be $" << option2Payment << "." << endl;

    /*
    In the third option, the author is paid 10% of the net price for the first 4,000 copies
    sold, and 14% of the net price for the copies sold over 4,000. 
    */
   // Calculations for option 3
   const double START_ROYALTY_RATE3 = 0.10;
   const double END_ROYALTY_RATE3 = 0.14;
   const int BONUS_THRESHOLD = 4000;
   double option3Payment = 0;
   if (estimatedCopiesSold > BONUS_THRESHOLD) {
    option3Payment += (START_ROYALTY_RATE3 * netPrice) * BONUS_THRESHOLD;
    option3Payment += (END_ROYALTY_RATE3 * netPrice) * (estimatedCopiesSold - BONUS_THRESHOLD);
   } else {
    option3Payment += (START_ROYALTY_RATE3 * netPrice) * estimatedCopiesSold;
   }
   // Print option 3
   cout << "\nThe total royalties for the third option will be $" << option3Payment << "." << endl;

   // Determine the best option
   int bestOption;
   if (OPTION1_PAYMENT >= option2Payment && OPTION1_PAYMENT >= option3Payment ) {
    bestOption = 1;
   } else if (option2Payment >= OPTION1_PAYMENT && option2Payment >= option3Payment) {
    bestOption = 2;
   } else {
    bestOption = 3;
   }

   // Print the best option
   switch(bestOption) {
    case 1:
        cout << "\nOption 1 is the best option: $" << OPTION1_PAYMENT << "." << endl;
        break;
    case 2:
        cout << "\nOption 2 is the best option: $" << option2Payment << "." << endl;
        break;
    case 3:
        cout << "\nOption 3 is the best option: $" << option3Payment << "." << endl;
        break;
    default:
        cout << "\nCould not determine the best option." << endl;
        break;
   }

    return 0;
}