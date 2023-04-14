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

double Fibonacci(int n)
{
	if (n <= 2) return 1;
	else return (Fibonacci(n - 1) + Fibonacci(n - 2));
	//return n < 3 ? 1 : n>3 ? (Fibonacci(n - 1) + Fibonacci(n - 2);
}



void main()
{
	//cout << "Hello Recursion";
	//main();
	int n;
	int a;
	int limit;
	//cout << "Enter number";
	 //cin >> a;
	 cout << "Enter power ";
	 cin >> limit;
	 //cout << a << " ^ " << n << " is " << power(a, n) << endl;
	 
	//factorial(n);
	//cout << "Factorial for " << n << " is " << factorial(n) << endl;

	 //int t = 2;
	 //int f = 4;
	 //int l = 5;
	 //cout << t + f * l << endl; // wow



	 for (int i = 0; i <= limit; i++)
	 {
		 cout << Fibonacci(i) << " " << endl;
	 }
}

