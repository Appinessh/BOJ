#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int test_case;
int number_coin;
vector<int> coin;
vector<vector<int>> dp;
int money;
int main(void)
{
	cin >> test_case;
	while (test_case > 0)
	{
		test_case--;
		cin >> number_coin;
		coin.resize(0);
		coin.resize(number_coin);
		for(int i=0;i<number_coin;i++)
		{
			cin >> coin[i];
		}
		cin >> money;
		dp.resize(0);
		dp.resize(number_coin);
		for (int i = 0; i < number_coin; i++)
		{
			dp[i].resize(money + 1);
		}
		for (int i = 0; i < number_coin; i++)
		{
			for (int j = 0; j <= money; j++)
			{
				if (j == 0)
				{
					dp[i][j] = 1;
					continue;
				}

				if (i != 0)
				{
					for (int k = 0; j - k >= 0; k += coin[i])
					{
						dp[i][j] += dp[i - 1][j - k];
					}
				}
				else if(j%coin[i]==0)
				{
					dp[i][j] = 1;
				}
			}
		}
		cout << dp[number_coin - 1][money]<<"\n";
	}
	return 0;
}