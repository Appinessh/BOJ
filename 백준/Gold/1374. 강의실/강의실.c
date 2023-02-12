#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct lec {
	int start;
	int end;
}lec;
int parent(int i)
{
	if (i == 0)
	{
		return -1;
	}
	return(i - 1) / 2;
}
int left(int i)
{
	return 2 * i + 1;
}
int right(int i)
{
	return 2 * i + 2;
}
int min_heapify(lec* array, int size, int index)
{
	int l = left(index);
	int r = right(index);
	int smallest = index;
	if (l <= size - 1 && array[l].start < array[index].start)
	{
		smallest = l;
	}
	if (r <= size - 1 && array[r].start < array[smallest].start)
	{
		smallest = r;
	}
	if (smallest != index)
	{
		lec temp = array[index];
		array[index] = array[smallest];
		array[smallest] = temp;
		min_heapify(array, size, smallest);
	}
	return 0;
}
void build_min_heap(lec* array, int size)
{
	for (int i = size / 2; i >= 0; i--)
	{
		min_heapify(array, size,i);
	}
}
int min_heapify_int(int* array, int size, int index)
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
		min_heapify_int(array, size, smallest);
	}
	return 0;
}
void build_min_heap_int(int* array, int size)
{
	for (int i = size / 2; i >= 0; i--)
	{
		min_heapify_int(array, size, i);
	}
}
void from_leaf_node(int* array, int size)
{
	int index = size - 1;
	while (parent(index) >= 0 && array[parent(index)] >= array[index])
	{
		int temp;
		temp = array[parent(index)];
		array[parent(index)] = array[index];
		array[index] = temp;
		index = parent(index);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	lec* input = (lec*)malloc(sizeof(lec) * n);
	int* end_time = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d%d%d", &temp, &input[i].start, &input[i].end);
	}
	build_min_heap(input, n);
	int input_size = n;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (count == 0)
		{
			end_time[0] = input[i].end;
			input[i] = input[input_size - 1];
			input_size--;
			min_heapify(input, input_size, 0);
			count++;
		}
		else if(end_time[0]<=input[0].start)
		{
			int min = INT_MAX;
			int marker;
			int index = 0;
			while (right(index) < count && end_time[right(index)] <= input[0].start)
			{
				index = right(index);
			}
			for (int j = index; j < right(index); j++)
			{
				if (end_time[j] <= input[0].start)
				{
					min = min < (input[0].start - end_time[j]) ? min : (input[0].start - end_time[j]);
				}
				if (min == input[0].start - end_time[j])
				{
					marker = j;
				}
			}
			end_time[marker] = input[0].end;
			min_heapify_int(end_time, count, marker);
			input[0] = input[input_size - 1];
			input_size--;
			min_heapify(input, input_size, 0);
		}
		else
		{
			end_time[count] = input[0].end;
			count++;
			from_leaf_node(end_time, count);
			input[0] = input[input_size - 1];
			input_size--;
			min_heapify(input, input_size, 0);
		}
	}
	printf("%d", count);
	free(end_time);
	free(input);
	return 0;
}