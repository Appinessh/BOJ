#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp;
vector<int> input;
void calculation(void)
{
	for (int i = 0; i < dp.size(); i++)
	{
		if (i == 0)
		{
			dp[i][0] = input[i];
			dp[i][1] = 0;
		}
		else if (i==1)
		{
			dp[i][0] = input[i];
			dp[i][1] = input[i] + input[i - 1];
		}
		else
		{
			dp[i][0] = input[i] + (dp[i - 2][0] > dp[i - 2][1] ? dp[i - 2][0] : dp[i - 2][1]);
			dp[i][1] = input[i] + dp[i - 1][0];
		}
	}
}
int main(void)
{
	int n;
	cin >> n;
	dp.resize(n);
	input.resize(n);
	for (int i = 0; i < n; i++)
	{
		dp[i].resize(2);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	calculation();
	int answer = dp[n - 1][0] > dp[n - 1][1] ? dp[n - 1][0] : dp[n - 1][1];
	cout << answer << endl;
	return 0;
}