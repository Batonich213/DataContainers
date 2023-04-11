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

double power(double a, int n)
{
	/*if (n == 0)
		return 1;
	else if (n > 0) return a * power(a, n - 1);
	else if (n < 0) return  1 / power(a, -n);*/
	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / power(a, -n);
}


//double SubFactorial(int n);



void main()
{
	//cout << "Hello Recursion";
	//main();
	int n;
	int a;
	cout << "Enter number";
	 cin >> a;
	 cout << "Enter power ";
	 cin >> n;
	 cout << a << " ^ " << n << " is " << power(a, n) << endl;
	 
	//factorial(n);
	//cout << "Factorial for " << n << " is " << factorial(n) << endl;

	 //int t = 2;
	 //int f = 4;
	 //int l = 5;
	 //cout << t + f * l << endl; // wow
}

