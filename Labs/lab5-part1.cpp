#include <iostream>
using namespace std;

double celsius(double f)
{
	return (f - 32) / 1.8;
}

int main(void)
{
	double f;
	cout << "Fahrenheit to Celsius Converter. Enter number greater than 1,000 to quit." << endl;
	do
	{
		cout << "Enter Temp in Fahrenheit: ";
		cin >> f;
		cout << "In Celsius this is " << celsius(f) << endl;
		if (f>1000)
		{
			return 0;
		}
	} while (f<1000);
}