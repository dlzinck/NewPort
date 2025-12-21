// main.cpp
// Author: Drew Lane Zinck II
// Date: 07/18/2025
// Description: Driver program for CS210 Project One. Simulates a dual-clock system and
//              provides a user menu for adding time.

#include <iostream>
#include "Clock.h"
using namespace std;

// Function: displayClocks
// Purpose: Prints both 12-hour and 24-hour clocks side-by-side in formatted boxes
void displayClocks(Clock clock) {
    cout << "**************************     **************************\n";
    cout << "*     12-Hour Clock      *     *     24-Hour Clock      *\n";
    cout << "*     ";
    clock.display12HourClock();
    cout << "        *     *     ";
    clock.display24HourClock();
    cout << "           *\n";
    cout << "**************************     **************************\n";
}

// Function: displayMenu
// Purpose: Show the list of user options for modifying the time
void displayMenu() {
    cout << "\nMENU:\n";
    cout << "1 - Add One Hour\n";
    cout << "2 - Add One Minute\n";
    cout << "3 - Add One Second\n";
    cout << "4 - Exit Program\n";
    cout << "Please enter your choice: ";
}

int main() {
    Clock clock;   // Create a Clock object to track time
    int choice;    // Variable to hold the users input

    // Main loop: runs until user chooses to exit (option 4)
    do {
        displayClocks(clock); // Show current time
        displayMenu();        // Show action menu
        cin >> choice;        // Get user input

        switch (choice) {
            case 1:
                clock.addHour();
                break;
            case 2:
                clock.addMinute();
                break;
            case 3:
                clock.addSecond();
                break;
            case 4:
                cout << "\nExiting program. Thank you!\n";
                break;
            default:
                cout << "\nInvalid input. Please enter a number from 1 to 4.\n";
        }

        cout << "\n"; // Blank line for readability

    } while (choice != 4);

    return 0;
}
