#pragma once
#include <string>

using namespace std;

class BankingApp // includeds only methods that require private class variables.
{
private: // private variables for the four initial inputs.
	double InitialAmount;
	double MonthlyDeposit;
	double AnnualInterest;
	int NumYears;

public:
	/* Constructor */
	BankingApp();

	/* h linker for function to create strings of characters*/
	string nCharString(size_t n, char c); // included to be used across two other derived classes.
	
	/* Setters/Getters */
	void setInitialAmount(double a);
	double getInitialAmount();

	void setMonthlyDeposit(double d);
	double getMonthlyDeposit();

	void setAnnualInterest(double i);
	double getAnnualInterest();

	void setNumYears(int y);
	int getNumYears();

	/* User input functions*/
	double inputInvAmount();
	double inputMonDeposit();
	double inputAnnInterest();
	int inputNumYears();
};
/* Derived classes form the BankingApp parent class to inherit nCharacterString method */
class DataPrinter :public BankingApp
{
public:
	/* h linker for printing out the data table with no input yet provided */
	void printDataNoInput();

	/* h linker for printing out the table with the inputs inserted */
	int printDataInput(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
};
class DepositReports :public BankingApp 
{
public:
	/* h linker for printing out heading without monthly deposits */
	void balDepReportWithout();

	/* h linker for printing out heading with monthly deposits */
	void balDepReportWith();
};
class BalanceCalculators :public BankingApp
{
public:
	/* h linker for calculating balance without a monthly deposit */
	double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);

	/* h linker for calculating balance with a monthly deposit included */
	double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
};
