#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long long int result(long long int* array, int m,int size)
{
	long long int mid;
	long long int sum;
	long long int max_cut;
	long long int left = 1, right = array[size - 1];
	while (left<=right)
	{
		sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < size; i++)
		{
			sum = sum + array[i] / mid;
		}
		if (sum < m)
		{
			right = mid-1;
		}
		else
		{
			max_cut =mid;
			left = mid+1;
		}
	}
	return max_cut;
}
int compare(const void* a, const void* b)
{
	long long int num1 = *(long long int*)a;
	long long int num2 = *(long long int*)b;
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
	int n, m;
	scanf("%d%d", &n, &m);
	long long int* array = (long long int*)malloc(sizeof(long long int) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &array[i]);
	}
	qsort(array, n, sizeof(long long int), compare);
	printf("%lld", result(array, m, n));
	return 0;
}