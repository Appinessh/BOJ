#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main(void)
{
	string s;
	cin >> s;
	vector<int> arr;
	int input;
	arr.resize(s.size());
	for (int i = 0; i < s.size(); i++)
	{
		arr[i] = s[i] - '0';
	}

	int n = arr.size();
	vector<int> dp;
	dp.resize(n);
	for (int i = 0; i < n; i++)
	{
		dp[i] = 0;
		if (i==0)
		{
			if (arr[i] == 0)
			{
				dp[i] = 0;
			}
			else
			{
				dp[i] = 1;
			}
		}
		else if (i == 1)
		{
			if (arr[i] != 0)
			{
				dp[i] = dp[i - 1];
			}
			int a;
			a = 10 * arr[i - 1] + arr[i];
			if (a >= 10 && a <= 26)
			{
				dp[i] = dp[i] + 1;
			}
		}
		else
		{
			if (arr[i] != 0)
			{
				dp[i] = dp[i - 1];
			}
			int a;
			a= 10 * arr[i - 1] + arr[i];
			if (a >= 10 && a <= 26)
			{
				dp[i] = dp[i] + dp[i - 2];
			}
		}
		dp[i] = dp[i] % 1000000;
	}
	cout << dp[n - 1];
	return 0;
}