#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define MAX_NUM 9

void counting_sort(int list[], int sorted[], int count[], int cumulative_sum[], int n)
{
	int i;

	for (i = 1; i <= n; i++)
		count[list[i]]++;

	cumulative_sum[0] = count[0];
	for (i = 1; i <= MAX_NUM; i++)
		cumulative_sum[i] = count[i] + cumulative_sum[i - 1];

	for (i = n; i > 0; i--)
		sorted[cumulative_sum[list[i]]--] = list[i];
}

int main()
{
	int i, n, size;
	int list[MAX_SIZE + 2];
	int sorted[MAX_SIZE + 2];
	int count[MAX_NUM + 1];
	int cumulative_sum[MAX_NUM + 1];

	scanf("%d", &n);

	for (i = 0; i <= MAX_NUM; i++)
		count[i] = 0;

	for (i = 0; i <= MAX_SIZE; i++)
	{
		if (n != 0)
		{
			list[i + 1] = n % 10;
			n /= 10;
		}
		else
		{
			size = i;
			counting_sort(list, sorted, count, cumulative_sum, size);
			break;
		}
	}

	for (i = size; i > 0; i--)
		printf("%d", sorted[i]);
	

}
