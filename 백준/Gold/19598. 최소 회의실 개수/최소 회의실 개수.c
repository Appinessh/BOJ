#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct lec {
	int start;
	int end;
}lec;
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
int min_heapify(lec* input, int size, int index)
{
	int l = left(index);
	int r = right(index);
	int smallest = index;
	if (l <= size - 1 && input[l].start < input[index].start)
	{
		smallest = l;
	}
	if (r <= size - 1 && input[r].start < input[smallest].start)
	{
		smallest = r;
	}
	if (smallest != index)
	{
		lec temp;
		temp = input[index];
		input[index] = input[smallest];
		input[smallest] = temp;
		min_heapify(input, size, smallest);
	}
	return 0;
}
void build_min_heap(lec* input, int size)
{
	for (int i = size / 2; 0 <= i; i--)
	{
		min_heapify(input, size, i);
	}
}
int min_heapify_int(int* input, int size, int index)
{
	int l = left(index);
	int r = right(index);
	int smallest = index;
	if (l <= size - 1 && input[l]< input[index])
	{
		smallest = l;
	}
	if (r <= size - 1 && input[r]< input[smallest])
	{
		smallest = r;
	}
	if (smallest != index)
	{
		int temp;
		temp = input[index];
		input[index] = input[smallest];
		input[smallest] = temp;
		min_heapify_int(input, size, smallest);
	}
	return 0;
}
void build_min_heap_int(int* input, int size)
{
	for (int i = size / 2; 0 <= i; i--)
	{
		min_heapify_int(input, size, i);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);	
	int size = n;
	lec* input = (lec*)malloc(sizeof(lec) * n);
	int* end_time = (int*)malloc(sizeof(int) * n);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &input[i].start, &input[i].end);
	}
	build_min_heap(input, n);
	while(size>0)
	{
		if (count == 0)
		{
			end_time[count] = input[0].end;
			count++;
			input[0] = input[size - 1];
			size--;
			min_heapify(input, size, 0);
		}
		else if (end_time[0] > input[0].start)
		{
			end_time[count] = input[0].end;
			count++;
			input[0] = input[size - 1];
			size--;
			min_heapify(input, size, 0);
			int index = count - 1;
			while (end_time[index] < end_time[parent(index)])
			{
				int temp;
				temp = end_time[index];
				end_time[index] = end_time[parent(index)];
				end_time[parent(index)] = temp;
				index = parent(index);
			}
		}
		else
		{
			int index = 0;
			while (left(index) <= count - 1 && end_time[left(index)] <= input[0].start)
			{
				index = left(index);
			}
			int min = INT_MAX;
			int marker=index;
			for (int i = index; i < left(index); i++)
			{
				if (end_time[i] > input[0].start)
				{
					break;
				}
				if (i > count - 1)
				{
					break;
				}
				min = min < (input[0].start - end_time[i]) ? min : (input[0].start - end_time[i]);
				if (min == input[0].start - end_time[i])
				{
					marker = i;
				}
			}
			end_time[marker] = input[0].end;
			min_heapify_int(end_time, count, marker);
			input[0] = input[size - 1];
			size--;
			min_heapify(input, size, 0);
		}
	}

	printf("%d", count);
	free(input);
	free(end_time);
	return 0;
}