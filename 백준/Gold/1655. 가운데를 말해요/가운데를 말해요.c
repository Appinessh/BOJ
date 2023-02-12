#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int parent(int i)
{
	if (i == 0)
	{
		return -1;
	}
	else
	{
		return (i - 1) / 2;
	}
}
int left(int i)
{
	return 2 * i + 1;
}
int right(int i)
{
	return 2 * i + 2;
}
int min_heapify(int* array, int size, int index)
{
	int l = left(index);
	int r = right(index);
	int smallest = index;
	if (l <= size - 1 && array[l] < array[index])
	{
		smallest = l;
	}
	if (r <= size - 1 && array[r] < array[smallest])
	{
		smallest = r;
	}
	if (smallest != index)
	{
		int temp = array[index];
		array[index] = array[smallest];
		array[smallest] = temp;
		min_heapify(array, size, smallest);
	}
	return 0;
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
		int temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		max_heapify(array, size, largest);
	}
	return 0;
}
void from_leaf_min(int* array, int size)
{
	int index = size - 1;
	while (parent(index) >= 0 && array[parent(index)] > array[index])
	{
		int temp;
		temp = array[index];
		array[index] = array[parent(index)];
		array[parent(index)] = temp;
		index = parent(index);
	}
}
void from_leaf_max(int* array, int size)
{
	int index = size - 1;
	while (parent(index) >= 0 && array[parent(index)] < array[index])
	{
		int temp;
		temp = array[index];
		array[index] = array[parent(index)];
		array[parent(index)] = temp;
		index = parent(index);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int size = 0;
	int max_heap_size = 0;
	int min_heap_size = 0;
	int* max_heap = (int*)malloc(sizeof(int) * n);
	int* min_heap = (int*)malloc(sizeof(int) * n);
	int* answer = (int*)malloc(sizeof(int) * n);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		size++;
		if (i % 2 == 0)
		{
			scanf("%d", &max_heap[max_heap_size]);
			max_heap_size++;
			from_leaf_max(max_heap, max_heap_size);
			if (i == 0)
			{
				answer[count] = max_heap[0];
				count++;
				continue;
			}
			if (min_heap[0] < max_heap[0])
			{
				int temp;
				temp = max_heap[0];
				max_heap[0] = min_heap[0];
				min_heap[0] = temp;
				min_heapify(min_heap, min_heap_size, 0);
			}
			answer[count] = max_heap[0];
			count++;
		}
		else
		{
			scanf("%d", &min_heap[min_heap_size]);
			min_heap_size++;
			from_leaf_min(min_heap, min_heap_size);
			if (min_heap[0] < max_heap[0])
			{
				int temp;
				temp = max_heap[0];
				max_heap[0] = min_heap[0];
				min_heap[0] = temp;
				max_heapify(max_heap, max_heap_size, 0);
			}
			answer[count] = max_heap[0];
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", answer[i]);
	}
	free(min_heap);
	free(max_heap);
	free(answer);
	return 0;
}