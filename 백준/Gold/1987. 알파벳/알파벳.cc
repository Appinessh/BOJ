#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c;
vector<int> dy = { -1,1,0,0 };
vector<int> dx = { 0,0,-1,1 };
vector<vector<char>> map;
vector<int> alphabet(26);
int maxi = 1;
void dfs(int index1, int index2, int find_path)
{
	for (int i = 0; i < 4; i++)
	{
		if (index1 + dy[i] >= 0 && index1 + dy[i] < map.size())
		{
			if (index2 + dx[i] >= 0 && index2 + dx[i] < map[0].size())
			{
				if (alphabet[(map[index1 + dy[i]][index2 + dx[i]] - '0') - 17] == 0)
				{
					alphabet[(map[index1 + dy[i]][index2 + dx[i]] - '0') - 17] = 1;
					maxi = maxi > find_path + 1 ? maxi : find_path + 1;
					dfs(index1 + dy[i], index2 + dx[i], find_path + 1);
					alphabet[(map[index1 + dy[i]][index2 + dx[i]] - '0') - 17]--;
				}
				else
				{

				}
			}
		}
	}
}
int main(void)
{
	cin >> r >> c;
	map.resize(r);
	for (int i = 0; i < r; i++)
	{
		map[i].resize(c);
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}
	alphabet[(map[0][0] - '0') - 17] = 1;
	dfs(0, 0, 1);
	cout << maxi;
	return 0;
}