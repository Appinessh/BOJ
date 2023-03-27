#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
struct node {
	int index1;
	int index2;
	int number;
};
vector<vector<int>> direction = { {-1,0},{1,0},{0,1},{0,-1} };
vector<vector<int>> map;
vector<vector<int>> visited_0;
vector<vector<int>> visited_1;
queue<node> q;
void solution(void)
{
	visited_0[0][0] = 1;
	visited_1[0][0] = 1;
	node start;
	start.index1 = 0;
	start.index2 = 0;
	start.number = 0;
	q.push(start);
	while (!q.empty())
	{
		node temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int index1, index2;
			index1 = temp.index1 + direction[i][0];
			index2 = temp.index2 + direction[i][1];
			if (index1 >= 0 && index2 >= 0 && index1 < map.size() && index2 < map[0].size())
			{
				if (temp.number == 0)
				{
					if (visited_0[index1][index2] == 0&&map[index1][index2]==0)
					{
						visited_0[index1][index2] = visited_0[temp.index1][temp.index2] + 1;
						if (visited_1[index1][index2] == 0)
						{
							visited_1[index1][index2] = visited_0[index1][index2];
						}// 검토
						node new_node;
						new_node.index1 = index1;
						new_node.index2 = index2;
						new_node.number = 0;
						q.push(new_node);
					}
					else if(visited_0[index1][index2]==0&&map[index1][index2]==1)
					{
						visited_1[index1][index2] = visited_0[temp.index1][temp.index2]+1;
						node new_node;
						new_node.index1 = index1;
						new_node.index2 = index2;
						new_node.number = 1;
						q.push(new_node);
					}
					else
					{

					}
				}
				else //temp.number=1;
				{
					if (visited_1[index1][index2] == 0 && map[index1][index2] == 0)
					{
						visited_1[index1][index2] = visited_1[temp.index1][temp.index2] + 1;
						node new_node;
						new_node.index1 = index1;
						new_node.index2 = index2;
						new_node.number = 1;
						q.push(new_node);
					}
				}
			}
		}
	}
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	map.resize(n);
	visited_0.resize(n);
	visited_1.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
		visited_0[i].resize(m);
		visited_1[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			scanf("%1d", &a);
			map[i][j] = a;
		}
	}
	solution();
	int min;
	if (visited_0[n - 1][m - 1] == 0 && visited_1[n - 1][m - 1] == 0)
	{
		cout << "-1";
	}
	else if (visited_0[n - 1][m - 1] == 0)
	{
		cout << visited_1[n - 1][m - 1];
	}
	else if (visited_1[n - 1][m - 1] == 0)
	{
		cout << visited_0[n - 1][m - 1];
	}
	else
	{
		min = visited_0[n - 1][m - 1] < visited_1[n - 1][m - 1] ? visited_0[n - 1][m - 1] : visited_1[n - 1][m - 1];
		cout << min ;
	}
	return 0;
}