#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	return 2*i + 2;
}
int max_heapify(int* array, int index, int size)
{
	int l = left(index);
	int r = right(index);
	int largest=index;
	if (array[l] > array[index]&&l<=size-1)
	{
		largest = l;
	}
	if (array[r] > array[largest]&&r<=size-1)
	{
		largest = r;
	}
	if (largest != index)
	{
		int temp;
		temp = array[largest];
		array[largest] = array[index];
		array[index] = temp;
		max_heapify(array, largest, size);
	}
	return 0;
}
int build_max_heap(int* array, int size)
{
	for (int i = size / 2 + 1; 0 <= i; i--)
	{
		max_heapify(array, i, size);
	}
	return 0;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	int* answer = (int*)malloc(sizeof(int) * n);
	int size = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp == 0)
		{
			if (size == 0)
			{
				answer[count] = 0;
			}
			else
			{
				answer[count] = array[0];
				array[0] = array[size - 1];
				size--;
				max_heapify(array, 0, size);
			}
			count++;
		}
		else
		{
			array[size] = temp;
			int index = size;
			size++;
			while (parent(index) >= 0&&array[index]>array[parent(index)])
			{
				int a;
				a = array[index];
				array[index] = array[parent(index)];
				array[parent(index)] = a;
				index = parent(index);
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", answer[i]);
	}
	free(array);
	free(answer);
	return 0;
}