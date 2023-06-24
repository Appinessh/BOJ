#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> map;
int main(void)
{
	int n, k;
	cin >> n >> k;
	map.resize(n + 1);
	for (int i = 0; i < n + 1; i++)
	{
		map[i].resize(k + 1);
	}
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < k + 1; j++)
		{
			if (j == 0)
			{
				map[i][j] = 0;
			}
			else if (i == 0 || j == 1)
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = map[i - 1][j] + map[i][j - 1];
				map[i][j] = map[i][j] % 1000000000;
			}
		}
	}
	cout << map[n][k];
	return 0;
}