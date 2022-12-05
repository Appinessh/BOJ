#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include<math.h>
int min(double m)
{
	int a;
	a = (int)m;
	if (a == m)
	{
		return a;
	}
	else if(a>m)
	{
		return a;
	}
	else
	{
		return a + 1;
	}
}
int max(double n)
{
	int a;
	a = (int)n;
	if (a == n)
	{
		return a;
	}
	else if (a > n)
	{
		return a-1;
	}
	else
	{
		return a;
	}
}
int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	int i;
	int sum = 0;
	int k = min(sqrt(m));
	if (min(sqrt(m)) > max(sqrt(n)))
	{
		printf("-1");
		return 0;
	}
	for (i = min(sqrt(m)); i <= max(sqrt(n)); i++)
	{
		sum = sum + i * i;
	}
	printf("%d\n", sum);
	printf("%d", k * k);
	return 0;
}