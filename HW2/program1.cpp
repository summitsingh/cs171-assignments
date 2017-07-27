#include <iostream>
using namespace std;
bool leap_year(int year) //function to check if the year is leap year or not
{
	if (year % 4 != 0) //if a year is not divisible by 4 then it is a common year
		year = 0;
	else if (year % 100 != 0) //if a year is not divisible by 100 then it is a leap year
		year = 1;
	else if (year % 400 != 0) //if a year is not divisible by 400 then it is a common year
		year = 0;
	else //it is a leap year
		year = 1;
	return year; //this function returns 1 if it is a leap year else it returns 0
}
int main(void)
{
	int year;
	for (int i = 1; i <= 8; i++) //for loop that runs 8 times
	{
		cout << "Enter year: ";
		cin >> year; //prompt user to enter year
		if (leap_year(year)) //check if the year is leap year or not
			cout << year << " is a leap year." << endl;
		else
			cout << year << " is not a leap year." << endl;
	}
	return 0;
}