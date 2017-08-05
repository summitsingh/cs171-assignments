#include <iostream>
#include <string>
using namespace std;

string one = "I";
string five = "V";
string ten = "X";
string fifty = "L";
string hundred = "C";
string fivehundred = "D";
string thousand = "M";
string five_thousand = "v";
string ten_thousand = "x";

string roman(int number, string one, string five, string ten)
{
	if (number == 1)
		return one;
	if (number == 2)
		return one + one;
	if (number == 3)
		return one + one + one;
	if (number == 4)
		return one + five;
	if (number == 5)
		return five;
	if (number == 6)
		return five + one;
	if (number == 7)
		return five + one + one;
	if (number == 8)
		return five + one + one + one;
	if (number == 9)
		return one + ten;
}

string roman_num(int number)
{
	string ones = roman(number % 10, one, five, ten);
	number /= 10;
	string tens = roman(number % 10, ten, fifty, hundred);
	number /= 10;
	string hundreds = roman(number % 10, hundred, fivehundred, thousand);
	number /= 10;
	string thousands = roman(number % 10, thousand, five_thousand, ten_thousand);
	return thousands + hundreds + tens + ones;
}

int main()
{
	int number;
	cout << "Roman Number Generator." << endl;
	do
	{
		cout << "Please enter a number between 1 and 3,999:  ";
		cin >> number;
		if (number >= 1 && number <= 3999)
		{
			cout << "Roman Numerals: " << roman_num(number) << endl;
		}
		else
		{
			cout << "Invalid Value, enter between 1 and 3,999" << endl;
		}
	} while (number != 0);
	return 0;
}