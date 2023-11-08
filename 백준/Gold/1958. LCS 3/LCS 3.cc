#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<vector<int>>> dp;
int find_max(int index1, int index2, int index3)
{
	int result = dp[index1 - 1][index2][index3] > dp[index1][index2 - 1][index3] ? dp[index1 - 1][index2][index3] : dp[index1][index2 - 1][index3];
	result = result > dp[index1][index2][index3 - 1] ? result : dp[index1][index2][index3 - 1];
	return result;
}
int main(void)
{
	string str1;
	string str2;
	string str3;
	cin >> str1 >> str2 >> str3;
	dp.resize(str1.size());
	for (int i = 0; i < str1.size(); i++)
	{
		dp[i].resize(str2.size());
	}
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			dp[i][j].resize(str3.size());
		}
	}
	for (int k = 0; k < str3.size(); k++)
	{
		for (int i = 0; i < str1.size(); i++)
		{
			for (int j = 0; j < str2.size(); j++)
			{
				if (i * j * k > 0)
				{
					if (str1[i] == str2[j] && str2[j] == str3[k])
					{
						dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					}
					else
					{
						dp[i][j][k] = find_max(i, j, k);
					}
				}
				else
				{
					if (i == 0 && j == 0 && k == 0)
					{
						if (str1[i] == str2[j] && str2[j] == str3[k])
						{
							dp[i][j][k] = 1;
						}
						else
						{
							dp[i][j][k] = 0;
						}
					}
					else if (i == 0 && j != 0 && k == 0)
					{
						if (dp[i][j-1][k] == 1)
						{
							dp[i][j][k] = 1;
						}
						else if (str2[j] == str1[i] && str1[i] == str3[k])
						{
							dp[i][j][k] = 1;
						}
						else
						{
							dp[i][j][k] = 0;
						}
					}
					else if (i != 0 && j == 0 && k == 0)
					{
						if (dp[i-1][j][k] == 1)
						{
							dp[i][j][k] = 1;
						}
						else if (str2[j] == str1[i] && str1[i] == str3[k])
						{
							dp[i][j][k] = 1;
						}
						else
						{
							dp[i][j][k] = 0;
						}
					}
					else if (i != 0 && j != 0 && k == 0)
					{
						if (dp[i - 1][j][k] == 1||dp[i][j-1][k]==1)
						{
							dp[i][j][k] = 1;
						}
						else if (str2[j] == str1[i] && str1[i] == str3[k])
						{
							dp[i][j][k] = 1;
						}
						else
						{
							dp[i][j][k] = 0;
						}
					}
					else if (i == 0 && j == 0 && k != 0)
					{
						if (dp[i][j][k-1] == 1)
						{
							dp[i][j][k] = 1;
						}
						else if (str2[j] == str1[i] && str1[i] == str3[k])
						{
							dp[i][j][k] = 1;
						}
						else
						{
							dp[i][j][k] = 0;
						}
					}
					else if (i == 0 && j != 0 && k != 0)
					{
						if (dp[i][j][k - 1] == 1|| dp[i][j-1][k] == 1)
						{
							dp[i][j][k] = 1;
						}
						else if (str2[j] == str1[i] && str1[i] == str3[k])
						{
							dp[i][j][k] = 1;
						}
						else
						{
							dp[i][j][k] = 0;
						}
					}
					else
					{
						if (dp[i][j][k - 1] == 1 || dp[i-1][j][k] == 1)
						{
							dp[i][j][k] = 1;
						}
						else if (str2[j] == str1[i] && str1[i] == str3[k])
						{
							dp[i][j][k] = 1;
						}
						else
						{
							dp[i][j][k] = 0;
						}
					}
				}
			}
		}
	}
	cout << dp[str1.size()-1][str2.size()-1][str3.size()-1];
	return 0;
}