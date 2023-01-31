#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int main(void)
{
	int n, s;
	scanf("%d%d", &n, &s);
	int* array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int pointer1 = 0, pointer2 = 0;
	int length = INT_MAX;
	int sum = array[pointer1];
	int index1, index2;
	int temp;
	while (0 <= pointer1 && pointer2 <= n - 1&&pointer1<=pointer2)
	{
		if (sum < s)
		{
			pointer2++;
			temp = array[pointer2];
		}
		else
		{
			temp = -array[pointer1];
			length = length < (pointer2 - pointer1 + 1) ? length : (pointer2 - pointer1 + 1);
			pointer1++;
		}
		sum = sum + temp;
	}
	if (length == INT_MAX)
	{
		printf("0");
	}
	else
	{
		printf("%d", length);
	}
	return 0;
}