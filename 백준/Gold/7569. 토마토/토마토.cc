#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector<vector<vector<int>>> map;
vector<vector<vector<int>>> visited;
vector<vector<int>> direction = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };
queue <vector<int>> q;
void find_location(void)
{
	vector<int> answer;
	answer.resize(3);
	answer[0] = -1;
	for (int i = 0; i < map[0][0].size(); i++)
	{
		for (int j = 0; j < map.size(); j++)
		{
			for (int k = 0; k < map[0].size(); k++)
			{
				if (visited[j][k][i] == 0 && map[j][k][i] == 1)
				{
					answer[0] = j;
					answer[1] = k;
					answer[2] = i;
					visited[j][k][i] = 1;
					q.push(answer);
				}
			}
		}
	}
}
void bfs(void)
{
	if (q.empty())
	{

	}
	else
	{
		vector<int> coordinates = q.front();
		int indicator = 1;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			if (coordinates[0] + direction[i][0] >= 0 && coordinates[1] + direction[i][1] >= 0 && coordinates[2] + direction[i][2] >= 0)
			{
				if (coordinates[0] + direction[i][0] < map.size() && coordinates[1] + direction[i][1] < map[0].size() && coordinates[2] + direction[i][2] < map[0][0].size())
				{
					if (visited[coordinates[0] + direction[i][0]][coordinates[1] + direction[i][1]][coordinates[2] + direction[i][2]] == 0 && map[coordinates[0] + direction[i][0]][coordinates[1] + direction[i][1]][coordinates[2] + direction[i][2]] == 0)
					{
						visited[coordinates[0] + direction[i][0]][coordinates[1] + direction[i][1]][coordinates[2] + direction[i][2]] = visited[coordinates[0]][coordinates[1]][coordinates[2]]+1;
						vector<int> new_coordinates(3);
						new_coordinates[0] = coordinates[0] + direction[i][0];
						new_coordinates[1] = coordinates[1] + direction[i][1];
						new_coordinates[2] = coordinates[2] + direction[i][2];
						q.push(new_coordinates);
					}
				}
			}
		}
		bfs();
	}
}
int find_unripen(void)
{
	int result=0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			for (int k = 0; k < map[0][0].size(); k++)
			{
				if (visited[i][j][k] == 0&&map[i][j][k]==0)
				{
					result = 1;
					return result;
				}
			}
		}
	}
	return result;
}
int main(void)
{
	int n, m, h;
	cin >> m >> n >> h;
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
			map[i][j].resize(h);
			visited[i][j].resize(h);
		}
	}
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j][k];
			}
		}
	}
	find_location();
	bfs();
	if (find_unripen())
	{

		cout << "-1";
		return 0;
	}
	int max = INT_MIN;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				max = max > visited[j][k][i] ? max : visited[j][k][i];
			}
		}
	}
	cout << max-1;
	return 0;
}