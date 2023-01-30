#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int result(int* dis, int* pri, int n)
{
	int min;
	min = INT_MAX;
	int* indicator = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		indicator[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (pri[i] <= min)
		{
			indicator[i] = 1;
			min = pri[i];
		}
	}
	int start=0, end;
	int sum;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (indicator[i] == 1)
		{
			end = i;
			sum = 0;
			for (int j = start; j < end; j++)
			{
				sum = sum + dis[j];
			}
			ans = ans + sum * pri[start];
			start = i;
		}
	}
	return ans;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* distance = (int*)malloc(sizeof(int) * (n - 1));
	int* price = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d", &distance[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &price[i]);
	}
	printf("%d", result(distance, price, n));
	return 0;
}