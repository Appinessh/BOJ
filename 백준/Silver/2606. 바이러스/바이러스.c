#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int val = 0;
void dfs(int** edge, int* visited, int start,int n_v)
{
	visited[start] = val;
	for (int i = 1; i <= n_v; i++)
	{
		if (visited[i] == 0 && edge[start][i] == 1)
		{
			dfs(edge, visited, i, n_v);
		}
	}
}
int main(void)
{
	int n_v, n_e;
	scanf("%d%d", &n_v, &n_e);
	int** edge = (int**)malloc(sizeof(int*) * (n_v+2));
	int** answer = (int**)malloc(sizeof(int*) * (n_v + 2));
	int* visited = (int*)malloc(sizeof(int) * (n_v + 1));
	for (int i = 0; i < n_v +2; i++)
	{
		edge[i] = (int*)malloc(sizeof(int) * (n_v + 2));
		answer[i] = (int*)malloc(sizeof(int) * (n_v + 2));
	}
	for (int i = 0; i < n_v + 1; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < n_v + 2; i++)
	{
		for (int j = 0; j < n_v + 2; j++)
		{
			edge[i][j] = 0;
			answer[i][j] = 0;
		}
	}
	for (int i = 0; i < n_e; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	while (1)
	{
		int index = -1;
		for (int i = 1; i <= n_v; i++)
		{
			if (visited[i] == 0)
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			break;
		}
		val++;
		dfs(edge, visited, index, n_v);
	}
	int sum = 0;
	for (int i = 2; i <= n_v; i++)
	{
		if (visited[1] == visited[i])
		{
			sum++;
		}
	}
	printf("%d", sum);
	free(edge);
	free(visited);
	free(answer);
	return 0;
}