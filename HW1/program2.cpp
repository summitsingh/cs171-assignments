#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	int ounces, barrel, gallon, quart, pint, cup, gill, tablespoons;
	int barrelr, gallonr, quartr, pintr, cupr, gillr;

	cout << "How many fluid ounces do you have? ";
	cin >> ounces; //input fluid ounces

	barrel = ounces / 5376; //convert ounces to barrel
	barrelr = ounces % 5376;

	gallon = barrelr / 128; //convert barrel to gallon
	gallonr = barrelr % 128;

	quart = gallonr / 32; //convert gallon to quart
	quartr = gallonr % 32;

	pint = quartr / 16; //convert quart to pint
	pintr = quartr % 16;

	cup = pintr / 8; //convert pint to cup
	cupr = pintr % 8;

	gill = cupr / 4; //convert cup to gill
	gillr = cupr % 4;

	tablespoons = gillr * 2; //convert gill to tablespoons

	cout << ounces << " fluid ounces can be divided into:" << endl;
	cout << barrel << " barrel(s)" << endl; //output barrel
	cout << gallon << " gallon(s)" << endl; //output gallon
	cout << quart << " quart(s)" << endl; //output quart
	cout << pint << " pint(s)" << endl; //output pint
	cout << cup << " cup(s)" << endl; //output cup
	cout << gill << " gill(s)" << endl; //output gill
	cout << tablespoons << " tablespoons" << endl; //output tablespoons

	return 0;
}