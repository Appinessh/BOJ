#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 > num2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	qsort(array, n, sizeof(int), compare);
	int pointer1=0, pointer2=n-1;
	int sum;
	int index1, index2;
	int close = INT_MAX;
	while (pointer1 < pointer2)
	{
		sum = array[pointer1] + array[pointer2];
		if (sum < 0)
		{
			if (abs(sum) < abs(close))
			{
				close = sum;
				index1 = pointer1;
				index2 = pointer2;
			}
			pointer1++;
		}
		else if (sum > 0)
		{
			if (abs(sum) < abs(close))
			{
				close = sum;
				index1 = pointer1;
				index2 = pointer2;
			}
			pointer2--;
		}
		else
		{
			printf("%d %d", array[pointer1], array[pointer2]);
			return 0;
		}
	}
	printf("%d %d", array[index1], array[index2]);
	return 0;
}