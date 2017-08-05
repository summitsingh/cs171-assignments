#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

void analyze(string filename, vector<int> & results, int min_age, int max_age)
{
        ifstream fin;
        fin.open(filename);
        
        string search;
        ifstream inFile;
        string line;
        
        inFile.open(filename);

        for(int i=0;i<results.size();i++)
        results[i] = 0;

        char a;
        int b,c;
        while(inFile>>a>>b>>c)
        {
            if (min_age<=b && b<=max_age){
                if (a=='M'){
                    results[c*2-2]+=1;
                }
                else if (a=='F'){
                    results[c*2-1]+=1;
                }
            }
        }
        fin.close();
}

void print_bar(int num)
{
    int x,y;
    
    x = num/10;
    y = num%10;
    
    for(int i=0;i<x;i++)
        cout<<"X";
    cout<<y<<"\n";
}

void print_chart(vector<int> & results){
    for(int i = 0;i<results.size();i++){
        if((i%2) == 0)
        cout<<"M Freq. ";
        else cout <<"F Freq. ";
        
        if((i%2) == 0)
        cout<< ((i+2)/2) <<" ";
        else cout<<((i+1)/2)<<" ";;
        print_bar(results[i]);
    }
}

void main()
{
    string filename = "alcohol.txt";
	char x='y';

    int min_age, max_age;
    vector<int> results(10);

	while (x == 'y')
	{
		cout << "Enter min age as an integer: ";
		cin >> min_age;
		cout << "Enter max age as an integer: ";
		cin >> max_age;
    
    ifstream input_stream;
    input_stream.open(filename.c_str(), ios::in);
    if(!input_stream)
    {
        cout<<"Error\n";
    }
    else {
        analyze(filename, results, min_age, max_age);
        print_chart(results);
    }
	cout << "Create new table? (y/n)";
	cin >> x;
	}
}