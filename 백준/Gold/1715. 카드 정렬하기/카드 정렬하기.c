#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
long long int sum = 0;
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
int min_heapify(long long int* array, int size, int index)
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
		long long int temp = array[smallest];
		array[smallest] = array[index];
		array[index] = temp;
		min_heapify(array, size, smallest);
	}
	return 0;
}
void build_min_heap(long long int* array, int size)
{
	for (int i = size / 2; i >= 0; i--)
	{
		min_heapify(array, size, i);
	}
}
void double_pop(long long int* array, int size)
{
	int index;
	if (array[1] < array[2])
	{
		index = 1;
	}
	else
	{
		index = 2;
	}
	long long int a, b;
	a = array[0] + array[index];
	b = array[size - 1];
	sum = sum + a;
	size--;
	array[0] = a;
	array[index] = b;
	min_heapify(array, size, index);
	min_heapify(array, size, 0);
}
int main(void)
{
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0");
		return 0;
	}
	long long int* input = (long long int*)malloc(sizeof(long long int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &input[i]);
	}
	build_min_heap(input, n);
	int size = n;
	while (size > 2)
	{
		double_pop(input, size);
		size--;
	}
	printf("%lld", sum+input[0] + input[1]);
	free(input);
	return 0;
}