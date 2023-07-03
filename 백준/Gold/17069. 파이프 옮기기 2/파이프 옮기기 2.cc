#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<long long int>> map;
vector<vector<long long int>> map_1;
vector<vector<long long int>> map_2;
vector<vector<long long int>> map_3;
int main(void)
{
	int n;
	cin >> n;
	map.resize(n);
	map_1.resize(n);
	map_2.resize(n);
	map_3.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(n);
		map_1[i].resize(n);
		map_2[i].resize(n);
		map_3[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;
			map_1[i][j] = 0;
			map_2[i][j] = 0;
			map_3[i][j] = 0;
		}
	}
	map_1[0][1] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map_1[0][1] = 1;
			if (map[i][j] == 0)
			{
				if (j > 0)
				{
					map_1[i][j] = map_2[i][j - 1] + map_1[i][j - 1];
				}
			}
			if (map[i][j] == 0)
			{
				if (i > 0 && j > 0 && map[i - 1][j] == 0 && map[i][j - 1] == 0)
				{
					map_2[i][j] = map_3[i - 1][j - 1] + map_1[i - 1][j - 1] + map_2[i - 1][j - 1];
				}
			}
			if (map[i][j] == 0)
			{
				if (i > 0)
				{
					map_3[i][j] = map_3[i - 1][j] + map_2[i - 1][j];
				}
			}
		}
	}
	cout << map_1[n - 1][n - 1] + map_2[n - 1][n - 1] + map_3[n - 1][n - 1] << endl;
	return 0;
}