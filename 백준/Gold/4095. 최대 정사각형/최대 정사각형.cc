#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> dp;
int min(int a, int b, int c)
{
	return (a<b ? a : b) < c ? (a < b ? a : b) : c;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	while (n != 0 || m != 0)
	{
		map.resize(0);
		dp.resize(0);
		map.resize(n);
		dp.resize(n);
		int result=0;

		for (int i = 0; i < n; i++)
		{
			map[i].resize(m);
			dp[i].resize(m);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int input;
				cin >> input;
				map[i][j] = input;
				dp[i][j] = input;
				result = result > input ? result : input;
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
				}
				result = result > dp[i][j] ? result : dp[i][j];
			}

		}
		cout << result<<"\n";
		cin >> n >> m;
	}
	return 0;
}