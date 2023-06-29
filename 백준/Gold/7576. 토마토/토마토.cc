#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> direction = { {-1,0},{1,0},{0,1},{0,-1} };
struct node
{
	int index1;
	int index2;
	int value;
};
queue <node> q;
void find_location(void)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if (map[i][j] == 1)
			{
				node new_node;
				new_node.index1 = i;
				new_node.index2 = j;
				new_node.value = 1;
				q.push(new_node);
			}
		}
	}
}
void dfs(void)
{
	if (q.empty())
	{

	}
	else
	{
		node top_node = q.front();
		q.pop();
		if (map[top_node.index1][top_node.index2] == 0)
		{
			map[top_node.index1][top_node.index2] = top_node.value;
		}
		for (int i = 0; i < 4; i++)
		{
			if (top_node.index1 + direction[i][0] >= 0 && top_node.index1 + direction[i][0] < map.size() && top_node.index2 + direction[i][1] >= 0 && top_node.index2 + direction[i][1] < map[0].size())
			{
				if (map[top_node.index1 + direction[i][0]][top_node.index2 + direction[i][1]] == 0 )
				{
					node new_node;
					new_node.index1 = top_node.index1 + direction[i][0];
					new_node.index2 = top_node.index2 + direction[i][1];
					new_node.value = top_node.value + 1;
					q.push(new_node);
					map[new_node.index1][new_node.index2] = new_node.value;
				}
			}
		}
		dfs();
	}
}
int main(void)
{
	int n, m;
	cin >> m >> n;
	map.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	find_location();
	dfs();
	int max = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for(int j=0;j<map[0].size();j++)
		{
			if (map[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (map[i][j] != -1)
			{
				max = max > map[i][j] - 1 ? max : map[i][j] - 1;
			}
		}
	}
	cout << max;
	return 0;
}