#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> computers;
vector<vector<int>> map;
vector<vector<int>> direction = { {-1,0},{1,0},{0,-1},{0,1} };
struct coordinates {
	int index1;
	int index2;
	int val;
};
queue <coordinates> q;
int n, m;
int bfs(void)
{
	if (q.empty())
	{
		return 0;
	}
	coordinates new_one;
	new_one = q.front();
	q.pop();
	for (int i = 0; i < 4; i++)
	{
		if (new_one.index1 + direction[i][0] >= 0 && new_one.index2 + direction[i][1] >= 0 && new_one.index1 + direction[i][0] < n && new_one.index2 + direction[i][1] < m)
		{
			if (map[new_one.index1 + direction[i][0]][new_one.index2 + direction[i][1]] == 1)
			{
				map[new_one.index1 + direction[i][0]][new_one.index2 + direction[i][1]] = new_one.val + 1;
				coordinates new_two;
				new_two.index1 = new_one.index1 + direction[i][0];
				new_two.index2 = new_one.index2 + direction[i][1];
				new_two.val = new_one.val + 1;
				q.push(new_two);
			}
		}
	}
	bfs();
	return 0;
}
int main(void) 
{
	cin >> n >> m;
	map.resize(n);
	coordinates new_coord;
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				new_coord.index1 = i;
				new_coord.index2 = j;
			}
		}
	}
	new_coord.val = 2;
	q.push(new_coord);
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && i != new_coord.index1 && j != new_coord.index2)
			{
				cout << -1<<" ";
			}
			else if (i == new_coord.index1 && j == new_coord.index2)
			{
				cout << 0<<" ";
			}
			else if (map[i][j] == 0)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << map[i][j] - 2 << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}