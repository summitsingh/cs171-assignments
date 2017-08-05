#include <iostream>
using namespace std;

int part1(void)
{
	int x, min=100;
	do
	{
		cout << "Enter a number between 1 and 100. Enter 0 or a number > 100 to quit:" << endl;
		cin >> x;
		if (x == 0 || x > 100)
		{
			cout << "Bye" << endl;
			return 0;
		}
		if (x < min)
		{
			min = x;
		}
		cout << "The smallest number you have entered in : " << min << endl;
	} while (x != 0 && x < 100);
	return 0;
}

int part2(void)
{
	int min = 0, max = 100, guess = 50;
	char x;
	cout << "Let's play a guessing game." << endl;
	cout << "Pick a number between 0 and 100." << endl;
	cout << "I will make guesses. Tell me if your number is higher or lower." << endl;
	do
	{
		cout << "Is your secret number " << guess << "?" << endl;
		cout << "y for yes, l for lower, h for higher" << endl;
		cin >> x;
		if (x == 'h')
		{
			min = guess + 1;
			guess = (min + max) / 2;
		}
		else if (x == 'l')
		{
			max = guess - 1;
			guess = (min + max) / 2;
		}
		else if (x == 'y')
		{
			cout << "Your secret number was : " << guess << endl;
		}
	} while (x != 'y');
	return 0;
}

int main(void)
{
	int x;
	cout << "Which program do you want to run? (1,2): ";
	cin >> x;
	if (x == 1)
		part1();
	else if (x == 2)
		part2();
	return 0;
}