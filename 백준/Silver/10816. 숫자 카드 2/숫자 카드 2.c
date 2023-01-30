#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int upper_bound(int* array, int left, int right, int val)
{
	int mid;
	int ans = -1;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (array[mid] < val)
		{
			left = mid + 1;
		}
		else if(array[mid]==val)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ans;
}
int lower_bound(int* array, int left, int right, int val)
{
	int mid;
	int ans = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (array[mid] < val)
		{
			left = mid + 1;
		}
		else if (array[mid] == val)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ans;
}
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
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int m;
	scanf("%d", &m);
	int* list = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &list[i]);
	}
	qsort(array, n, sizeof(int), compare);
	for (i = 0; i < m; i++)
	{
		if (upper_bound(array, 0, n - 1, list[i]) == -1)
		{
			printf("0 ");
		}
		else
		{
			printf("%d ", upper_bound(array, 0, n - 1, list[i]) - lower_bound(array, 0, n - 1, list[i]) + 1);
		}
	}
	return 0;
}