#include <iostream> 
#include <string>
#include <fstream>
using namespace std;

int starts_with_letter(string filename, char letter)
{
	string res_name = "results_";
	res_name += letter;
	res_name += ".txt";
	ifstream infile;
	infile.open(filename);
	ofstream outfile;
	outfile.open(res_name);
	string data;
	int counter = 0;
	while (infile >> data){
		if (data[0] == letter || data[0] == letter + 32){
			outfile << data << endl;
			counter += 1;
		}
	}
	infile.close();
	outfile.close();
	return counter;
}

void main()
{
	string filename;
	char letter = 'A';
	cout << "Enter the name of a file to read: ";
	cin >> filename;
	for (int i = 0; i < 26; i++)
	{
		cout << "The count of words that start with " << letter << " is " << starts_with_letter(filename, letter) << endl;
		letter++;
	}
}