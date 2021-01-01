#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int Size(int n)
{
	int size = 0;
	for (int i = 0;; i++)
	{
		n = n / 10;
		size++;
		if (n == 0)
			return size;
	}
}

int Digits(int n, int m)
{
	return n / (int)pow(10, m - 1) % 10;
}

int SumOfDivs(int num)
{
	int n, j, sum;
	int size = Size(num);
	int min = num - 9 * size;
	for (n = min; n < num; n++)
	{
		sum = n;
		for (j = 1; j <= size; j++)
			sum += n / (int)pow(10, j - 1) % 10;
		if (sum == num)
			return n;
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);

	/*
	int arr[100];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	*/

	printf("%d", SumOfDivs(n));

	return 0;
}

