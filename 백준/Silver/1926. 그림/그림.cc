#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> direction = { {-1,0},{1,0},{0,-1},{0,1} };
int R, C;
int cnt;
int area;
vector<int> find_not_visited(int start)
{
	vector <int> res(2);
	res[0] = -1;
	res[1] = -1;
	for (int i = start; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 1)
			{
				res[0] = i;
				res[1] = j;
				return res;
			}
		}
	}
	return res;
}
void dfs(int index1, int index2)
{
	for (int i = 0; i < 4; i++)
	{
		if (index1 + direction[i][0] >= 0 && index1 + direction[i][0] < R)
		{
			if (index2 + direction[i][1] >= 0 && index2 + direction[i][1] < C)
			{
				if (map[index1 + direction[i][0]][index2 + direction[i][1]] == 1)
				{
					map[index1 + direction[i][0]][index2 + direction[i][1]] = cnt;
					area++;
					dfs(index1 + direction[i][0], index2 + direction[i][1]);
				}
			}
		}
	}
	return;
}
int main(void)
{
	cin >> R >> C;
	map.resize(R);
	for (int i = 0; i < R; i++)
	{
		map[i].resize(C);
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
	cnt = 0;
	vector<int> seed(2);
	seed = find_not_visited(0);
	int ans = 0;
	while (seed[0] != -1)
	{
		area = 0;
		cnt--;
		map[seed[0]][ seed[1]] = cnt;
		area++;
		dfs(seed[0], seed[1]);
		ans = ans > area ? ans : area;
		seed = find_not_visited(seed[0]);
	}
	cout << (-1) * cnt << "\n" << ans;
	return 0;
}