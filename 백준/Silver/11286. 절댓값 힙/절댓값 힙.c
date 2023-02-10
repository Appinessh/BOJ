#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int parent(int i)
{
	if (i == 0)
	{
		return -1;
	}
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
int abs_min_heapify(int* array, int size, int index)
{
	int l = left(index);
	int r = right(index);
	int smallest = index;
	if (l <= size - 1 && abs(array[index]) >= abs(array[l]))
	{
		if (abs(array[index]) == abs(array[l]))
		{
			if (array[index] < array[l])
			{
				smallest = index;
			}
			else if (array[index] > array[l])
			{
				smallest = l;
			}
			else
			{
				smallest = l;
			}
		}
		else
		{
			smallest = l;
		}
	}
	if (r <= size - 1 && abs(array[smallest]) >= abs(array[r]))
	{
		if (abs(array[smallest]) == abs(array[r]))
		{
			if (array[smallest] < array[r])
			{
				smallest =smallest;
			}
			else if (array[smallest] > array[r])
			{
				smallest = r;
			}
			else
			{
				smallest = r;
			}
		}
		else
		{
			smallest = r;
		}
	}
	if (smallest != index)
	{
		int temp;
		temp = array[index];
		array[index] = array[smallest];
		array[smallest] = temp;
		abs_min_heapify(array, size, smallest);
	}
	return 0;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	int* answer = (int*)malloc(sizeof(int) * n);
	int size=0;
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
				abs_min_heapify(array, size, 0);
			}
			count++;
		}
		else
		{
			array[size] = temp;
			size++;
			int index;
			index = size - 1;
			while (parent(index) >= 0 && abs(array[index]) <= abs(array[parent(index)]))
			{
				if (abs(array[index]) == abs(array[parent(index)]))
				{
					if (array[index] > array[parent(index)])
					{
						break;
					}
				}
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