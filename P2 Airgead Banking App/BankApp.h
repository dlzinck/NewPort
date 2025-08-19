// ========================
// BankApp.h
// Class definition for the Airgead Banking investment calculator.
// ========================

#ifndef AIRGEAD_BANKAPP_H_
#define AIRGEAD_BANKAPP_H_

/**
 * @class BankApp
 * @brief Provides functionality to calculate and display compound interest reports
 *        with and without monthly deposits over a specified number of years.
 */
class BankApp {
public:
    /**
     * @brief Constructs a BankApp object with user-provided investment parameters.
     * 
     * @param t_initialInvestment   The initial investment amount.
     * @param t_monthlyDeposit      The fixed monthly deposit amount.
     * @param t_interestRate        The annual interest rate as a percentage.
     * @param t_numberOfYears       The total number of years for the investment.
     */
    BankApp(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);

    /**
     * @brief Displays a yearly investment report without monthly deposits.
     *        Interest is compounded monthly on the initial investment.
     */
    void printReportWithoutMonthlyDeposit();

    /**
     * @brief Displays a yearly investment report including monthly deposits.
     *        Interest is compounded monthly on the balance before each deposit.
     */
    void printReportWithMonthlyDeposit();

private:
    // Member variables representing user input
    double m_initialInvestment;   ///< Initial investment amount
    double m_monthlyDeposit;      ///< Monthly deposit amount
    double m_interestRate;        ///< Annual interest rate (percentage)
    int m_numberOfYears;          ///< Total number of years for the investment

    /**
     * @brief Outputs the year-end balance and interest earned in tabular format.
     *
     * @param t_year             The year number.
     * @param t_yearEndBalance   The total balance at year end.
     * @param t_interestEarned   The interest earned during the year.
     */
    void printDetails(int t_year, double t_yearEndBalance, double t_interestEarned);
};

#endif // AIRGEAD_BANKAPP_H_