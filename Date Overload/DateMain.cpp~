#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Date.cpp"

using namespace std;

int main()
{
	Date date1; //Calls default constructor
	int inMonth;
	int inDay;
	int inYear;
	int numberofdays;

	cout << "Program will print stu after constructors." << endl;
	cout << date1;
	cout << endl;

	cout << "Make sure the months are different." << endl;
	cout << "Enter the date numerically (Month Day Year): ";
	cin >> inMonth >> inDay >> inYear;
	date1.setMonth(inMonth);
	date1.setDay(inDay);
	date1.setYear(inYear);

	while(date1.validation() == false) //Calls validation function
	{
		cout << "\nThe month or day is incorrect. Please re-enter the date (M D Y): ";
		cin >> inMonth >> inDay >> inYear;
		date1.setMonth(inMonth);
		date1.setDay(inDay);
		date1.setYear(inYear);
	}
	
	cout << "Enter a second date (M D Y): ";
	cin >> inMonth >> inDay >> inYear;
	Date date2 (inMonth, inDay, inYear); //Calls constructor 2

	while(date2.validation() == false) //Calls validation function
	{
		cout << "\nThe month or day is incorrect. Please re-enter the date (M D Y): ";
		cin >> inMonth >> inDay >> inYear;
		date2.setMonth(inMonth);
		date2.setDay(inDay);
		date2.setYear(inYear);
	}

	cout << "Printing the two dates:" << endl;
	cout << date1;
	cout << date2;

	cout << "The first date will be moved forward by a certain number of days." << endl;
	cout << "Enter the number of days to add: ";
	cin >> numberofdays;
	date1 = date1 + numberofdays;
	cout << "New date: " << date1;

	if(date1 == date2) //Calls boolean function for comparing months
		cout << "\nThe months are the same." << endl;
	else
		cout << "\nThe months are not the same." << endl;

	cout << "\nMake sure the months are the same." << endl;
	cout << "Enter a date (Month Day Year): ";
	cin >> inMonth >> inDay >> inYear;
	Date date3 (inMonth, inDay, inYear); //Calls constructor 2

	while(date3.validation() == false) //Calls validation function
	{
		cout << "\nThe month or day is incorrect. Please re-enter the date (M D Y): ";
		cin >> inMonth >> inDay >> inYear;
		date3.setMonth(inMonth);
		date3.setDay(inDay);
		date3.setYear(inYear);
	}
	
	cout << "Enter a second date (M D Y): ";
	cin >> inMonth >> inDay >> inYear;
	Date date4 (inMonth, inDay, inYear); //Calls constructor 2

	while(date4.validation() == false) //Calls validation function for a boolean value
	{
		cout << "\nThe month or day is incorrect. Please re-enter the date (M D Y): ";
		cin >> inMonth >> inDay >> inYear;
		date4.setMonth(inMonth);
		date4.setDay(inDay);
		date4.setYear(inYear);
	}

	cout << "\nPrinting the two dates:" << endl;
	cout << date3;
	cout << date4;

	if(date3 == date4) //Calls boolean function for comparing months
		cout << "\nThe months are the same." << endl;
	else
		cout << "\nThe months are not the same." << endl;

	cout <<  "\nThe first date will increment forward a day." << endl;
	cout << "Original date: ";
	cout << date1;
	date1.nextDay();
	cout << "New date: ";
	cout << date1;

	return 0;
}
