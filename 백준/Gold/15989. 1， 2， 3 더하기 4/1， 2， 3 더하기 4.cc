#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp;
int T,n;
int main(void)
{
	cin >> T;
	while (T > 0)
	{
		T--;
		dp.resize(0);
		cin >> n;
		dp.resize(3);
		for (int i = 0; i < 3; i++)
		{
			dp[i].resize(n + 1);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0)
				{
					dp[i][j] = 1;
				}
				else if(j>=i+1)
				{
					dp[i][j] = dp[i][j - i - 1] + dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		cout << dp[2][n] << "\n";
	}
	return 0;
}