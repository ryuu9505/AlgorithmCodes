#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//
int TripleSix(int N)
{
	int i, j, n, nth = 0, digit, combo = 0;

	for (i = 666;; i++)
	{
		combo = 0;
		for (j = 0;; j++)
		{
			n = i / (int)pow(10, j);
			digit = n % 10;
			if (n == 0)
				break; 
			else if (digit == 6)
			{
				combo++;
				if (combo == 3)
				{
					nth++;
					break;
				}
			}
			else
				combo = 0;
		}
		if (nth == N)
			return i;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", TripleSix(N));
}
