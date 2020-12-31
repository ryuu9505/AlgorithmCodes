#include <stdio.h>
#include <math.h>

// Tower of Hanoi
void Hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		printf("%d %d\n", from, to);
	}
	else
	{
		Hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		Hanoi(n - 1, by, from, to);
	}
}

int main()
{
	int n, k;
	scanf("%d", &n);
	k = pow(2, n) - 1;
	printf("%d\n", k);
	Hanoi(n, 1, 2, 3);

	return 0;
}
