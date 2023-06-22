#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 0;
vector<vector<int>> map;
vector<vector<int>> visited;
vector<vector<int>> direction = { {-1,0},{0,-1},{1,0},{0,1}};
void cleaning(int index1, int index2, int di)
{
	if (visited[index1][index2] == 0)
	{
		answer++;
		visited[index1][index2] = answer;

	}
	int indicator = 0;
	for (int i = 0; i < 4; i++)
	{
		if ((index1 + direction[(i + di + 1) % 4][0] < 0) || (index1 + direction[(i + di + 1) % 4][0] >= map.size()))
		{
			continue;
		}
		if ((index2 + direction[(i + di + 1) % 4][1] < 0) || (index2 + direction[(i + di + 1) % 4][1] >= map[0].size()))
		{
			continue;
		}
		if (map[index1 + direction[(i + di + 1) % 4][0]][index2 + direction[(i + di + 1) % 4][1]] != 1&&visited[index1+direction[(i+di+1)%4][0]][index2+direction[(i+di+1)%4][1]]==0)
		{

			cleaning(index1 + direction[(i + di + 1) % 4][0], index2 + direction[(i + di + 1) % 4][1], (i + di + 1) % 4);
			indicator = 1;
			break;
		}
	}
	if (indicator == 0)
	{

		if (map[index1 + direction[(di + 2) % 4][0]][index2 + direction[(di + 2) % 4][1]] != 1)
		{
			cleaning(index1 + direction[(di + 2) % 4][0], index2 + direction[(di + 2) % 4][1], di);
		}
		else
		{

		}
	}
}
int main(void)
{
	int n, m;
	int r, c, di;
	cin >> n >> m;
	cin >> r >> c >> di;
	r;
	c;
	map.resize(n);
	visited.resize(n);
	if (di == 1)
	{
		di = 3;
	}
	else if (di == 3)
	{
		di = 1;
	}
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
		visited[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;
			visited[i][j] = input;
		}
	}
	cleaning(r, c,di);
	cout << answer << endl;
	return 0;
}