/*
* Brent Artuch
* 10/2/2022
* CS 210 H7088
*/
#include <iostream>
#include "BankingApp.h"

using namespace std;

int main()
{
	/* Main Class Object*/
	BankingApp myApp; 
	/* Derived Class Objects */
	DataPrinter printData; 
	DepositReports printHeadings;
	BalanceCalculators printCalcs;

	char choice = ' '; // initialize choice variable for outer loop.

	while (choice != 'n') // if character n is entered loop will exit.
	{
		printData.printDataNoInput(); // call function to print data inputs without the information present.

		/* User Input with Setters */
		myApp.setInitialAmount(myApp.inputInvAmount()); // setter functions called with user input functions as parameters.
		myApp.setMonthlyDeposit(myApp.inputMonDeposit());
		myApp.setAnnualInterest(myApp.inputAnnInterest());
		myApp.setNumYears(myApp.inputNumYears());

		printData.printDataInput(myApp.getInitialAmount(), myApp.getMonthlyDeposit(), myApp.getAnnualInterest(), myApp.getNumYears()); // print the data inputs with the information present.

		printHeadings.balDepReportWithout(); // print the heading for the balance report without monthly deposits.
		printCalcs.calculateBalanceWithoutMonthlyDeposit(myApp.getInitialAmount(), myApp.getAnnualInterest(), myApp.getNumYears()); // calculates and prints the data with getter functions as parameters.

		printHeadings.balDepReportWith(); // print the heading for balance report with monthly deposits.
		printCalcs.balanceWithMonthlyDeposit(myApp.getInitialAmount(), myApp.getMonthlyDeposit(), myApp.getAnnualInterest(), myApp.getNumYears()); // calculates and prints the data with getter functions as parameters.

		char choice = ' '; // reinitialize choce for the nested loop.
		while (choice != 'y') { // while loop to get input from user as to whether they wish to continue.
			try { 
				cout << "Would you like to test different data? y or n" << endl;
				cin >> choice;

				if (choice == 'n') { // if choice is n, end the program
					return choice;
					break;
				}
				else {
				throw 202; // if choice is not y or n return error code 202 
				}
			}
			catch (int x) { // catch the error
				cout << "Must Enter y or n. Error NUmber: " << x << endl;
				cout << endl;
			}
		}
	}
	cout << " Program Ended" << endl;
	return 0;
}