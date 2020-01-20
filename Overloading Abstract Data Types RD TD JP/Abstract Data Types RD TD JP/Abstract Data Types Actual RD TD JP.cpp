#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Date
{
private:
	string month;
	int day;
	int year;
public:
	Date();
	Date(string aMonth, int aDay, int aYear);
	void setMonth(string aMonth);
	void setDay(int aDay);
	void setYear(int aYear);
	string getMonth() const;
	int getDay() const;
	int getYear() const;
	void printDate() const; //Highlight for later possible review
	bool sameMonth(Date arg_Date) const;
	bool operator == (const Date& arg_Date) const;
};

Date::Date() //Constructor 1
{
	month = " ";
	day = 0;
	year = 0;
}

Date::Date(string aMonth, int aDay, int aYear) //Constructor 2
{
	month = aMonth;
	day = aDay;
	year = aYear;
}

void Date::setMonth(string aMonth)
{
	month = aMonth;
}

void Date::setDay(int aDay)
{
	day = aDay;
}

void Date::setYear(int aYear)
{
	year = aYear;
}

string Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}

void Date::printDate() const //Review
{
	cout << "\n" << month << " " << day << ", " << year << endl;
}

ostream& operator << (ostream& os, const Date& arg_Date)
{
        os << "Date is: " << arg_Date.getMonth() 
           << "/" << arg_Date.getDay() 
           << "/" << arg_Date.getYear() << endl;
        return os;


bool Date::sameMonth(Date arg_Date) const
{
	if(month == arg_Date.getMonth())
		return true;
	else return false;
}

bool Date::operator == (const Date& arg_Date) const
{
    if (month == arg_Date.month && day == arg_Date.day && year == arg_Date.year)
        return true;
    else
        return false;
}

int main()
{
	Date date1; //Calls constructor 1
	string inMonth;
	int inDay;
	int inYear;

	cout << "Program will print stu after constructors. Also testing." << endl;
	date1.operator << (ostream& os, const Date& date1);
	cout << endl;

	cout << "Please enter the month name: ";
	cin >> inMonth;
	date1.setMonth (inMonth);
	
	cout << "\nEnter the day number: ";
	cin >> inDay;
	date1.setDay (inDay);
	
	cout << "\nEnter the year: ";
	cin >> inYear;
	date1.setYear (inYear);

	date1.operator << (ostream& os, const Date& date1);

	cout << "\nPlease enter the month name: ";
	cin >> inMonth;
	
	cout << "\nEnter the day number: ";
	cin >> inDay;
	
	cout << "\nEnter the year: ";
	cin >> inYear;

	Date date2 (inMonth, inDay, inYear); //Calls constructor 2
	
	date2.operator << (ostream& os, const Date& date1);
	if(date1.operator == (const Date& date2))
		cout << "The months are the same." << endl;
	else
		cout << "The months are not the same." << endl;

	cout << "\nPress enter any value to end program.:";

	cin >> inYear;
}
