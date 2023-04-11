#include<iostream>
using namespace std;


void elevator(int floor)
{
	if (floor <= 0)
	{
		cout << "This is basement";
		return;
	}
	cout << "You on " << floor << " floor" << endl;
	elevator(floor - 1);
}

int factorial(int n)
{
	if (n < 0)
		return 0; 
	if (n == 0) 
		return 1; 
	else 
		return n * factorial(n - 1);
}

void main()
{
	//cout << "Hello Recursion";
	//main();
	int n;
	cout << "Enter nubmer";
	 cin >> n;
	factorial(n);
	cout << "Factorial for " << n << " is " << factorial(n) << endl;
}

