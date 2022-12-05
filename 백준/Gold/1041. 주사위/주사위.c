#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<limits.h>
long long int max(long long int a, long long int b)
{
	return a > b ? a : b;
}
long long int min(long long int a, long long int b)
{
	return a < b ? a : b;
}
int main(void)
{
	long long int n;
	long long int a[6];
	scanf("%lld", &n);
	scanf("%lld%lld%lld%lld%lld%lld", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
	int i;
	long long int k;
	long long int sum = 0;
	if (n == 1)
	{
		k = INT_MIN;
		for (i = 0; i < 6; i++)
		{
			k = max(k, a[i]);
			sum = sum + a[i];
		}
		printf("%lld", sum - k);
		return 0;
	}
	k = INT_MAX;
	for (i = 0; i < 6; i++)
	{
		k = min(k, a[i]);
	}
	i = 0;
	int j;
	long long int l=INT_MAX;

	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 6; j++)
		{
			if (i + j == 5)
			{
				continue;
			}
			l = min(l, a[i] + a[j]);
		}
	}

	long long int m1,m2,m3,m4;
	m1 = min(a[0] + a[1] + a[2], a[5] + a[1] + a[2]);
	m2 = min(a[0] + a[1] + a[3], a[5] + a[1] + a[3]);
	m3 = min(a[0] + a[3] + a[4], a[5] + a[3] + a[4]);
	m4 = min(a[0] + a[2] + a[4], a[5] + a[2] + a[4]);
	long long int m5, m6, m;
	m5 = min(m1, m2);
	m6 = min(m3, m4);
	m = min(m5, m6);
	sum = (5 * (n - 2) * (n - 2) + 4 * (n - 2)) * k + (4 * (n - 2) + 4 * (n - 1)) * l + 4 * m;
	printf("%lld", sum);
}