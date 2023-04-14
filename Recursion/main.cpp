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

void Fibonacci(long long n, long long int a = 0, long long int b =1)
{
	if (a + b >= n)return;
	cout << a + b << "\t";
	Fibonacci(n, b, a + b);
	//if (n <= 2) return 1;
	//else if (n > 2) return (Fibonacci(n - 1) + Fibonacci(n - 2));
	//return n <= 2 ? 1 : n >=2 ? (Fibonacci(n - 1) + Fibonacci(n - 2);
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
	cout << "Enter limit ";
	cin >> limit;
	//cout << a << " ^ " << n << " is " << power(a, n) << endl;

   //factorial(n);
   //cout << "Factorial for " << n << " is " << factorial(n) << endl;

	//int t = 2;
	//int f = 4;
	//int l = 5;
	//cout << t + f * l << endl; // wow


	Fibonacci(limit);
	
}

