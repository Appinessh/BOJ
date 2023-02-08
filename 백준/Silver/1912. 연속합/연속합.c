#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
int max3(int a, int b, int c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
int from_left(int* array, int start, int end)
{
	int sum = 0;
	int max=INT_MIN;
	for (int i = start; i <= end; i++)
	{
		sum = sum + array[i];
		max = max > sum ? max : sum;
	}
	return max;
}
int from_right(int* array, int start, int end)
{
	int sum = 0;
	int max = INT_MIN;
	for (int i = end; start <= i; i--)
	{
		sum = sum + array[i];
		max = max > sum ? max : sum;
	}
	return max;
}
int cal(int* array, int start, int end)
{
	if (start == end)
	{
		return array[start];
	}
	int mid = (start + end) / 2;
	return max3(cal(array, start, mid), cal(array, mid + 1, end), from_right(array, start, mid) + from_left(array, mid + 1, end));
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int* array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int answer = cal(array, 0, n - 1);
	printf("%d", answer);
	return 0;
}