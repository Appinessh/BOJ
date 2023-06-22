#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp;
int main(void)
{
	int n;
	cin >> n;
	dp.resize(10);
	for (int i = 0; i < 10; i++)
	{
		dp[i].resize(n);
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				int result = 0;
				for (int k = 0; k <= i ; k++)
				{
					result = result + dp[k][j - 1];
				}
				result = result % 10007;
				dp[i][j] = result;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 10; i++)
	{
		answer = answer + dp[i][n - 1];
	}
	answer = answer % 10007;
	cout << answer;
	return 0;
}