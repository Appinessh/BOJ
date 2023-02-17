#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	int* dp1 = (int*)malloc(sizeof(int) * n);
	int* dp2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
		dp1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (array[i] > array[j])
			{
				dp1[i] = dp1[i] > (dp1[j] + 1) ? dp1[i] : (dp1[j] + 1);
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		dp2[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if (array[j] < array[i])
			{
				dp2[i] = dp2[i] > (dp2[j] + 1) ? dp2[i] : (dp2[j] + 1);
			}
		}
	}
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		dp1[i] = dp1[i] + dp2[i] - 1;
		max = max > dp1[i] ? max : dp1[i];
	}
	printf("%d", max);
	free(dp1);
	free(dp2);
	free(array);
	return 0;
	
}