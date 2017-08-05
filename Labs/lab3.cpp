#include <iostream>
#include <string>
using namespace std;

int part1(void)
{
	int x;
	cout << "Enter a month using it's numerical representation (Jan=1, Dec=12): ";
	cin >> x;
	if (x == 1 || x == 3 || x == 5 || x == 7 || x == 9 || x == 11 || x == 12)
		cout << "31 days" << endl;
	else if (x == 2)
		cout << "28 or 29 days" << endl;
	else
		cout << "30 days" << endl;

	return 0;
}

int part2(void)
{
	string a, b, c;
	cout << "Enter three strings: ";
	cin >> a;
	cin >> b;
	cin >> c;

	if ((a < b) && (a < c) && (b < c))
		cout << a << " " << b << " " << c << endl;
	else if ((a < b) && (a < c) && (c < b))
		cout << a << " " << c << " " << b << endl;
	else if ((b < a) && (b < c) && (a < c))
		cout << b << " " << a << " " << c << endl;
	else if ((b < a) && (b < c) && (c < a))
		cout << b << " " << c << " " << a << endl;
	else if ((c < a) && (c < b) && (a < b))
		cout << c << " " << a << " " << b << endl;
	else if ((c < a) && (c < b) && (b < a))
		cout << c << " " << b << " " << a << endl;

	return 0;
}

int part3(void)
{
	float hours, rate, hours1, rate1, extra = 0;
	cout << "How may hours did you work this week? ";
	cin >> hours;
	cout << "How much are you paid per hour? ";
	cin >> rate;
	if (hours > 40)
	{
		hours1 = hours - 40;
		hours = hours - hours1;
		rate1 = rate*1.5;
		extra = hours1*rate1;
	}
	cout << "Pay for the week: " << (hours*rate) + extra << endl;

	return 0;
}

int main(void)
{
	int x;
	cout << "Which program do you want to run? (1,2,3): ";
	cin >> x;
	if (x==1)
		part1();
	else if (x==2)
		part2();
	else if (x==3)
		part3();
	return 0;
}