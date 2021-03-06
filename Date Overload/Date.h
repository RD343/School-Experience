#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;
	bool leap_year();
public:
	Date();
	Date(int aMonth, int aDay, int aYear);
	void setMonth(int aMonth);
	void setDay(int aDay);
	void setYear(int aYear);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	//void printDate() const;
	//bool sameMonth(Date date2) const;
	bool validation();
	void nextDay();
	Date& operator++ ();
	Date& operator++ (int);
	bool operator == (const Date& arg_Date) const;
};


Date operator+ (Date, int);
Date operator+ (int, Date);
ostream& operator << (ostream&, const Date&);
#endif
