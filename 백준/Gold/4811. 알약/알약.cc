#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<long long int>> dp;
int n;
int main(void)
{
	cin >> n;
	while (n!= 0)
	{
		dp.resize(0);
		dp.resize(n+1);
		for (int i = 0; i <= n; i++)
		{
			dp[i].resize(2 * n);
		}
		for (int i = 0; i < 2 * n; i++)
		{
			if (i < n)
			{
				for (int j = 0; j <= i+1; j++)
				{
					if (i == 0)
					{
						dp[0][i] = 0;
						dp[1][i] = 1;
					}
					else if (j==0)
					{
						dp[j][i] += dp[j+1][i - 1];
					}
					else if (j == i + 1)
					{
						dp[j][i] = 1;
					}
					else
					{
						dp[j][i] = dp[j-1][i-1] + dp[j + 1][i - 1];
					}
				}
			}
			else
			{
				for (int j = 0; j <= n - (i - n + 1); j++)
				{
					if (j == 0)
					{
						dp[j][i] = dp[j + 1][i - 1];
					}
					else
					{
						dp[j][i] = dp[j + 1][i - 1] + dp[j - 1][i - 1];
					}
				}
			}
		}
		cout << dp[0][2 * n - 1] << "\n";
		cin >> n;
	}
	return 0;
}