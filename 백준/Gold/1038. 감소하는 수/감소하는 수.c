#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	n = n + 1;
	if (n > 1023)
	{
		printf("-1");
		return 0;
	}
	if (n <= 10)
	{
		printf("%d", n - 1);
		return 0;
	}
	int sum[11][10] = { 0, };
	int count[11][10] = { 0, };
	int row[11][10] = { 0, };
	int i, j;
	int a=0, b=0;
	for (i = 0; i < 11; i++)
	{
		count[1][i] = 1;
		sum[1][i] = i + 1;
		row[1][i] = i + 1;
	}
	for (i = 2; i < 11; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				count[i][j] = 0;
				sum[i][j] = sum[i - 1][9] + count[i][j];
				row[i][j] = 0;
			}
			else
			{
				count[i][j] = count[i][j - 1] + count[i - 1][j - 1];
				sum[i][j] = sum[i][j - 1] + count[i][j];
				row[i][j] = count[i][j] + row[i][j - 1];
			}
			if(sum[i][j]>=n)
			{
				break;
			}
		}
		if (sum[i][j] >= n)
		{
			a = i;
			b = j;
			printf("%d", b);
			n = n - sum[a][b - 1];
			break;
		}
	}
	a--;
	while (1)
	{
		if (a == 0)
		{
			break;
		}
		for (i = 0; i < 10; i++)
		{
			if (n <= row[a][i])
			{
				b = i;
				break;
			}
		}
		printf("%d", b);
		n = n - row[a][b - 1];
		a--;
	}
	return 0;
}