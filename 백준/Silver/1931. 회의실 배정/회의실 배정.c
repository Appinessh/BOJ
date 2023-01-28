#include <stdio.h>
#define _CRT_SECURE_NO_WARNIGNGS
#include <stdlib.h>
void merge(int* start, int* end, int a, int mid, int b)
{
	int* end1=(int*)malloc(sizeof(int)*(mid-a+1+1));
	int* start1 = (int*)malloc(sizeof(int) * (mid - a + 1+1));
	int* end2=(int*)malloc(sizeof(int)*(b-mid+1));
	int* start2 = (int*)malloc(sizeof(int) * (b - mid+1));
	int j;
	for (j = 0; j <= mid - a; j++)
	{
		end1[j] = end[a + j];
		start1[j] = start[a + j];
	}
	for (j = 0; j <= b - mid - 1; j++)
	{
		end2[j] = end[mid + 1 + j];
		start2[j] = start[mid + 1 + j];
	}
	int index1 = 0, index2 = 0;
	for (j = 0; j <= b - a; j++)
	{
		if (index1 == mid - a + 1)
		{
			start[a+j] = start2[index2];
			end[a+j] = end2[index2];
			index2++;
		}
		else if (index2 == b - mid)
		{
			start[a + j] = start1[index1];
			end[a + j] = end1[index1];
			index1++;
		}
		else if (end1[index1] < end2[index2])
		{
			start[a + j] = start1[index1];
			end[a + j] = end1[index1];
			index1++;
		}
		else if (end1[index1] > end2[index2])
		{
			start[a + j] = start2[index2];
			end[a + j] = end2[index2];
			index2++;
		}
		else // end1[index1]==end2[index2]
		{
			if (start1[index1] < start2[index2])
			{
				start[a + j] = start1[index1];
				end[a + j] = end1[index1];
				index1++;
			}
			else
			{
				start[a + j] = start2[index2];
				end[a + j] = end2[index2];
				index2++;
			}
		}
	}
}
int mergesort(int *start,int* end, int a, int b)
{
	if (a == b)
	{
		return 0;
	}
	int mid;
	mid = (a + b) / 2;
	mergesort(start, end, a, mid);
	mergesort(start, end, mid + 1, b);
	merge(start, end, a, mid, b);
	return 0;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* start = (int*)malloc(sizeof(int) * n);
	int* end = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &start[i], &end[i]);
	}
	mergesort(start, end, 0, n - 1);
	int count = 0;
	int time=0;
	for (i = 0; i < n; i++)
	{
		if (start[i] >= time)
		{
			count++;
			time = end[i];
		}
	}
	printf("%d", count);
	return 0;
}