#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void merge(int list[], int p1, int q1, int p2, int q2)
{
	int pointer1 = p1;
	int pointer2 = p2;
	int i;
	int* array1;
	array1 = (int*)malloc((q1 - p1 + 2) * sizeof(int));
	int* array2;
	array2 = (int*)malloc((q2 - p2 + 2) * sizeof(int));
	for (i = 0; i < q1 - p1 + 1; i++)
	{
		array1[i] = list[pointer1];
		pointer1++;
	}
	array1[i] = INT_MAX;
	for (i = 0; i < q2 - p2 + 1; i++)
	{
		array2[i] = list[pointer2];
		pointer2++;
	}
	array2[i] = INT_MAX;
	pointer1 = 0;
	pointer2 = 0;
	for (i = p1; i <= q2; i++)
	{
		if (array1[pointer1] <= array2[pointer2])
		{
			list[i] = array1[pointer1];
			pointer1++;
		}
		else
		{
			list[i] = array2[pointer2];
			pointer2++;
		}
	}
	free(array1);
	free(array2);
}
void mergesort(int list[], int p, int q)
{
	if (p < q)
	{
		int mid = (p + q) / 2;
		mergesort(list, p, mid);
		mergesort(list, mid + 1, q);
		merge(list, p, mid, mid + 1, q);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array;
	array = (int*)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	mergesort(array, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("%d\n", array[i]);
	}
	free(array);
	return 0;
}