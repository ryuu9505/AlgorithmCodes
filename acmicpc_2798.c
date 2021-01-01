#include <stdio.h>

// Brute-Force
int BlackJack(int n, int m, int card_num[])
{
	int sum, best = 0;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = card_num[i] + card_num[j] + card_num[k];
				if (sum <= m && sum > best)
					best = sum;
			} 
		}
	}

	return best;
}

int main()
{
	int n, m;
	int card_num[100];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &card_num[i]);
	printf("%d", BlackJack(n, m, card_num));

	return 0;
}

