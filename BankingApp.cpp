#include "BankingApp.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

BankingApp::BankingApp() // constructor initializing the private variables.
{
	InitialAmount = 0;
	MonthlyDeposit = 0;
	AnnualInterest = 0;
	NumYears = 0;
}
string BankingApp::nCharString(size_t n, char c) // function to print out character lines.
{
	string charString = ""; // empty string.

	for (size_t i = 0; i < n; i++) { // for number given, that number of characters will be returned until number is reached.
		charString += c; // character that will be added.
	}
	return charString;
}

/* Data Printer Functions */
void DataPrinter::printDataNoInput() // print input requirments without user input.
{
	cout << endl; // blank line for whitespace.
	cout << nCharString(34, '*') << endl; // call nCharSring function to create borders. 
	cout << nCharString(11, '*') << " Data Input " << nCharString(11, '*') << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
	cout << endl;
}
int DataPrinter::printDataInput(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) // print the data requirments with user input.
{
	cout << endl; // blank line for whitespace.
	cout << nCharString(34, '*') << endl; // call nCharString function to create borders.
	cout << nCharString(11, '*') << " Data Input " << nCharString(11, '*') << endl;
	cout << "Initial Investment Amount: " << "$" << fixed << setprecision(2) << initialInvestment << endl; // fixed set precision used to get two decimal places in the double values. 
	cout << "Monthly Deposit: " << "$" << fixed << setprecision(2) << monthlyDeposit << endl;
	cout << "Annual Interest: " << "%" << interestRate << endl;
	cout << "Number of years: " << numberOfYears << endl;
	cout << endl;

	return 0;
}
/* Deposit Report Functions */
void DepositReports::balDepReportWithout() // prints out heading for data chart withou monthly deposits.
{
	cout << endl; // blank line for whitespace.
	cout << nCharString(5, ' ') << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << nCharString(66, '=') << endl; // utilize nCharString function for boreders again,
	cout << " " << "Year" << setw(30) << "Year End Balance" << setw(30) << "Year End Interest Earned" << endl;
	cout << nCharString(66, '-');
	cout << endl;
}
void DepositReports::balDepReportWith() // prints out heading for data chart with monthly deposits included.
{
	cout << endl; // blank line for whitespace.
	cout << nCharString(5, ' ') << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << nCharString(66, '=') << endl; // utilize nCharString function for boreders again,
	cout << " " << "Year" << setw(30) << "Year End Balance" << setw(30) << "Year End Interest Earned" << endl;
	cout << nCharString(66, '-');
	cout << endl;
}

/* Calculation Functions */
double BalanceCalculators::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) // will give us the data to fill in our balance report without monthly deposits.
{
	double openingAmount; // initialize the opening amount.
	double total = initialInvestment; // set the total to the initialInvestment parameter for later calculation.

	for (int i = 0; i < numberOfYears; i++) { // no monthly deposits to account for so utilize simple annual interest rate to be iterated through for as many years that are given.
		openingAmount = total * (interestRate / 100); // set opening amount to annual interest calculation using interestRate and initialInvestment parameters.
		total += openingAmount; // add the openingAmount variable to the toatal to get the year end balance.
		cout << setw(3) << i + 1 << setw(25) << total << setw(25) << openingAmount << endl; // output the year, balance, and intrest in uniform format using setw function.
		cout << endl;
	}
	return 0;
}
double BalanceCalculators::balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) // similar to the previous section but with a nested for loop incuded for monthly calculations.
{
	double openingAmount; // initialize the opening amount.
	double total = initialInvestment; // set the total to the initialInvestment parameter for later calculation.

	for (int i = 0; i < numberOfYears; i++) { // outer loop that will give us our outputed dated to the console for years given.
		double interest = 0; // initialize an interest variable for use within the loop.
		for (int j = 0; j < 12; j++) {
			openingAmount = (total + monthlyDeposit) * ((interestRate / 100) / 12); // add month elements to the previous equation so that we can return increases for individual months as to opposed to entire year.
			interest += openingAmount; // add openingAmount to the previously defined interedt variable to store our Year Earned Interest.
			total = total + monthlyDeposit + openingAmount; // add total, monthlyDeposit, and opening amount variables together to store our Year End Balance. 
		}
		cout << setw(3) << i + 1 << setw(25) << total << setw(25) << interest << endl; // output the year, balance, and intrest in uniform format using setw function.
		cout << endl;
	}
	return 0;
}

/* Setters and Getters for the Initial Inputs */
void BankingApp::setInitialAmount(double a)
{	
	InitialAmount = a;
}
double BankingApp::getInitialAmount()
{
	return InitialAmount;
}
void BankingApp::setMonthlyDeposit(double d)
{
	MonthlyDeposit = d;
}
double BankingApp::getMonthlyDeposit()
{
	return MonthlyDeposit;
}
void BankingApp::setAnnualInterest(double i)
{
	AnnualInterest = i;
}
double BankingApp::getAnnualInterest()
{
	return AnnualInterest;
}
void BankingApp::setNumYears(int y)
{
	NumYears = y;
}
int BankingApp::getNumYears()
{
	return NumYears;
}

/* Initial Input Functions */
double BankingApp::inputInvAmount() // input function that will store invAmount.
{
	while (true) { // continuous loop until the correct input is given.
		try {
			cout << "Enter Initial Investment Amount: " << endl;
			cin >> InitialAmount;

			if (InitialAmount > 0) { // if the input is a positive double
				return InitialAmount;
				break;
			}
			else {
				throw 505; // error code if input is negative.
			}
		}
		catch (int x) {
			cout << "Number must be postitive. Error Number: " << x << endl; // message that will be displayed if negative number is input by user.
			cout << endl; // whitespace.
		}
	}
}
double BankingApp::inputMonDeposit() // input function that will store the monthly deposit amount.
{
	while (true) { // continuous loop until the correct input is given.
		try {
			cout << "Enter Monthly Deposit: " << endl;
			cin >> MonthlyDeposit;

			if (MonthlyDeposit > 0) {
				return MonthlyDeposit;
				break;
			}
			else {
				throw 505; // error code if input is negative
			}
		}
		catch (int x) {
			cout << "Number must be postitive. Error Number: " << x << endl; // message that will be displayed if negative number is input by user.
			cout << endl;
		}
	}
}
double BankingApp::inputAnnInterest() // input function that will store the annInterest amount.
{
	while (true) { // continuous loop until the correct input is given.
		try {
			cout << "Enter Annual Interest Rate: " << endl;
			cin >> AnnualInterest;
			
			if (AnnualInterest > 0) {
				return AnnualInterest;
				break;
			}
			else {
				throw 505; // error code if input is negative
			}
		}
		catch (int x) {
			cout << "Number must be postitive. Error Number: " << x << endl; // message that will be displayed if negative number is input by user.
			cout << endl;
		}
	}
}
int BankingApp::inputNumYears() // input function that will store numYears.
{
	while (true) { // continuous loop until the correct input is given.
		try {
			cout << "Enter Number of years: " << endl;
			cin >> NumYears;

			if (NumYears > 0) {
				return NumYears;
				break;
			}
			else {
				throw 505; // error code if input is negative
			}
		}
		catch (int x) {
			cout << "Number must be postitive. Error Number: " << x << endl; // message that will be displayed if negative number is input by user.
			cout << endl;
		}
	}
}

