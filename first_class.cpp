// Classes.cpp : Defines the entry point for the console application.

//#include "stdafx.h"
#include <iostream>
using namespace std;

class DayOfYear
{
public:
	void input(); //member function prototype
	void output(); //member function prototype
	int month;
	int day;
};

int main()
{
	DayOfYear today;
	DayOfYear birthday;

	int letter;

	cout << "Enter today's date:\n";
	today.input();
	cout << "Enter your birthday:\n";
	birthday.input();
	cout << "Today's date is ";
	today.output();
	cout << "Your birthdate is ";
	birthday.output();

	if (today.month == birthday.month
		&& today.day == birthday.day)
		cout << "Happy Birthday!\n";
	else
		cout << "Happy Birthday Anyways!\n";

	cin >> letter;

	return 0;
}

void DayOfYear::output()
{
	cout << "month = " << month
		<< ", day = " << day << endl;
}

void DayOfYear::input()
{
	cout << "Enter month as a number: ";
	cin >> month;
	cout << "Enter day of the month: ";
	cin >> day;

}



