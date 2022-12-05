#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include<math.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int a[10001] = {0,};
	int i,j;
	int b;
	int M = INT_MIN;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b);
		a[b]++;
		M = max(M, b);
	}
	for (i = 1; i <= M; i++)
	{
		for (j = 0; j < a[i]; j++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}