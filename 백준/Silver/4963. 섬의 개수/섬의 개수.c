#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int answer;
int* find(int** map, int** visited, int size1,int size2)
{
	int* answer=(int*)malloc(sizeof(int)*2);
	answer[0] = -1;
	answer[1] = -1;
	int indi=0;
	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if (visited[i][j] == 0 && map[i][j] == 1)
			{
				answer[0] = i;
				answer[1] = j;
				indi = 1;
				break;
			}
		}
		if (indi == 1)
		{
			break;
		}
	}
	return answer;
}
void dfs(int** map, int** visited, int index1, int index2, int size1, int size2)
{
	visited[index1][index2] = 1;
	if (visited[index1 - 1][index2] == 0 && map[index1 - 1][index2] == 1)
	{
		dfs(map, visited, index1 - 1, index2, size1, size2);
	}
	if (visited[index1 +1][index2] == 0 && map[index1 +1][index2] == 1)
	{
		dfs(map, visited, index1+ 1, index2, size1, size2);
	}
	if (visited[index1][index2-1] == 0 && map[index1][index2-1] == 1)
	{
		dfs(map, visited, index1, index2-1, size1, size2);
	}
	if (visited[index1][index2 + 1] == 0 && map[index1][index2 + 1] == 1)
	{
		dfs(map, visited, index1, index2 + 1, size1, size2);
	}
	if (visited[index1 - 1][index2-1] == 0 && map[index1 - 1][index2-1] == 1)
	{
		dfs(map, visited, index1 - 1, index2-1, size1, size2);
	}
	if (visited[index1 - 1][index2 + 1] == 0 && map[index1 - 1][index2 + 1] == 1)
	{
		dfs(map, visited, index1 - 1, index2 + 1, size1, size2);
	}
	if (visited[index1 + 1][index2 - 1] == 0 && map[index1 + 1][index2 - 1] == 1)
	{
		dfs(map, visited, index1 + 1, index2 - 1, size1, size2);
	}
	if (visited[index1 + 1][index2 + 1] == 0 && map[index1 + 1][index2 + 1] == 1)
	{
		dfs(map, visited, index1 + 1, index2 + 1, size1, size2);
	}
}
int main(void)
{
	while (1)
	{
		int n, m;
		scanf("%d%d", &m, &n);
		if (n == 0 && m == 0)
		{
			break;
		}
		int** map = (int**)malloc(sizeof(int*) * (n + 2));
		int** visited = (int**)malloc(sizeof(int*) * (n + 2));
		for (int i = 0; i < n + 2; i++)
		{
			map[i] = (int*)malloc(sizeof(int) * (m + 2));
			visited[i] = (int*)malloc(sizeof(int) * (m + 2));
		}
		for (int i = 0; i < n + 2; i++)
		{
			for (int j = 0; j < m + 2; j++)
			{
				visited[i][j] = 0;
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
				{
					map[i][j] = 0;
				}
				else
				{
					scanf("%1d", &map[i][j]);
				}
			}
		}
		answer = 0;
		while (1)
		{
			int* temp=(int*)malloc(sizeof(int)*2);
			temp=find(map, visited, n, m);
			int index1 = temp[0];
			int index2 = temp[1];
			if (index1 == -1)
			{
				break;
			}
			dfs(map, visited, index1, index2, n, m);
			answer++;
		}
		printf("%d\n", answer);
		free(map);
		free(visited);
	}
	return 0;
}