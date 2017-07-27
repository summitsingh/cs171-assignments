#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream is;
ofstream os;

//function to output status of the craft to file
void reportStatus(ostream &os, double time, double height, double velocity, double fuel, string name)
{
	os << endl << "Status of your " << name << " spacecraft:" << endl;
	os << "Time   : " << time << " seconds" << endl;
	os << "Height : " << height << " feet" << endl;
	os << "Speed  : " << velocity << " feet/second" << endl;
	//to print "OUT OF FUEL" if fuel is less than zero
	if (fuel <= 0)
	{
		os << "Fuel   : " << fuel << endl;
		os << "**** OUT OF FUEL ****" << endl;
	}
	else
	{
		os << "Fuel   : " << fuel << endl;
	}
}

//function to update status of the craft
void updateStatus(double &velocity, double burnAmount, double &fuelRemaining, double &height)
{
	fuelRemaining = fuelRemaining - burnAmount;
	height = height - velocity - (5 - burnAmount) / 2;
	velocity = (velocity + 5) - burnAmount;
}

//function to replace "$SPACECRAFT" with "APOLLO"
void introduction(istream &is, ostream &os, string target, string replacement)
{
	string x;
	while (getline(is, x))
	{ 
		while (x.find(target) != -1)
			x.replace(x.find(target), target.length(), replacement);
		cout << x << endl;
		os << x << endl;
	}
}

//function to calculate the touchdown time
void touchdown(double &elapsedTime, double &velocity, double &burnAmount, double &height)
{
	double delta;
	velocity = velocity - 5 + burnAmount;
	height = height + velocity + (5 - burnAmount) / 2;
	elapsedTime--;
	if (burnAmount != 5)
		delta = (sqrt(velocity*velocity + height*(10 - 2 * burnAmount)) - velocity) / (5 - burnAmount);
	else
		delta = height / velocity;
	elapsedTime = elapsedTime + delta;
	velocity = velocity + (5 - burnAmount)*delta;
}

//function to print file analysis
void finalAnalysis(ostream &os, double velocity)
{
	if (velocity == 0)
	{
		cout << "Congratulations! A perfect landing!!" << endl << "Your license will be renewed...later." << endl;
		os << "Congratulations! A perfect landing!!" << endl << "Your license will be renewed...later." << endl;
	}
	else if (velocity < 2)
	{
		cout << "A little bumpy." << endl;
		os << "A little bumpy." << endl;
	}
	else if (velocity < 5)
	{
		cout << "You blew it!!!!!!" << endl << "Your family will be notified...by post." << endl;
		os << "You blew it!!!!!!" << endl << "Your family will be notified...by post." << endl;
	}
	else if (velocity < 10)
	{
		cout << "Your ship is a heap of junk !!!!!" << endl << "Your family will be notified...by post." << endl;
		os << "Your ship is a heap of junk !!!!!" << endl << "Your family will be notified...by post." << endl;
	}
	else if (velocity < 30)
	{
		cout << "You blasted a huge crater !!!!" << endl << "Your family will be notified...by post." << endl;
		os << "You blasted a huge crater !!!!" << endl << "Your family will be notified...by post." << endl;
	}
	else if (velocity < 50)
	{
		cout << "Your ship is a wreck !!!!!" << endl << "Your family will be notified...by post." << endl;
		os << "Your ship is a wreck !!!!!" << endl << "Your family will be notified...by post." << endl;
	}
	else if (velocity >= 50)
	{
		cout << "You totaled an entire mountain !!!!!" << endl << "Your family will be notified...by post." << endl;
		os << "You totaled an entire mountain !!!!!" << endl << "Your family will be notified...by post." << endl;
	}
}

//main function
void main()
{
	char instructions, output;
	string outputfile;
	double velocity = 50, burnAmount = 0, fuelRemaining = 150, height = 1000, time = 0;
	//ask the user if the user wants to see the instructions
	cout << "Do you want to see the instructions (y/n)? ";
	cin >> instructions;
	cout << endl;
	//ask the user if he/she wants to output the logs
	cout << "Do you want to output the logs in a file (y/n)? ";
	cin >> output;
	cout << endl;
	//ask the user for name of the output file
	if (output == 'Y' || output == 'y')
	{
		cout << "Name of the output file (for example - test1.txt): ";
		cin >> outputfile;
		cout << endl;
	}
	//opens intput file for the program instructions
	is.open("input.txt");
	//opens output file
	os.open(outputfile);
	//calls introduction function and replace "$SPACECRAFT" with "APOLLO"
	if (instructions == 'Y' || instructions == 'y')
		introduction(is, os, "$SPACECRAFT", "APOLLO");
	cout << endl << "LUNAR LANDER" << endl;
	cout << "Beginning landing procedure.........." << endl;
	cout << "DIGBY wishes you good luck !!!!!!!" << endl;
	os << endl << "LUNAR LANDER" << endl;
	os << "Beginning landing procedure.........." << endl;
	os << "DIGBY wishes you good luck !!!!!!!" << endl;
	//while loop to make sure height is greater than 0
	while (height > 0)
	{
		cout << endl << "Status of your APOLLO spacecraft:" << endl;
		cout << "Time   : " << time << " seconds" << endl;
		cout << "Height : " << height << " feet" << endl;
		cout << "Speed  : " << velocity << " feet/second" << endl;
		if (fuelRemaining <= 0)
		{
			cout << "Fuel   : " << fuelRemaining << endl;
			cout << "**** OUT OF FUEL ****" << endl;
		}
		else
		{
			cout << "Fuel   : " << fuelRemaining << endl;
		}
		if (fuelRemaining > 0)
		{
			cout << "Enter fuel burn amount: ";
			cin >> burnAmount;
		}
		//while loop if burnAmount is greater than 30
		while (burnAmount > 30)
		{
			cout << "More than 30 not allowed" << endl;
			cout << "Enter fuel burn amount: ";
			cin >> burnAmount;
		}
		//while loop if burnAmount is less than 0
		while (burnAmount < 0)
		{
			cout << "Negative value not allowed" << endl;
			cout << "Enter fuel burn amount: ";
			cin >> burnAmount;
		}
		//burnAmount will be equal to fuelRemaining if the input burnAmount value is greater than fuelRemaining
		if (burnAmount > fuelRemaining)
		{
			burnAmount = fuelRemaining;
		}
		//calls reportStatus function
		if (output == 'Y' || output == 'y')
		{
			reportStatus(os, time, height, velocity, fuelRemaining, "APOLLO");
		}
		os << "Enter fuel burn amount: " << burnAmount << endl;
		//calls updateStatus function
		updateStatus(velocity, burnAmount, fuelRemaining, height);
		//to increment time in each loop
		time++;
	}
	//calls touchdown function
	touchdown(time, velocity, burnAmount, height);
	cout << endl << "***** CONTACT *****";
	cout << endl << "Touchdown at " << time << " seconds." << endl;
	cout << "Landing velocity = " << velocity << " feet/sec." << endl;
	cout << fuelRemaining << " units of fuel remaining." << endl << endl;
	os << endl << "***** CONTACT *****";
	os << endl << "Touchdown at " << time << " seconds." << endl;
	os << "Landing velocity = " << velocity << " feet/sec." << endl;
	os << fuelRemaining << " units of fuel remaining." << endl << endl;
	//calls finalAnalysis function
	finalAnalysis(os, velocity);
	//close file
	is.close();
	os.close();
}