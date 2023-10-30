#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
vector <vector<int>> direction = { {-1,0},{0,-1},{1,0},{0,1} };
vector<vector<int>> map;
vector<vector<int>> visited;
typedef struct node {
	int index1;
	int index2;
	int time;
};
int n, m, T;
int timegap;
int answer = INT_MAX;
queue <node> q;
int dfs(void)
{
	if (q.empty())
	{
		return -1;
	}
	node top_node = q.front();
	q.pop();
	if (top_node.index1 == n && top_node.index2 == m)
	{
		return top_node.time;
	}
	if (map[top_node.index1][top_node.index2] ==2 )
	{
		answer = top_node.time + (n - top_node.index1) + (m - top_node.index2);
	}
	for (int i = 0; i < 4; i++)
	{
		if (top_node.index1 + direction[i][0] >= 0 && top_node.index1 + direction[i][0] <= n)
		{
			if (top_node.index2 + direction[i][1] >= 0 && top_node.index2 + direction[i][1] <= m)
			{
				if (visited[top_node.index1 + direction[i][0]][top_node.index2 + direction[i][1]] == 0)
				{
					if (map[top_node.index1 + direction[i][0]][top_node.index2 + direction[i][1]] != 1)
					{
						node new_node;
						new_node.index1 = top_node.index1 + direction[i][0];
						new_node.index2 = top_node.index2 + direction[i][1];
						new_node.time = top_node.time + 1;
						visited[new_node.index1][new_node.index2] = 1;
						q.push(new_node);
					}
				}
			}
		}
	}
	return dfs();
}
int main(void)
{
	cin >> n >> m >> T;
	map.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
		visited[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				timegap = n - 1 - i + m - 1 - j;
			}
		}
	}
	n--;
	m--;
	node seed_node;
	seed_node.index1 = 0;
	seed_node.index2 = 0;
	seed_node.time = 0;
	visited[0][0] = 1;
	q.push(seed_node);
	int result=dfs();
	if (result == -1 && answer <= T)
	{
		cout << answer;
		return 0;
	}
	answer = answer < result ? answer : result;
	if (answer == -1||answer>T)
	{
		cout << "Fail";
		return 0;
	}
	cout << answer;
	return 0;
}