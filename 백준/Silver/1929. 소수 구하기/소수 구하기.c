#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	int p = (int)(sqrt(n));
	int list[1000];
	list[0] = 2;
	int i,count=1;
	int j;
	for (i = 3; i <= p ; i++)
	{
		for (j = 0; j < count; j++)
		{
			if (i % list[j] == 0)
			{
				break;
			}
			if (j == count - 1)
			{
				list[count] = i;
				count++;
				break;
			}
		}
	}
	if (m == 1)
	{
		m = m + 1;
	}
	for (i = m; i < n + 1; i++)
	{
		for (j = 0; j < count; j++)
		{
			if (i == list[j])
			{
				printf("%d\n", i);
				break;
			}
			if (i % list[j] == 0)
			{
				break;
			}
			if (j == count - 1)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}