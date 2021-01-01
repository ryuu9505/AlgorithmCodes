#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Brute-Force
void Rank(int N, int x[], int y[])
{
	int ranking;
	for (int i = 0; i < N; i++)
	{
		ranking = 1;
		for (int j = 0; j < N; j++)
		{
			if (x[i] < x[j] && y[i] < y[j])
				ranking++;
		}
		printf("%d ", ranking);
	}
}


int main()
{
	int N;
	scanf("%d", &N);

	int x[50], y[50];
	for (int i = 0; i < N; i++)
		scanf("%d %d", &x[i], &y[i]);

	Rank(N, x, y);

	return 0;
}
