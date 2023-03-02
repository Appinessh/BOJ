#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n;
	cin >> k;
	vector<int> coin(n);
	int count = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
		if (coin[i] <= k)
		{
			count++;
		}
	}
	sort(coin.begin(), coin.end());
	vector<int> dp1(k + 1, 0);
	vector<int> dp2(k + 1, 0);
	for (int i = 0; i <= count; i++)
	{
		if (i == 0)
		{
			for (int j = coin[i]; j <= k; j = j + coin[i])
			{
				dp2[j] = 1;
			}
		}
		else
		{
			for (int j = 0; j <= k; j++)
			{
				dp1[j] = dp2[j];
				dp2[j] = 0;
			}
			for (int j = coin[i]; j <= k; j = j + coin[i])
			{
				dp2[j] = 1;
			}
			for (int j = 1; j <= k; j++)
			{
				int number = 0;
				while (j - coin[i] * number >= 1)
				{
					dp2[j] = dp2[j] + dp1[j - coin[i] * number];
					number++;
				}
			}
		}
	}
	cout << dp2[k];
	return 0;
}