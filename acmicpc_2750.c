#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 1000

// Bubble Sort
void bubble_sort(int list[], int n)
{
	int i, j, temp;

	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int i;
	//int n = MAX_SIZE;
	int n;
	int list[MAX_SIZE];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}
	bubble_sort(list, n);
	for (i = 0; i < n; i++)
	{
		printf("%d\n", list[i]);
	}
}
