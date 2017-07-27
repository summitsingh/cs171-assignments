#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

//this function randomly assigns the value `C' or `G' to the three reference parameters
//checks that two of door1, door2, and door3 is a `G', and that the other is a `C'
void setupDoors(char &door1, char &door2, char &door3)
{
	vector<char> v1 = { 'G', 'G', 'C' };
	random_shuffle(v1.begin(), v1.end()); //shuffles vector for random C and two G's
	door1 = v1[0], door2 = v1[1], door3 = v1[2];
}

//this function obeys the constraint that Monty never picks the same door as the player and never picks the door that has the car
void pickDoorChoices(char door1, char door2, char door3, int &doorPlayer, int &doorMonty)
{
	doorPlayer = rand() % 3 + 1; //random number from 1 to 3 assigned to doorPlayer
	if (doorPlayer == 1)
	{
		if (door2 == 'C')
			doorMonty = 3;
		else
			doorMonty = 2;
	}
	if (doorPlayer == 2)
	{
		if (door1 == 'C')
			doorMonty = 3;
		else
			doorMonty = 1;
	}
	if (doorPlayer == 3)
	{
		if (door2 == 'C')
			doorMonty = 1;
		else
			doorMonty = 2;
	}
}

//function returns true when player wins by not switching
bool checkDoors(char door1, char door2, char door3, int doorPlayer)
{
	if (doorPlayer == 1 && door1 == 'C')
		return 1;
	if (doorPlayer == 2 && door2 == 'C')
		return 1;
	if (doorPlayer == 3 && door3 == 'C')
		return 1;
	return 0; //returns false if player doesn't wins
}

//this function switches door values
int switchDoors(int doorPlayer, int doorMonty)
{
	if (doorPlayer == 1 && doorMonty == 2)
		return 3;
	if (doorPlayer == 1 && doorMonty == 3)
		return 2;
	if (doorPlayer == 2 && doorMonty == 3)
		return 1;
	if (doorPlayer == 2 && doorMonty == 1)
		return 3;
	if (doorPlayer == 3 && doorMonty == 2)
		return 1;
	if (doorPlayer == 3 && doorMonty == 1)
		return 2;
	return 0;
}

//function to show table which includes percentage of stay wins and switch wins
void table(int stayWins, int switchWins)
{
	cout << "Monty Hall Problem" << endl;
	cout << "\t\tPercent Win\tNumber of Wins" << endl;
	cout << "Switch Wins\t" << setprecision(2) << fixed << ((switchWins * 100) / 10000) << "%\t\t" << switchWins << endl; //shows percentage of Switch Wins
	cout << "Stay Wins\t" << setprecision(2) << fixed << ((stayWins * 100) / 10000) << "%\t\t" << stayWins << endl; //shows percentage of Stay Wins
}

void main()
{
	cout << "Is it to the player's advantage to switch doors after Monty tells them?" << endl << endl;
	char door1, door2, door3;
	int doorPlayer, doorMonty;
	double stayWins = 0, switchWins = 0;
	srand(time(NULL)); //function used to generate random numbers
	for (int i = 0; i < 10000; i++) //this loop is used to test the results for 10000 games
	{
		setupDoors(door1, door2, door3); //this function setup doors 1, 2 and 3
		pickDoorChoices(door1, door2, door3, doorPlayer, doorMonty); //this function setup door for Monty
		if (checkDoors(door1, door2, door3, doorPlayer)) //this function checks if the player wons without switching
			stayWins++; //to increment stayWins while if is true
		doorPlayer = switchDoors(doorPlayer, doorMonty); //this function switches the door value and assigns to doorPlayer
		if (checkDoors(door1, door2, door3, doorPlayer)) //checks if the player wons after switching
			switchWins++; //to increment switchWins while if is true
	}
	//Monty Hall Problem table
	table(stayWins, switchWins);
}