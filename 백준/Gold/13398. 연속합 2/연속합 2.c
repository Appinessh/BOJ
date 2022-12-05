#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int max(int a, int b, int c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}

int LM(int k, int l, int a[100000])
{
	int i = l;
	int sum = 0;
	int  M = 0;
	for (i = l; i >= k; i--)
	{
		sum = sum + a[i];
		M = sum > M ? sum : M;
	}
	return M;
}
int RM(int k, int l, int a[100000])
{
	int i = k;
	int sum = 0;
	int  M = 0;
	for (i = k; i <= l; i++)
	{
		sum = sum + a[i];
		M = sum > M ? sum : M;
	}
	return M;
}
int LM1(int k, int l, int a[100000])
{
	int i = l;
	int sum = 0;
	int  M = 0;
	int min = 0;
	for (i = l; i >= k; i--)
	{
		sum = sum + min;
		min = min < a[i] ? min : a[i];
		sum = sum + a[i]-min;
		M = sum > M ? sum : M;

	}
	return M;
}
int RM1(int k, int l, int a[100000])
{
	int i = k;
	int sum = 0;
	int  M = 0;
	int min = 0;
	for (i = k; i <= l; i++)
	{
		sum = sum + min;
		min = min<a[i] ? min : a[i];
		sum = sum + a[i]-min;
		M = sum > M ? sum : M;
	}
	return M;
}
int M(int k, int l, int a[100000])
{
	int b;
	if (k == l)
	{
		return a[k];
	}
	else
	{
		b=max(M(k, k + (l - k + 1) / 2 - 1, a), LM(k, k + (l - k + 1) / 2 - 1, a) + RM(k + (l - k + 1) / 2, l, a), M(k + (l - k + 1) / 2, l, a));
		b = max(b, LM1(k, k + (l - k + 1) / 2 - 1, a) + RM(k + (l - k + 1) / 2, l, a), LM(k, k + (l - k + 1) / 2 - 1, a) + RM1(k + (l - k + 1) / 2, l, a));
		return b;
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	int a[100000] = { 0, };
	int count=0;
	int MAX=INT_MIN;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] <= 0)
		{
			count++;
		}
		MAX = MAX > a[i] ? MAX : a[i];
	}
	if (count == n)
	{
		printf("%d", MAX);
		return 0;
	}
	printf("%d", M(0, n - 1, a));
	return 0;
}