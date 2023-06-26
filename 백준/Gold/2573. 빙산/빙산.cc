#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> cnt_matrix;
vector<vector<int>> visited;
vector<vector<int>> direction = { {-1,0},{1,0},{0,1},{0,-1} };
void melting(void)
{
	cnt_matrix.resize(map.size());
	for (int i = 0; i < map.size(); i++)
	{
		cnt_matrix[i].resize(map[0].size());
	}
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + direction[k][0] >= 0 && i + direction[k][0] < map.size() && j + direction[k][1] >= 0 && j + direction[k][1] < map[0].size())
				{
					if (map[i + direction[k][0]][j + direction[k][1]] == 0)
					{
						cnt++;
					}
				}
			}
			cnt_matrix[i][j] = cnt;

		}
	}
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			map[i][j] = map[i][j] - cnt_matrix[i][j];
			if (map[i][j] < 0)
			{
				map[i][j] = 0;
			}
		}
	}
}
vector<int> index_find(void)
{
	vector<int> result;
	result.resize(2);
	result[0] = -1;
	result[1] = -1;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] != 0&&visited[i][j]==0)
			{
				result[0] = i;
				result[1] = j;
				break;
			}
		}
	}
	return result;
}
void dfs(int index1, int index2)
{
	visited[index1][index2] = 1;
	for (int i = 0; i < 4; i++)
	{
		if (index1 + direction[i][0] >= 0 && index1 + direction[i][0] < map.size() && index2 + direction[i][1] >= 0 && index2 + direction[i][1] < map[0].size())
		{
			if (map[index1 + direction[i][0]][index2 + direction[i][1]] != 0 && visited[index1 + direction[i][0]][index2 + direction[i][1]] == 0)
			{
				dfs(index1 + direction[i][0], index2 + direction[i][1]);
			}
		}
	}
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	while (1)
	{
		vector<int> index;
		index.resize(2);
		index = index_find();
		if (index[0] == -1)
		{
			break;
		}
		dfs(index[0], index[1]);
		index = index_find();
		if (index[0] != -1)
		{
			cout << cnt;
			return 0;
		}
		cnt++;
		melting();
		visited.resize(0);
		visited.resize(n);
		for (int i = 0; i < n; i++)
		{
			visited[i].resize(m);
		}
	}
	cout << 0;
	return 0;
}