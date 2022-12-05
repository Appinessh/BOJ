#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int maxarray(int array[1500], int n)
{
	int i;
	int M = INT_MIN;
	int index = 0;
	for (i = 0; i < n; i++)
	{
		M = max(M, array[i]);
		if (M == array[i])
		{
			index = i;
		}
	}
	return index;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i, j;
	int array[1500][1500];
	int last[1500];
	int coordinates[1500];

	for (j = 0; j < n; j++)
	{
		coordinates[j] = n - 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &array[i][j]);
			if (i == n - 1)
			{
				last[j] = array[i][j];
			}
		}
	}
	int count = 0;
	int ans;
	while (count <= n-1)
	{
		count++;
		ans = last[maxarray(last, n)];
		coordinates[maxarray(last, n)]= coordinates[maxarray(last, n)]-1;
		last[maxarray(last, n)] = array[coordinates[maxarray(last, n)]][maxarray(last,n)];
	}
	printf("%d", ans);
}