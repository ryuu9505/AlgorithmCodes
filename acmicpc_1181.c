#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20000
#define MAX_LENGTH 50

char sorted[MAX_SIZE][MAX_LENGTH+1];

void merge(char str[][MAX_LENGTH + 1], int left, int mid, int right)
{
	int i, j, k, l, p, temp;
	i = left;
	j = mid + 1;
	k = left;

	// 중간을 기준으로 두개의 배열로 나누고 각 원소 값들을 하나씩 비교해 가며 임시 배열로 정렬
	while (i <= mid && j <= right) // 하나의 배열의 원소가 모두 정렬될 때까지
	{
		if (strlen(str[i]) < strlen(str[j]))
		{
			strcpy(sorted[k++], str[i++]);
		}
		else if (strlen(str[i]) == strlen(str[j]))
		{
			temp = k;
			for (p = 0; p < strlen(str[i]); p++)
			{
				if (str[i][p] < str[j][p])
				{
					strcpy(sorted[k++], str[i++]);
					break;
				}
				else if (str[i][p] > str[j][p])
				{
					strcpy(sorted[k++], str[j++]);
					break;
				}
			}
			if (temp == k)
				strcpy(sorted[k++], str[i++]);
		}
		else
		{
			strcpy(sorted[k++], str[j++]);
		}
	}

	// 남은 배열의 원소들은 임시 배열로 그대로 옮기기
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			strcpy(sorted[k++], str[l]);
	}
	else
	{
		for (l = i; l <= mid; l++)
			strcpy(sorted[k++], str[l]);
	}

	// 임시 배열에서 배열로 옮기기
	for (l = left; l <= right; l++)
		strcpy(str[l], sorted[l]);
}

void merge_sort(char str[][MAX_LENGTH + 1], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; // Divide
		merge_sort(str, left, mid); // Conquer
		merge_sort(str, mid + 1, right); // Conquer
		merge(str, left, mid, right); // Combine
	}
}

int main()
{
	int i, n, size;
	char str[MAX_SIZE][MAX_LENGTH + 1];
	char str_temp[MAX_LENGTH + 1];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", &str[i]);
	}

	merge_sort(str, 0, n-1);


	printf("%s\n", str[0]);
	strcpy(str_temp, str[0]);
	for (i = 1; i < n; i++)
	{
		if (strcmp(str[i], str_temp))
			printf("%s\n", str[i]);
		strcpy(str_temp, str[i]);
	}
}
