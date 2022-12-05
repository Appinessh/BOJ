#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include<math.h>
int mergesort(int a[10], int s, int e)
{
	if (s == e)
	{
		return 0;
	}
	mergesort(a, s, s + (e - s + 1) / 2 - 1);
	mergesort(a, s + (e - s + 1) / 2, e);
	merge(a, s, s + (e - s + 1) / 2 - 1, s + (e - s + 1) / 2, e);
	return 0;
}
int merge(int a[10], int s1, int e1, int s2, int e2)
{
	int b1[6];
	int b2[6];
	b1[5] = INT_MAX;
	b2[5] = INT_MAX;
	int i,j;
	for (i = s1; i <= e1; i++)
	{
		b1[i - s1] = a[i];
	}
	b1[i-s1] = INT_MAX;
	for (j = s2; j <= e2; j++)
	{
		b2[j - s2] = a[j];
	}
	b2[j-s2] = INT_MAX;
	int k;
	i = 0;
	j = 0;
	for (k = s1; k <= e2; k++)
	{
		if (b1[i] <= b2[j])
		{
			a[k] = b1[i];
			i++;
		}
		else
		{
			a[k] = b2[j];
			j++;
		}
	}
	return 0;
}
int main(void)
{
	int T;
	scanf("%d", &T);
	int a[1000][10];
	int i;
	int j;
	for (j = 0; j < T; j++)
	{
		for (i = 0; i < 10; i++)
		{
			scanf("%d", &a[j][i]);
		}
	}
	int b[10];
	for (i = 0; i < T; i++)
	{
		for (j = 0; j < 10; j++)
		{
			b[j] = a[i][j];
		}
		mergesort(b, 0, 9);
		printf("%d\n", b[7]);
	}
	return 0;
}