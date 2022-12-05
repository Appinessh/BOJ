#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int merge(int a[1000], int s1, int e1, int s2, int e2)
{
	int b[501];
	int c[501];
	int i, j;
	for (i = 0; i < e1 - s1 + 1; i++)
	{
		b[i] = a[i + s1];
	}
	b[i] = INT_MAX;
	for (j = 0; j < e2 - s2 +1 ; j++)
	{
		c[j] = a[j + s2];
	}
	c[j] = INT_MAX;
	int k;
	i = 0, j = 0;
	for (k = s1; k < e2 + 1; k++)
	{
		if (b[i] <= c[j])
		{
			a[k] = b[i];
			i++;
		}
		else
		{
			a[k] = c[j];
			j++;
		}
	}
}
int mergesort(int a[1000],int s, int e)
{
	if (s == e)
	{
		return 0;
	}
	mergesort(a, s, s + (e-s+1) / 2 - 1);
	mergesort(a,s + (e-s+1) / 2, e);
	merge(a, s, s + (e-s+1) / 2 - 1, s + (e-s+1) / 2, e);
	return 0;
}
int main(void)
{
	int n;
	int a[1000];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	mergesort(a, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}