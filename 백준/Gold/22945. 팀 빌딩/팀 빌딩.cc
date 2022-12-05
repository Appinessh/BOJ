#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minfc(int a, int b)
{
	return a < b ? a : b;
}
int maxfc(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array;
	array = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int j;
	int max = INT_MIN;
	int pointer1 = 0;
	int pointer2 = n - 1;
	while (pointer1 != pointer2)
	{
		max = maxfc(max, (pointer2 - pointer1 - 1) * minfc(array[pointer1], array[pointer2]));
		if (minfc(array[pointer1], array[pointer2]) == array[pointer1])
		{
			pointer1++;
		}
		else
		{
			pointer2--;
		}
	}
	printf("%d", max);
	free(array);
	return 0;
}