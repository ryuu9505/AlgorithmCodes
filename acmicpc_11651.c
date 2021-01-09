#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100000

int x_sorted[MAX_SIZE];
int y_sorted[MAX_SIZE];

void merge(int x[], int y[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	// 중간을 기준으로 두개의 배열로 나누고 각 원소 값들을 하나씩 비교해 가며 임시 배열로 정렬
	while (i <= mid && j <= right) // 하나의 배열의 원소가 모두 정렬될 때까지
	{
		if (x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]))
		{
			x_sorted[k] = x[i];
			y_sorted[k] = y[i];
			i++; k++;
		}
		else
		{
			x_sorted[k] = x[j];
			y_sorted[k] = y[j];
			j++; k++;
		}
	}

	// 남은 배열의 원소들은 임시 배열로 그대로 옮기기
	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			x_sorted[k] = x[l];
			y_sorted[k] = y[l];
			k++;
		}
	}
	else
	{
		for (l = i; l <= mid; l++)
		{
			x_sorted[k] = x[l];
			y_sorted[k] = y[l];
			k++;
		}
	}

	// 임시 배열에서 배열로 옮기기
	for (l = left; l <= right; l++)
	{
		x[l] = x_sorted[l];
		y[l] = y_sorted[l];
	}
}

void merge_sort(int x[], int y[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; // Divide
		merge_sort(x, y, left, mid); // Conquer
		merge_sort(x, y, mid + 1, right); // Conquer
		merge(x, y, left, mid, right); // Combine
	}
}

int main()
{
	int i, n, size;
	int x[MAX_SIZE];
	int y[MAX_SIZE];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);

	merge_sort(y, x, 0, n-1); // 11650에서 y, x 자리만 바꿈

	for (i = 0; i < n; i++)
		printf("%d %d\n", x[i], y[i]);
}
