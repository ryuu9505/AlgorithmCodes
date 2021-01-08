#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 500000
#define MAX_NUM 4000

int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	// 중간을 기준으로 두개의 배열로 나누고 각 원소 값들을 하나씩 비교해 가며 임시 배열로 정렬
	while (i <= mid && j <= right) // 하나의 배열의 원소가 모두 정렬될 때까지
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남은 배열의 원소들은 임시 배열로 그대로 옮기기
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// 임시 배열에서 배열로 옮기기
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
}

void merge_sort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; // Divide
		merge_sort(list, left, mid); // Conquer
		merge_sort(list, mid + 1, right); // Conquer
		merge(list, left, mid, right); // Combine
	}
}

int main()
{
	int i, n, tied = 0, max = 0, idx = 0;
	double sum = 0;
	//int list[MAX_SIZE];
	int count[MAX_NUM * 2 + 1];


	scanf("%d", &n);
	int* list = malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	for (i = 0; i <= MAX_NUM * 2; i++)
		count[i] = 0;

	for (i = 0; i < n; i++)
		count[list[i] + MAX_NUM]++;

	for (i = 0; i < n; i++)
		sum += list[i];
	printf("%.0lf\n", sum / n);

	merge_sort(list, 0, n - 1);

	printf("%d\n", list[n / 2]);

	for (i = 0; i <= MAX_NUM * 2; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
			idx = i;
			tied = 0;
		}
		else if (count[i] == max && tied == 0)
		{
			max = count[i];
			idx = i;
			tied = 1;
		}
	}

	printf("%d\n", idx - 4000);

	printf("%d\n", list[n - 1] - list[0]);
	free(list);
}
