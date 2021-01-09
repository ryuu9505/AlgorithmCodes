#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100000
#define MAX_LENGTH 100

int age_sorted[MAX_SIZE];
char name_sorted[MAX_SIZE][MAX_LENGTH + 1];

void merge(int age[], char name[][MAX_LENGTH + 1], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	// 중간을 기준으로 두개의 배열로 나누고 각 원소 값들을 하나씩 비교해 가며 임시 배열로 정렬
	while (i <= mid && j <= right) // 하나의 배열의 원소가 모두 정렬될 때까지
	{
		if (age[i] <= age[j])
		{
			age_sorted[k] = age[i];
			strcpy(name_sorted[k], name[i]);
			i++; k++;
		}
		else
		{
			age_sorted[k] = age[j];
			strcpy(name_sorted[k], name[j]);
			j++; k++;
		}
	}

	// 남은 배열의 원소들은 임시 배열로 그대로 옮기기
	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			age_sorted[k] = age[l];
			strcpy(name_sorted[k], name[l]);
			k++;
		}
	}
	else
	{
		for (l = i; l <= mid; l++)
		{
			age_sorted[k] = age[l];
			strcpy(name_sorted[k], name[l]);
			k++;
		}
	}

	// 임시 배열에서 배열로 옮기기
	for (l = left; l <= right; l++)
	{
		age[l] = age_sorted[l];
		strcpy(name[l], name_sorted[l]);
	}
}

void merge_sort(int age[], char name[][MAX_LENGTH + 1], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; // Divide
		merge_sort(age, name, left, mid); // Conquer
		merge_sort(age, name, mid + 1, right); // Conquer
		merge(age, name, left, mid, right); // Combine
	}
}

int main()
{
	int i, n;
	char name[MAX_SIZE][MAX_LENGTH + 1];
	int age[MAX_SIZE];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d %s", &age[i], &name[i]);

	merge_sort(age, name, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d %s\n", age[i], name[i]);
}
