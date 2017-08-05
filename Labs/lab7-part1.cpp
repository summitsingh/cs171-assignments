#include <iostream>
using namespace std;

 int operations(int a, int b)
 {
 int running = (a*2);
 running = (running + 2);
 running = (running * 5);
 running = running - (10 - b);
 running = (running % 10);
 return running;
 }
 int main()
 {
 cout << "What is person A's number?" << endl;
 int personA;
 cin >> personA;
 cout << "What is person B's number?" << endl;
 int personB;
 cin >> personB;
 int calculated = operations(personA, personB);
 
 cout << "Person B is now revealing their secret number to the crowd." << endl;
 cout << "Person A is computing........." << endl;
 cout << "Your secret number is: " << calculated << endl;
 return 0;
 }
 
