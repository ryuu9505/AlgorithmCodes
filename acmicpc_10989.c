#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUM 10000

int main()
{
	int i, j;
	int n, num;
	int count[MAX_NUM + 1];

	scanf("%d", &n);

    for (i = 0; i <= MAX_NUM; i++)
		count[i] = 0;
    
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &num);
        count[num]++;
	}

    for (i = 0; i <= MAX_NUM; i++)
    {
        for(j = 0; j < count[i]; j++)
            printf("%d\n", i);
    }
}
