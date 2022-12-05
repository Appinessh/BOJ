#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int cmp(int a, int b)
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
	for (i = 0; i < r - q; i++)
	{
		array2[i] = array[i + q + 1];
	}
	array2[i] = INT_MAX;
	int pointer1 = 0;
	int pointer2 = 0;
	for (i = 0; i < r - p + 1; i++)
	{
		if (array1[pointer1] <= array2[pointer2])
		{
			array[p + i] = array1[pointer1];
			pointer1++;
		}
		else
		{
			array[p + i] = array2[pointer2];
			pointer2++;
		}
	}
	free(array1);
	free(array2);
}
void  mergesort(int array[], int p, int q)
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
	array = (int*)malloc(n * sizeof(int));
	int i;
	double sum=0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
		sum = sum + array[i];
	}
	mergesort(array, 0, n - 1);
	int answ1 = round(sum/n);
	printf("%d\n", answ1);
	int answ2 = array[n / 2];
	printf("%d\n", answ2);
	int answ4 = array[n - 1] - array[0];
	int answ3, count=0;
	int** answer3;
	answer3 = (int**)malloc(sizeof(int*) * 2);
	answer3[0]=(int*)malloc(sizeof(int) * n);
	answer3[1] = (int*)malloc(sizeof(int) * n);
	answer3[0][0] = array[0];
	answer3[1][0] = 0;
	int max = INT_MIN;
	for (i = 0; i < n; i++)
	{
		if (array[i] == answer3[0][count])
		{
			answer3[1][count]++;
		}
		else
		{
			count++;
			answer3[0][count] = array[i];
			answer3[1][count] = 1;
		}
	}
	int indicator = 0;
	int index;
	for (i = 0; i <= count; i++)
	{
		if (answer3[1][i] > max)
		{
			max = answer3[1][i];
			indicator = 1;
			index = i;
		}
		else if(answer3[1][i] == max && indicator==1)
		{
			index = i;
			indicator = 2;
		}
		else if (answer3[1][i] == max && indicator == 2)
		{
			continue;
		}
		else
		{
			continue;
		}
	}
	answ3 = answer3[0][index];
	printf("%d\n%d\n", answ3, answ4);
	free(array);
	free(answer3);
	return 0;
}