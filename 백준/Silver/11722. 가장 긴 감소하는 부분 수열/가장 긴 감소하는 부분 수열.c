#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int* dp = (int*)malloc(sizeof(int) * n);
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (array[j] > array[i])
			{
				dp[i] = (dp[j] + 1) > (dp[i]) ? (dp[j] + 1) : (dp[i]);
			}
		}
	}
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		max = max > dp[i] ? max : dp[i];
	}
	printf("%d", max);
	return 0;
}