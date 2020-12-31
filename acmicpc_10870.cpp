#include <iostream>
using namespace std;


// Function returning the nth Fibonacci number
int Fibonacci(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << Fibonacci(n);
}
