#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int parent(int i)
{
	return (i - 1) / 2;
}
int left(int i)
{
	return 2 * i + 1;
}
int right(int i)
{
	return 2 * i + 2;
}
int max_heapify(int* array, int size, int index)
{
	int l = left(index);
	int r = right(index);
	int largest = index;
	if (l <= size - 1 && array[l] > array[index])
	{
		largest = l;
	}
	if (r <= size - 1 && array[r] > array[largest])
	{
		largest = r;
	}
	if (largest != index)
	{
		int temp;
		temp = array[largest];
		array[largest] = array[index];
		array[index] = temp;
		max_heapify(array, size, largest);
	}
	return 0;
}
int build_max_heap(int* array, int size)
{
	for (int i = size / 2; 0 <= i; i--)
	{
		max_heapify(array, size, i);
	}
	return 0;
}
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int* present = (int*)malloc(sizeof(int) * n);
	int* child = (int*)malloc(sizeof(int) * m);
	int success = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &present[i]);
	}
	build_max_heap(present, n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &child[i]);
	}
	for (int i = 0; i < m; i++)
	{
		if (child[i] < present[0])
		{
			present[0] = present[0] - child[i];
			max_heapify(present, n, 0);
		}
		else if (child[i] == present[0])
		{
			present[0] = present[n - 1];
			n--;
			max_heapify(present, n, 0);
		}
		else
		{
			success = 0;
			break;
		}
	}
	printf("%d", success);
	free(present);
	free(child);
	return 0;
}