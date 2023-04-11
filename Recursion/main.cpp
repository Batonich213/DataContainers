#include<iostream>
using namespace std;


void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "This is basement";
		return;
	}
	cout << "You on " << floor << " floor" << endl;
	elevator(floor - 1);
}



void main()
{
	//cout << "Hello Recursion";
	//main();
	int n;
	cout << "Enter floor number: "; cin >> n;
	elevator(n);
}

