#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> visited;
vector<vector<int>> direction = { {1,0},{-1,0},{0,1},{0,-1} };
struct node {
	int index1;
	int index2;
};
queue <node> location;
queue <node> next_step;
int bfs(void)
{
	if (next_step.empty())
	{
		return 0;
	}
	int result=0;
	node current_node;
	current_node = next_step.front();
	next_step.pop();
	for (int i = 0; i < 4; i++)
	{
		if (current_node.index1 + direction[i][0] >= 0 && current_node.index1 + direction[i][0] < map.size() && current_node.index2 + direction[i][1] >= 0 && current_node.index2 + direction[i][1] < map[0].size())
		{
			if(map[current_node.index1+direction[i][0]][current_node.index2+direction[i][1]]==1&&visited[current_node.index1+direction[i][0]][current_node.index2+direction[i][1]]==0)
			{
				visited[current_node.index1 + direction[i][0]][current_node.index2 + direction[i][1]] = visited[current_node.index1][current_node.index2] + 1;
				node new_node;
				new_node.index1 = current_node.index1 + direction[i][0];
				new_node.index2 = current_node.index2 + direction[i][1];
				next_step.push(new_node);
				result = result > visited[current_node.index1 + direction[i][0]][current_node.index2 + direction[i][1]] ? result : visited[current_node.index1 + direction[i][0]][current_node.index2 + direction[i][1]];
			}
		}
	}
	int a = bfs();
	result = result > a ? result : a;
	return result;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	map.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
		visited[i].resize(m);
	}
	char s;
	node new_node;
	int max = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> s;
			if (s == 'W')
			{
				map[i][j] = 0;
			}
			else
			{
				map[i][j] = 1;
				new_node.index1 = i;
				new_node.index2 = j;
				location.push(new_node);
			}
		}
	}
	if (location.empty())
	{
		cout << 0;
		return 0;
	}
	while (!location.empty())
	{
		node seed_node = location.front();
		location.pop();
		visited[seed_node.index1][seed_node.index2] = 1;
		next_step.push(seed_node);
		int k = bfs();
		max = max > k ? max : k;
		visited.resize(0);
		visited.resize(n);
		for (int i = 0; i < n; i++)
		{
			visited[i].resize(m);
		}
	}
	cout << max-1;
	return 0;
}