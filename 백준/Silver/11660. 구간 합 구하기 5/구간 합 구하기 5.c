#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int t_size;
	scanf("%d", &t_size);
	int** array = (int**)malloc(sizeof(int*) * (n+1));
	int** answer = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n+1; i++)
	{
		array[i] = (int*)malloc(sizeof(int) * (n + 1));
		answer[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	for (int j = 0; j <= n; j++)
	{
		answer[0][j] = 0;
		answer[j][0] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &array[i][j]);
			answer[i][j] = answer[i - 1][j] + answer[i][j - 1] - answer[i - 1][j - 1] + array[i][j];
		}
	}
	int* result = (int*)malloc(sizeof(int) * t_size);
	int x1, y1, x2, y2;
	for (int i = 0; i < t_size; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		result[i] = answer[x2][y2] + answer[x1 - 1][y1 - 1] - answer[x1 - 1][y2] - answer[x2][y1 - 1];
	}
	for (int i = 0; i < t_size; i++)
	{
		printf("%d\n", result[i]);
	}
	free(array);
	free(answer);
	free(result);
	return 0;
}