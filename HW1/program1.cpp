#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	long tuition = 0, cents = 0, total = 0;
	double percentage = 0, rate = 0;

	cout << "Enter the initial tuition amount: ";
	cin >> tuition; //input tuition
	cents = tuition * 100;
	cout << "Enter the yearly tuition increase (as a percentage): ";
	cin >> percentage; //input percentage
	rate = (percentage / 100) + 1;
	cout << "Tuition of year 1 is: $" << cents / 100 << "." << setfill('0') << setw(2) << cents % 100 << endl; //output year 1 tuition (dollars and cents)
	total = total + cents; //add year 1 tuition to total
	cents = static_cast<long>(cents * rate); //multiply year 1 tuition with rate to get year 2 tuition
	cout << "Tuition of year 2 is: $" << cents / 100 << "." << setfill('0') << setw(2) << cents % 100 << endl; //output year 2 tuition (dollars and cents)
	total = total + cents; //add year 2 tuition to total
	cents = static_cast<long>(cents * rate); //multiply year 2 tuition with rate to get year 3 tuition
	cout << "Tuition of year 3 is: $" << cents / 100 << "." << setfill('0') << setw(2) << cents % 100 << endl; //output year 3 tuition (dollars and cents)
	total = total + cents; //add year 3 tuition to total
	cents = static_cast<long>(cents * rate); //multiply year 3 tuition with rate to get year 4 tuition
	cout << "Tuition of year 4 is: $" << cents / 100 << "." << setfill('0') << setw(2) << cents % 100 << endl; //output year 4 tuition (dollars and cents)
	total = total + cents; //add year 4 tuition to total
	cents = static_cast<long>(cents * rate); //multiply year 4 tuition with rate to get year 5 tuition
	cout << "Tuition of year 5 is: $" << cents / 100 << "." << setfill('0') << setw(2) << cents % 100 << endl; //output year 5 tuition (dollars and cents)
	total = total + cents; //add year 5 tuition to total
	cout << "Total Tuition Cost is $" << total / 100 << "." << setfill('0') << setw(2) << total % 100 << endl; //output total tuition (dollars and cents)

	return 0;
}