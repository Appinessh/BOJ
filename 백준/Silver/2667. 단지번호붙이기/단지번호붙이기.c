#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int val = 0;
int* find(int** visited, int** map,int size)
{
	int n = size;
	int* answer = (int*)malloc(sizeof(int) * 2);
	answer[0] = -1;
	answer[1] = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] == 0 && map[i][j] == 1)
			{
				answer[0] = i;
				answer[1] = j;
				break;
			}
		}
	}
	return answer;
}
int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 > num2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int dfs(int** visited, int** map, int index1, int index2, int size)
{
	int sum = 0;
	visited[index1][index2] = 1;
	sum++;
	if (visited[index1 - 1][index2] == 0 &&map[index1-1][index2]==1)
	{
		sum=sum+dfs(visited, map, index1 - 1, index2, size);
	}
	if (visited[index1 + 1][index2] == 0 && map[index1 + 1][index2] == 1)
	{
		sum=sum+ dfs(visited, map, index1 + 1, index2, size);
	}
	if (visited[index1][index2-1] == 0 && map[index1][index2-1] == 1)
	{
		sum = sum + dfs(visited, map, index1, index2-1, size);
	}
	if (visited[index1][index2 + 1] == 0 && map[index1][index2 + 1] == 1)
	{
		sum = sum + dfs(visited, map, index1, index2 + 1, size);
	}
	return sum;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int** map = (int**)malloc(sizeof(int*) * (n + 2));
	int** visited = (int**)malloc(sizeof(int*) * (n + 2));
	int* answer = (int*)malloc(sizeof(int) * (n * n));
	for (int i = 0; i < n * n; i++)
	{
		answer[i] = INT_MAX;
	}
	for (int i = 0; i < n + 2; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * (n + 2));
		visited[i] = (int*)malloc(sizeof(int) * (n + 2));
	}
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			visited[i][j] = 0;
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
			{
				map[i][j] = 0;
			}
			else
			{
				scanf("%1d", &map[i][j]);
			}
		}
	}
	int count = 0;
	while (1)
	{
		int index1, index2;
		int* array = (int*)malloc(sizeof(int) * 2);
		array = find(visited, map, n);
		index1 = array[0];
		index2 = array[1];
		if (index1 == -1)
		{
			break;
		}
		val++;
		int temp = dfs(visited, map, index1, index2,n);
		answer[count] = temp;
		count++;
	}
	printf("%d\n", val);
	qsort(answer, n * n, sizeof(int), compare);
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", answer[i]);
	}
	free(map);
	free(visited);
	free(answer);
	return 0;
}