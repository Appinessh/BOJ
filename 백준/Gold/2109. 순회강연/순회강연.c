#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct work {
	int due;
	int score;
}work;
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
int max_heapify(work* array, int size, int index)
{
	int l = left(index);
	int r = right(index);
	int largest = index;
	if (l <= size - 1 && array[l].score > array[index].score)
	{
		largest = l;
	}
	if (r <= size - 1 && array[r].score > array[largest].score)
	{
		largest = r;
	}
	if (index != largest)
	{
		work temp;
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		max_heapify(array, size, largest);
	}
	return 0;
}
void build_max_heap(work* array, int size)
{
	for (int i = size / 2; i >= 0; i--)
	{
		max_heapify(array, size, i);
	}
}
int score[10001] = { 0, };
int find_date(int date)
{
	int i = date;
	for (i = date; i >= 1; i--)
	{
		if (score[i] == 0)
		{
			break;
		}
	}
	return i;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	work* input = (work*)malloc(sizeof(work) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &input[i].score, &input[i].due);
	}
	build_max_heap(input, n);
	int input_size = n;
	for (int i = 0; i < n; i++)
	{
		int date = find_date(input[0].due);
		if (date == 0)
		{
			input[0] = input[input_size - 1];
			input_size--;
			max_heapify(input, input_size, 0);
		}
		else
		{
			score[date] = input[0].score;
			input[0] = input[input_size - 1];
			input_size--;
			max_heapify(input, input_size, 0);
		}
	}
	int sum = 0;
	for (int i = 1; i <= 10000; i++)
	{
		sum = sum + score[i];
	}
	printf("%d", sum);
	free(input);
	return 0;
}