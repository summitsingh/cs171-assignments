#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	int time;
	int honolulu;
	int seattle;
	int london;
	int moscow;
	int hongkong;
	int aukland;
	cout << "What is the current time in Philadelphia? ";
	cin >> time; //input current time
	cout << endl; //new line
	honolulu = (time - (6 * 100)) + 2400; //convert the time in Honolulu
	seattle = (time - (3 * 100)) + 2400; //convert the time in Seattle
	london = (time + (5 * 100)) + 2400; //convert the time in London
	moscow = (time + (8 * 100)) + 2400; //convert the time in Moscow
	hongkong = (time + (12 * 100)) + 2400; //convert the time in Hongkong
	aukland = (time + (17 * 100)) + 2400; //convert the time in Aukland
	cout << "Current times in other cities" << endl;
	cout << endl; //new line
	cout << "Honolulu: \t" << setw(4) << setfill('0') << honolulu % 2400 << endl; //output time in Honolulu
	cout << "Seattle: \t" << setw(4) << setfill('0') << seattle % 2400 << endl; //output time in Seattle
	cout << "London: \t" << setw(4) << setfill('0') << london % 2400 << endl; //output time in London
	cout << "Moscow: \t" << setw(4) << setfill('0') << moscow % 2400 << endl; //output time in Moscow
	cout << "Hong Kong: \t" << setw(4) << setfill('0') << hongkong % 2400 << endl; //output time in Hong Kong
	cout << "Aukland: \t" << setw(4) << setfill('0') << aukland % 2400 << endl; //output time in Aukland

	return 0;
}