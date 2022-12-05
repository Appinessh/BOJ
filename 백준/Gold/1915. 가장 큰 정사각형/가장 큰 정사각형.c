#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int min(int a, int b, int c)
{
	return (a < b ? a:b)<c ? (a < b ? a : b):c;
}
int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, m;
	int i, j;
	scanf("%d%d", &n, &m);
	int array[1001][1001] = { 0, };
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%1d", &array[i][j]);
		}
	}
	int k = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (array[i][j] != 0)
			{
				array[i][j] = min(array[i - 1][j], array[i][j - 1], array[i - 1][j - 1])+1;
				k = max(k, array[i][j]);
			}
		}
	}
	printf("%d", k*k);
	return 0;
}