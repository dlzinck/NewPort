#include <iostream>
#include <iomanip>
#include <cmath>
#include "BankApp.h"

using namespace std;

/**
 * Constructs a BankApp object with the specified investment parameters.
 *
 * @param t_initialInvestment   The initial investment amount.
 * @param t_monthlyDeposit      The monthly deposit amount.
 * @param t_interestRate        The annual interest rate (percentage).
 * @param t_numberOfYears       The number of years for the investment.
 */
BankApp::BankApp(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears)
    : m_initialInvestment(t_initialInvestment),
      m_monthlyDeposit(t_monthlyDeposit),
      m_interestRate(t_interestRate),
      m_numberOfYears(t_numberOfYears) {}

/**
 * Generates and displays the investment report without monthly deposits.
 * Interest is compounded monthly based solely on the initial balance.
 */
void BankApp::printReportWithoutMonthlyDeposit() {
    double balance = m_initialInvestment;
    double monthlyRate = m_interestRate / 100.0 / 12.0;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double interestEarned = 0.0;

        for (int month = 0; month < 12; ++month) {
            double monthlyInterest = balance * monthlyRate;
            interestEarned += monthlyInterest;
            balance += monthlyInterest;
        }

        double roundedBalance = round(balance * 100.0) / 100.0;
        double roundedInterest = round(interestEarned * 100.0) / 100.0;

        printDetails(year, roundedBalance, roundedInterest);
    }
}

/**
 * Generates and displays the investment report with monthly deposits.
 * Interest is compounded monthly based on the balance before the deposit
 * is added.
 */
void BankApp::printReportWithMonthlyDeposit() {
    double balance = m_initialInvestment;
    double monthlyRate = m_interestRate / 100.0 / 12.0;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double interestEarned = 0.0;

        for (int month = 0; month < 12; ++month) {
            double monthlyInterest = balance * monthlyRate;
            interestEarned += monthlyInterest;
            balance += monthlyInterest;
            balance += m_monthlyDeposit;
        }

        double roundedBalance = round(balance * 100.0) / 100.0;
        double roundedInterest = round(interestEarned * 100.0) / 100.0;

        printDetails(year, roundedBalance, roundedInterest);
    }
}

/**
 * Displays formatted year-end balance and interest earned.
 *
 * @param t_year             The current year.
 * @param t_yearEndBalance   The year-end balance.
 * @param t_interestEarned   The total interest earned during the year.
 */
void BankApp::printDetails(int t_year, double t_yearEndBalance, double t_interestEarned) {
    cout << fixed << setprecision(2);
    cout << t_year << "\t\t" << t_yearEndBalance << "\t\t" << t_interestEarned << endl;
}
