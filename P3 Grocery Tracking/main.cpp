// Author: Drew Lane Zinck II
// Date: 2025-08-15
// Course: CS210 - Corner Grocer Project
// File: main.cpp
// Description: Entry point for the Corner Grocer program. Loads grocery item data,
//              writes a backup file, and provides an interactive menu to search
//              and display purchase frequencies.

/**
 * @file main.cpp
 * @brief Corner Grocer application entry point. Builds an item frequency table,
 *        writes a backup file, and provides a simple interactive menu.
 *
 * This is where the program starts running. It:
 *  1. Loads the input file into an ItemTracker object.
 *  2. Saves a backup copy into frequency.dat.
 *  3. Shows a menu for the user to:
 *     - Search how many times an item was bought.
 *     - Print all items with counts.
 *     - Print a histogram of item frequencies.
 *     - Exit the program.
 */

#include <iostream>
#include <limits>
#include <string>
#include "ItemTracker.h"

/// @brief Prints the main menu to the console.
static void PrintMenu() {
    std::cout << "\n===== Corner Grocer =====\n"
              << "1. Search item frequency\n"
              << "2. Print all item frequencies\n"
              << "3. Print histogram\n"
              << "4. Exit\n"
              << "Select an option (1-4): ";
}

int main() {
    const std::string kInputFile  = "CS210_Project_Three_Input_File.txt";
    const std::string kBackupFile = "frequency.dat";

    ItemTracker tracker;

    // Step 1: Load input file into tracker
    if (!tracker.LoadFromFile(kInputFile)) {
        std::cerr << "Fatal: cannot continue without input data." << std::endl;
        return 1;
    }

    // Step 2: Save backup file
    if (!tracker.WriteBackup(kBackupFile)) {
        std::cerr << "Warning: backup file not written." << std::endl;
    }

    // Step 3: Menu loop
    while (true) {
        PrintMenu();

        int choice;
        if (!(std::cin >> choice)) {
            // Handle non-numeric input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1-4.\n";
            continue;
        }

        if (choice == 1) {
            std::cout << "Enter item to search: ";
            std::string item;
            std::cin >> item;
            std::cout << tracker.CountOf(item) << '\n'; // Numeric frequency only
        }
        else if (choice == 2) {
            tracker.PrintAll();
        }
        else if (choice == 3) {
            tracker.PrintHistogram();
        }
        else if (choice == 4) {
            std::cout << "Exiting program.\n";
            break;
        }
        else {
            std::cout << "Please choose 1-4.\n";
        }
    }

    return 0;
}
