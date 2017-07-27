#include<iostream>
#include<string>
using namespace std;
const string HALFBAR = ":";
const string FULLBAR = "|";
const string ONEBAR = "00011";
const string TWOBAR = "00101";
const string THREEBAR = "00110";
const string FOURBAR = "01001";
const string FIVEBAR = "01010";
const string SIXBAR = "01100";
const string SEVENBAR = "10001";
const string EIGHTBAR = "10010";
const string NINEBAR = "10100";
const string ZEROBAR = "11000";
const int NUMBER_OF_DIGITS_IN_A_ZIP_CODE = 5;
const string ZERO_DIGIT = "0";
const string ONE_DIGIT = "1";
int makeCheckDigit(int zipcode) //function which returns checkdigit value
{
	int number = zipcode, numbersum = 0;
	for (int x = 1; x <= NUMBER_OF_DIGITS_IN_A_ZIP_CODE; x++) //for loop to sum all digits in zipcode
	{
		numbersum = numbersum + number % 10;
		number = number / 10;
	}
	return 10 - numbersum % 10; //returns checkdigit value
}
string convertDigit(int value) //function to convert digit to barcodes
{
	if (value == 1) //1 will be converted to barcode and the function will return the barcode
		return ":::||";
	if (value == 2) //2 will be converted to barcode and the function will return the barcode
		return "::|:|";
	if (value == 3) //3 will be converted to barcode and the function will return the barcode
		return "::||:";
	if (value == 4) //4 will be converted to barcode and the function will return the barcode
		return ":|::|";
	if (value == 5) //5 will be converted to barcode and the function will return the barcode
		return ":|:|:";
	if (value == 6) //6 will be converted to barcode and the function will return the barcode
		return ":||::";
	if (value == 7) //7 will be converted to barcode and the function will return the barcode
		return "|:::|";
	if (value == 8) //8 will be converted to barcode and the function will return the barcode
		return "|::|:";
	if (value == 9) //9 will be converted to barcode and the function will return the barcode
		return "|:|::";
	return "||:::"; //0 will be converted to barcode and the function will return the barcode
}
string barcode(int zipcode) //function to create barcode
{
	int checkDigit = makeCheckDigit(zipcode), digit = 0;
	string barcode; //variable used for storing barcode
	for (int i = 1; i <= NUMBER_OF_DIGITS_IN_A_ZIP_CODE; i++) //for loop used to convert digits to barcode and store in the variable
	{
		digit = zipcode % 10;
		barcode = convertDigit(digit) + barcode;
		zipcode /= 10;
	}
	barcode = barcode + convertDigit(checkDigit);
	barcode = FULLBAR + barcode + FULLBAR;
	return barcode; //function will return barcode
}
int main(void)
{
	int zipcode;
	cout << "Enter a 5-digit zipcode: ";
	cin >> zipcode; //prompt user to enter zipcode
	if (zipcode > 0) //checks if the zipcode is negative or not
	{
		cout << barcode(zipcode) << endl; //prints barcode
	}
	else
	{
		cout << "Zipcode cannot be a negative number." << endl;
	}
	return 0;
}