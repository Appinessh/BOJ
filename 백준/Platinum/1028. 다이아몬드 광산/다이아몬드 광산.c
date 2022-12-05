#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int array[752][752][3] = { 0, };
	int R, C;
	scanf("%d%d", &R, &C);
	int i, j;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			scanf("%1d", &array[i][j][0]);
		}
	}
	int k;
	int m=0;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (array[i][j][0] != 0)
			{
				array[i][j][1] = array[i - 1][j-1][1] + 1;
				array[i][j][2] = array[i-1][j+1][2] + 1;
				k = min(array[i][j][1], array[i][j][2]);
				while (k>m)
				{
					if (array[i - k + 1][j - k + 1][2] >= k && array[i - k + 1][j + k - 1][1] >= k)
					{
						m = max(m, k);
					}
					k--;
				}
			}
		}
	}
	printf("%d", m);
}