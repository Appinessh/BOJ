#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int result(int** input, int index)
{
	int i;
	int x1 = input[index][0], y1 = input[index][1];
	int x2 = x1 + 10, y2 = y1 + 10;
	int indicator[10][10] = { 0, };
	for (i = 0; i < index; i++)
	{
		if (input[i][0]<x2 && input[i][0]>=x1)
		{
			if (input[i][1]<y2 && input[i][1]>=y1)
			{
				for (int j = input[i][0] - x1; j < x2-x1; j++)
				{
					for (int k = input[i][1] - y1; k < y2-y1; k++)
					{
						indicator[j][k]++;
					}
				}
			}
			if (input[i][1]+10 < y2 && input[i][1]+10 >= y1)
			{
				for (int j = input[i][0] - x1; j < x2-x1; j++)
				{
					for (int k = 0; k < input[i][1]-y1+10; k++)
					{
						indicator[j][k]++;
					}
				}
			}
		}
		if (input[i][0]+10 < x2 && input[i][0]+10 >= x1)
		{
			if (input[i][1] < y2 && input[i][1] >= y1)
			{
				for (int j = 0; j < input[i][0]+10-x1; j++)
				{
					for (int k = input[i][1] - y1; k < y2 - y1; k++)
					{
						indicator[j][k]++;
					}
				}
			}
			if (input[i][1] + 10 < y2 && input[i][1] + 10 >= y1)
			{
				for (int j = 0; j < input[i][0]+10 - x1; j++)
				{
					for (int k = 0; k < input[i][1] - y1 + 10; k++)
					{
						indicator[j][k]++;
					}
				}
			}
		}
	}
	int val = 0;
	for (i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (indicator[i][j] == 0)
			{
				val++;
			}
		}
	}
	return val;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int** input = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		input[i] = (int*)malloc(sizeof(int) * 2);
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &input[i][0], &input[i][1]);
		answer = answer + result(input, i);
	}
	printf("%d", answer);
	return 0;
}