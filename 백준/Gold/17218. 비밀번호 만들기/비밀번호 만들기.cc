#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> dp;
vector<char> answer;
int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;
	int n, m;
	n = str1.size();
	m = str2.size();
	dp.resize(n);
	for (int i = 0; i < n; i++)
	{
		dp[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(i==0&&j==0)
			{
				if (str1[i] == str2[j])
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = 0;
				}
			}
			else if (i == 0 && j != 0)
			{
				if (dp[i][j - 1] == 0)
				{
					if (str1[i] == str2[j])
					{
						dp[i][j] = 1;
					}
					else
					{
						dp[i][j] = 0;
					}
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
				}
			}
			else if (i != 0 && j == 0)
			{
				if (dp[i - 1][j] == 0)
				{
					if (str1[i] == str2[j])
					{
						dp[i][j] = 1;
					}
					else
					{
						dp[i][j] = 0;
					}
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
			else
			{
				if (str1[i] == str2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
				}
			}
		}
	}
	int pointer1 = n - 1;
	int pointer2 = m - 1;
	while (pointer1 >= 0 && pointer2 >= 0)
	{
		if (dp[pointer1][pointer2] == 0)
		{
			break;
		}
		else
		{
			if (pointer1 == 0)
			{
				if (str1[pointer1] == str2[pointer2])
				{
					answer.push_back(str1[pointer1]);
					pointer2--;
					break;
				}
				else
				{
					pointer2--;
				}
			}
			else if (pointer2 == 0)
			{
				if (str1[pointer1] == str2[pointer2])
				{
					answer.push_back(str2[pointer2]);
					break;
				}
				pointer1--;
			}
			else
			{
				if (dp[pointer1][pointer2] == dp[pointer1 - 1][pointer2])
				{
					pointer1--;
				}
				else if (dp[pointer1][pointer2] == dp[pointer1][pointer2 - 1])
				{
					pointer2--;
				}
				else
				{
					answer.push_back(str1[pointer1]);
					pointer1--;
					pointer2--;
				}
			}
		}
	}
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[answer.size()-1-i];
	}
	return 0;
}