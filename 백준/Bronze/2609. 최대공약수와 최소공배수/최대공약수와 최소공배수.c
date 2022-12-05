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
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a, b;
	a = ceiling(sqrt(n));
	b = ceiling(sqrt(m));
	int n1[101] = { 0, };
	int m1[101] = { 0, };
	int MIN[101] = { 0, };
	int MAX[101] = { 0, };
	int i, j;
	int ans1 = 1, ans2 = 1;
	for (i = 2; i <= a; i++)
	{
		while (n % i == 0)
		{
			n1[i]++;
			n = n / i;
		}
	}
	if (n <= 100)
	{
		n1[n]++;
		ans1 = 1;
		ans2 = 1;
	}
	else
	{
		ans1 = 1;
		ans2 = n;
	}
	for (j = 2; j <= b; j++)
	{
		while (m % j == 0)
		{
			m1[j]++;
			m = m / j;
		}
	}
	if (m <= 100)
	{
		m1[m]++;
	}
	else
	{
		if (n == m)
		{
			ans1 = n;
			ans2 = n;
		}
		else
		{
			ans2 = ans2 * m;
		}
	}
	for (i = 1; i <= 100; i++)
	{
		if (n1[i] >= m1[i])
		{
			MIN[i] = m1[i];
			MAX[i] = n1[i];
		}
		else
		{
			MIN[i] = n1[i];
			MAX[i] = m1[i];
		}
	}
	for (i = 1; i <= 100; i++)
	{
		ans1 = ans1 * (int)pow(i, MIN[i]);
		ans2 = ans2 * (int)pow(i, MAX[i]);
	}
	printf("%d\n%d", ans1, ans2);
	return 0;
}