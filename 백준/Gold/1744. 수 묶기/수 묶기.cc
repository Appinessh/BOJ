#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int maxfc(int a, int b)
{
	return a > b ? a : b;
}
void merge(int array[], int p, int q, int r)
{
	int* array1;
	int* array2;
	array1 = (int*)malloc(sizeof(int) * (q - p + 2));
	array2 = (int*)malloc(sizeof(int) * (r - q + 1));
	int i;
	for (i = 0; i < q - p + 1; i++)
	{
		array1[i] = array[i + p];
	}
	array1[i] = INT_MAX;
	for (i = 0; i < r-q; i++)
	{
		array2[i] = array[i + q+1];
	}
	array2[i] = INT_MAX;
	int pointer1 = 0, pointer2 = 0;
	for (i = 0; i < r - p + 1; i++)
	{
		if (array1[pointer1] <= array2[pointer2])
		{
			array[i + p] = array1[pointer1];
			pointer1++;
		}
		else
		{
			array[i + p] = array2[pointer2];
			pointer2++;
		}
	}
	free(array1);
	free(array2);
}
void mergesort(int array[], int p, int q)
{
	if (p < q)
	{
		int mid = (p + q) / 2;
		mergesort(array, p, mid);
		mergesort(array, mid + 1, q);
		merge(array, p, mid, q);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array;
	array = (int*)malloc(sizeof(int) * n);
	int i;
	int count = 0;
	int indicator = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
		if (array[i] < 0)
		{
			count++;
		}
		if (array[i] == 0)
		{
			indicator++;
		}
	}
	mergesort(array, 0, n - 1);
	int answer = 0;
	for (i = 0; i < count-1; i = i + 2)
	{
		answer = answer + array[i] * array[i + 1];
	}
	if (count % 2 == 0&&count!=0)
	{

	}
	else
	{
		if (count != 0)
		{
			if (indicator != 0)
			{
				answer = answer;
			}
			else
			{
				answer = answer + array[i];
			}
		}
	}




	for (i = n - 1; i - 1 > count + indicator - 1; i = i - 2)
	{
		answer = answer + maxfc(array[i] + array[i - 1], array[i] * array[i - 1]);
	}
	if (i == count + indicator)
	{
		answer = answer + array[count + indicator];
	}
	printf("%d", answer);
	free(array);
	return 0;
}