#include <iostream>
#include <iomanip>
using namespace std;

const double MOON_GRAVITY = -1.63;

void main()
{
    double a, v;
	double fuel_tank;
    double f = 0;
    int count = 0;
    cout << "Enter an initial altitude: ";
    cin >> a;
    cout << "Enter an initial velocity: ";
    cin >> v;
    cout << "Enter the initial fuel amount: ";
    cin >> fuel_tank;
    while (a > 0)
	{
		v += MOON_GRAVITY + (0.1 * fuel_tank);
		a = a + v;
		count++;
        cout << "After " << count << " seconds Altitude is " << setprecision(4) << a << " meters, velocity is " << setprecision(4) << v << "m/s" << endl;
		if (a > 0)
		{
			cout << "How much fuel do you want to burn? ";
            cin >> f;
            if (fuel_tank < f)
			{
                cout << "You only have " << fuel_tank << " fuel units left. Please enter a valid amount of fuel to burn: " << endl;
                cin >> f;
            }
            fuel_tank -= f;
		}
    }
    if (v < -2)
	{
        cout << "We crashed! :(" << endl;
    }
    else
	{
        cout << "Successful landing." << endl;
    }
}