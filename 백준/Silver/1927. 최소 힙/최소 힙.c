#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int min_heapify(int* array, int size, int index)
{
	int l = left(index);
	int r = right(index);
	int smallest=index;
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
		int temp;
		temp = array[index];
		array[index] = array[smallest];
		array[smallest] = temp;
		min_heapify(array, size, smallest);
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
				min_heapify(array, size, 0);
			}
			count++;
		}
		else
		{
			array[size] = temp;
			size++;
			int index = size - 1;
			while (parent(index) >= 0 && array[parent(index)] > array[index])
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