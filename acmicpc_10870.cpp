#include <iostream>
using namespace std;

int Pibonacci(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;

	return Pibonacci(n - 1) + Pibonacci(n - 2);
}

int main()
{
	int n;

	cin >> n;
	cout << Pibonacci(n);
}
