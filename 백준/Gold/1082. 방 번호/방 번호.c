#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int min(int a, int b)
{
	return a < b ? a : b;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int cost[10];
	int iter[10] = {0,};
	int i,j;
	int m = 1000;
	int index;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &cost[i]);
		if (i >= 1)
		{
			m = min(m, cost[i]);
			if (cost[i] - m == 0)
			{
				index = i;
			}
		}
	}
	int total;
	int k,l;
	int count=n-1;
	scanf("%d", &total);
	if (n == 1)
	{
		if (total >= cost[0])
		{
			printf("0");
		}
		return 0;
	}
	if (total < m)
	{
		if (total >= cost[0])
		{
			printf("0");
		}
		return 0;
	}
	if (m <= cost[0])
	{
		k = total / m;
		l = total % m;
		iter[index] = k;
		while (1)
		{
			if (count == index)
			{
				break;
			}
			if (l >= cost[count] - m)
			{
				iter[index]--;
				iter[count]++;
				l = l - cost[count] + m;
			}
			else
			{
				count--;
			}
		}
		for (i = n-1; i >= 0; i--)
		{
			for (j = 0; j < iter[i]; j++)
			{
				printf("%d", i);
			}
		}
	}
	else
	{
		k = total / cost[0];
		l = total % cost[0];
		iter[0] = k;
		while (1)
		{
			if (l >= m - cost[0])
			{
				break;
			}
			else
			{
				l = l + cost[0];
				iter[0]--;
				k--;
			}
		}
		while (1)
		{
			if (count == index-1)
			{
				break;
			}
			if (l >= cost[count] - cost[0])
			{
				iter[count]++;
				iter[0]--;
				l = l - cost[count] + cost[0];
			}
			else
			{
				count--;
			}
		}
		for (i = n-1; i >= 0; i--)
		{
			for (j = 0; j < iter[i]; j++)
			{
				printf("%d", i);
			}
		}
	}
	return 0;
}