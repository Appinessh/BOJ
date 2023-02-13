#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int val = 1;
int dfs(int* visited, int** edge, int start,int n_v)
{
	visited[start] = val;
	for (int i = 1; i <= n_v; i++)
	{
		if (edge[start][i] == 1 && visited[i] == 0)
		{
			dfs(visited, edge, i, n_v);
		}
	}
	return 0;
}
int main(void)
{
	int n_v, n_e;
	scanf("%d%d", &n_v, &n_e);
	int** edge = (int**)malloc(sizeof(int*) * (n_v + 1));
	for (int i = 0; i <= n_v; i++)
	{
		edge[i] = (int*)malloc(sizeof(int) * (n_v + 1));
	}
	for (int i = 0; i <= n_v; i++)
	{
		for (int j = 0; j <= n_v; j++)
		{
			edge[i][j] = 0;
		}
	}
	for (int i = 0; i < n_e; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	int* visited = (int*)malloc(sizeof(int) * (n_v + 1));
	for (int i = 0; i <= n_v; i++)
	{
		visited[i] = 0;
	}
	int index = 0;
	while (index!=-1)
	{

		index = -1;
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
		dfs(visited, edge, index, n_v);
	}
	val--;
	printf("%d", val);
	free(visited);
	free(edge);
	return 0;
}