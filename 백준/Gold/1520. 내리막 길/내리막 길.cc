#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> dp;
vector<vector<int>> direction_map;
vector<vector<int>> visited;
vector<vector<int>> direction = { {-1,0},{1,0},{0,1},{0,-1} };
void dfs_realquick(int index1, int index2)
{
	visited[index1][index2] = 1;
	for (int i = 0; i < 4; i++)
	{
		if ((index1 + direction[i][0] >= 0) && (index1 + direction[i][0] < dp.size()) && (index2 + direction[i][1] >= 0) && (index2 + direction[i][1] < dp[i].size()))
		{
			if (visited[index1 + direction[i][0]][index2 + direction[i][1]] == 0&&map[index1][index2]>map[index1+direction[i][0]][index2+direction[i][1]])
			{
				dfs_realquick(index1 + direction[i][0], index2 + direction[i][1]);
			}
		}
	}
}
void dfs(int index1, int index2)
{
	for (int i = 0; i < 4; i++)
	{
		if ((index1 + direction[i][0] >= 0) && (index1 + direction[i][0] < dp.size()) && (index2 + direction[i][1] >= 0) && (index2 + direction[i][1] < dp[i].size()))
		{
			if (map[index1][index2]>map[index1+direction[i][0]][index2+direction[i][1]])
			{
				dp[index1 + direction[i][0]][index2 + direction[i][1]] = dp[index1][index2] + dp[index1 + direction[i][0]][index2 + direction[i][1]];
				direction_map[index1 + direction[i][0]][index2 + direction[i][1]]--;
				if (direction_map[index1 + direction[i][0]][index2 + direction[i][1]] == 0)
				{
					dfs(index1 + direction[i][0], index2 + direction[i][1]);
				}
			}
			else
			{
				continue;
			}
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	map.resize(n);
	dp.resize(n);
	direction_map.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
		dp[i].resize(m);
		direction_map[i].resize(m);
		visited[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;
			dp[i][j] = 0;

		}
	}
	dfs_realquick(0,0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if ((i + direction[k][0] >= 0) && (i + direction[k][0] < n) && (j + direction[k][1] >= 0) && (j + direction[k][1] < m))
				{
					if (visited[i][j]!=0 && visited[i + direction[k][0]][j + direction[k][1]] != 0 && map[i + direction[k][0]][j + direction[k][1]]>map[i][j])
					{
						direction_map[i][j]++;
					}
				}
			}
		}
	}
	dp[0][0] = 1;
	dfs(0, 0);
	cout << dp[n - 1][m - 1] << endl;
	return 0;
}