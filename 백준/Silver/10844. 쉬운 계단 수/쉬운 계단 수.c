#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * (10));
	int* next = (int*)malloc(sizeof(int) * (10));
	for (int i = 0; i <= 9; i++)
	{
		array[i] = 1;
		next[i] = 1;
	}
	while (n-1 > 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (i == 1)
			{
				next[i] = array[i + 1]+array[i-1];
			}
			else if (i == 9)
			{
				next[i] = array[i - 1];
			}
			else if (i == 0)
			{
				next[i] = array[i + 1];
			}
			else
			{
				next[i] = array[i - 1] + array[i + 1];
			}
		}
		for (int i = 0; i <= 9; i++)
		{
			array[i] = next[i] % 1000000000;
		}
		n--;
	}
	long long int sum = 0;
	for (int i = 1; i <= 9; i++)
	{
		sum = sum + array[i];
	}
	printf("%lld", sum%1000000000);
	free(array);
	free(next);
	return 0;
}