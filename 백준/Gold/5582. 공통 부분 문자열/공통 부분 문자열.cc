#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
vector<vector<int>> map;
int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;
	int n, m;
	int max = -1;
	n = str1.size();
	m = str2.size();
	map.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)
			{
				if (str1[i] == str2[j])
				{
					map[i][j] = 1;
				}
				else
				{
					map[i][j] = 0;
				}
			}
			else if (str1[i] == str2[j])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
			{
				map[i][j] = 0;
			}
			max = max > map[i][j] ? max : map[i][j];
		}
	}
	cout << max;
	return 0;
}