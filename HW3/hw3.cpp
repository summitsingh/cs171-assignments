#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//global constant declarations
const double safe = 0.00;
const double someImpairment = 0.04;
const double significantAffected = 0.08;
const double someCriminalPenalties = 0.10;
const double deathPossible = 0.30;
const string SAFE = "Safe To Drive";
const string SOMEIMPAIR = "Some Impairment";
const string SIGNIFICANT = "Driving Skills Significantly Affected";
const string MOST_STATES = "Criminal Penalties in Most US States";
const string ALL_STATES = "Legally Intoxicated - Criminal Penalties in All US States";
const string YOURE_DEAD = "Death is Possible!";

//function computes the blood alcohol concentration for the given number of drinks, the given weight, and the given elapsed time since the last drink (duration)
//it returns via reference parameters both the male and female blood concentrations for that
void computeBloodAlocholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC)
{
	maleBAC = (static_cast<double>(numDrinks) / static_cast<double>(weight)) * 3.8;
	femaleBAC = (static_cast<double>(numDrinks) / static_cast<double>(weight)) * 4.5;
	while (duration >= 40)
	{
		maleBAC -= 0.01;
		femaleBAC -= 0.01;
		duration -= 40;
	}
}

//function that returns (as a string) appropriate message for the blood alcohol concentration
string impairment(double bac)
{
	if (bac == safe)
		return SAFE;
	else if (bac <= someImpairment)
		return SOMEIMPAIR;
	else if (bac <= significantAffected)
		return SIGNIFICANT;
	else if (bac <= someCriminalPenalties)
		return MOST_STATES;
	else if (bac <= deathPossible)
		return ALL_STATES;
	else if (bac > deathPossible)
		return YOURE_DEAD;
}

//function prints out the message and gets an integer
//if the integer is greater than or equal to lower and less than or equal to upper then it returns the integer
//otherwise, it loops, asking for an integer again
int promptForInteger(const string &message, int lower, int upper)
{
	int x;
	do
	{
		cout << message;
		cin >> x;
	} while (!(x >= lower && x <= upper));
	return x;
}

//function prints out the message and returns the value entered as its result
//function checks that the input character entered is an M or an F
char promptForMorF(const string &message)
{
	char gender;
	do
	{
		cout << message;
		cin >> gender;
	} while (!(gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f'));
	return gender;
}

//function prints a BAC model for up to and including ten drinks and with nicely formatted output
void showImpairmentChart(int weight, int duration, bool isMale)
{
	string gender;
	double maleBAC, femaleBAC, bac;
	if (isMale)
		gender = "male";
	else
		gender = "female";
	cout << weight << " pounds, " << gender << ", " << duration << " minutes since last drink" << endl;
	cout << setw(8) << "# drinks" << setw(6) << "BAC" << " " << "Status" << endl;
	for (int i = 0; i <= 11; i++) //for loop to print the data for upto and including ten drinks
	{
		computeBloodAlocholConcentration(i, weight, duration, maleBAC, femaleBAC); //calls computeBloodAlcocholConcentration() and returns BAC via reference parameters
		if (isMale)
			bac = maleBAC;
		else
			bac = femaleBAC;
		cout << setw(8) << i << setw(6) << setprecision(3) << fixed << bac << " " << impairment(bac) << endl;
	}
}

//main function
void main()
{
	int weight, duration;
	char gender;
	bool isMale;
	weight = promptForInteger("Enter your weight (in lbs): ",1,999); //calls promptForInteger() and returns weight
	duration = promptForInteger("How many minutes has it been since your last drink? ", 0, 999); //calls promptForInteger() and returns duration
	gender = promptForMorF("Enter your sex as M or F : "); //calls promptForMorF() and returns gender
	if (gender == 'M' || gender == 'm')
		isMale = 1;
	else
		isMale = 0;
	cout << endl;
	showImpairmentChart(weight, duration, isMale); //calls showImpairmentChart function and prints a BAC model
}