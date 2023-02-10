#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct node{
	int start_date;
	int end_date;
	int pr;
}node;
int compare(const void* a, const void* b)
{
	node node1 = *(node*)a;
	node node2 = *(node*)b;
	if (node1.end_date > node2.end_date)
	{
		return 1;
	}
	else
	{
		if (node1.end_date == node2.end_date)
		{
			if (node1.start_date > node2.start_date)
			{
				return 1;
			}
			else if (node1.start_date == node2.start_date)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	node* array = (node*)malloc(sizeof(node) * (n+1));
	for (int i = 0; i < n; i++)
	{
		int temp1, temp2;
		array[i].start_date = i;
		scanf("%d%d", &temp1, &temp2);
		array[i].end_date = i + temp1 - 1;
		array[i].pr = temp2;
	}
	array[n].start_date = n;
	array[n].end_date = INT_MAX;
	qsort(array, n, sizeof(node), compare);
	int* answer = (int*)malloc(sizeof(int) * n);
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		answer[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int indi=0;
		while (1)
		{
			if (array[index].end_date < i)
			{
				index++;
			}
			else if (array[index].end_date == i)
			{
				break;
			}
			else
			{
				indi = 1;
				break;
			}
		}
		if (i == 0&&indi==1)
		{
			continue;
		}
		answer[i] = answer[i - 1];
		if (indi == 1)
		{
			continue;
		}
		while (array[index].end_date == i)
		{
			if (array[index].start_date == 0)
			{
				answer[i] = answer[i] > array[index].pr ? answer[i] : array[index].pr;
			}
			else
			{
				answer[i] = answer[i] > (answer[array[index].start_date - 1] + array[index].pr) ? answer[i] : (answer[array[index].start_date - 1] + array[index].pr);
			}
			index++;
		}
		index--;
	}
	printf("%d", answer[n - 1]);
	free(array);
	free(answer);
	return 0;
}