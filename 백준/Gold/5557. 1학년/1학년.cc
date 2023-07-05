#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<long long int> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<vector<long long int>> dp;
	dp.resize(21);
	for (int i = 0; i < 21; i++)
	{
		dp[i].resize(n);
	}
	dp[arr[0]][0]++;
	if (10 * arr[0] + arr[1] <= 20)
	{
		dp[10 * arr[0] + arr[1]][1] = 1;
	}
	if (arr[0] + arr[1] <= 20)
	{
		dp[arr[0] + arr[1]][1] = 1;
	}
	if (arr[0] - arr[1] >= 0)
	{
		dp[arr[0] - arr[1]][1]++;
	}
	for (int j = 2; j < n - 1; j++)
	{
		for (int i = 0; i < 21; i++)
		{
			if (i + arr[j] <= 20)
			{
				dp[i + arr[j]][j] = dp[i][j - 1] + dp[i + arr[j]][j];
			}
			if (i - arr[j] >= 0)
			{
				dp[i - arr[j]][j] = dp[i][j - 1] + dp[i - arr[j]][j];
			}
		}
	}
	cout << dp[arr[n - 1]][n - 2];
	return 0;
}