// ========================
// main.cpp
// Entry point for the Airgead Banking App.
// Handles user interaction and displays investment reports.
// ========================

#include <iostream>
#include <limits>
#include "BankApp.h"

using namespace std;

/**
 * @brief Collects validated user input for a positive double value.
 *
 * @param prompt The message displayed to the user.
 * @return A validated positive double.
 */
double getValidatedDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number.\n";
        } else {
            break;
        }
    }
    return value;
}

/**
 * @brief Collects validated user input for a positive integer value.
 *
 * @param prompt The message displayed to the user.
 * @return A validated positive integer.
 */
int getValidatedIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer.\n";
        } else {
            break;
        }
    }
    return value;
}

/**
 * @brief Main function that runs the Airgead Banking App.
 */
int main() {
    // Collect investment inputs from user
    double initialInvestment = getValidatedDoubleInput("Enter Initial Investment Amount: ");
    double monthlyDeposit    = getValidatedDoubleInput("Enter Monthly Deposit: ");
    double interestRate      = getValidatedDoubleInput("Enter Annual Interest Rate (in %): ");
    int numberOfYears        = getValidatedIntInput("Enter Number of Years: ");

    // Create BankApp object with user input
    BankApp app(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

    // Display report without monthly deposits
    cout << "\n\n  Balance and Interest Without Additional Monthly Deposits\n";
    cout << "============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    app.printReportWithoutMonthlyDeposit();

    // Display report with monthly deposits
    cout << "\n\n  Balance and Interest With Additional Monthly Deposits\n";
    cout << "========================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    app.printReportWithMonthlyDeposit();

    return 0;
}