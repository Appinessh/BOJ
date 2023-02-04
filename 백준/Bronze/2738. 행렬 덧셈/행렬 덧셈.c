#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int** input1 = (int**)malloc(sizeof(int*) * n);
	int** input2 = (int**)malloc(sizeof(int*) * n);
	int** answer = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		input1[i] = (int*)malloc(sizeof(int*) * m);
		input2[i] = (int*)malloc(sizeof(int*) * m);
		answer[i] = (int*)malloc(sizeof(int*) * m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &input1[i][j]);
			answer[i][j] = input1[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &input2[i][j]);
			answer[i][j] = answer[i][j] + input2[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}
	return 0;
}