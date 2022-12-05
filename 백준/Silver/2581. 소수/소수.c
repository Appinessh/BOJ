#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include<math.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int ceiling(double a)
{
	int n;
	n = (int)a;
	if (n >= a)
	{
		return n;
	}
	else
	{
		return n + 1;
	}
}
int ground(double a)
{
	int n;
	n = (int)a;
	if (n > a)
	{
		return n - 1;
	}
	else
	{
		return n;
	}
}
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i,j;
	int a[10000];
	int min;
	int sum = 0;
	int count=0;
	for (j = n; j <= m; j++)
	{
		if (ground(sqrt(j)) == 1 && j != 1)
		{
			sum = sum + j;
			count++;
			if (count == 1)
			{
				min = j;
			}
		}
		for (i = 2; i <= ground(sqrt(j));i++)
		{
			if (j % i == 0)
			{
				break;
			}
			else if (i==ground(sqrt(j)))
			{
				sum = sum + j;
				count++;
				if (count == 1)
				{
					min = j;
				}
			}
		}
	}
	if (count == 0)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n", sum);
	printf("%d", min);
	return 0;
}