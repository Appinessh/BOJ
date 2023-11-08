#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef struct node {
	int price;
	int people;
};
vector<node> city;
vector<int> dp;
int c, n;
int find_answer(void)
{
	for (int i = 0; i <= c+100; i++)
	{
		dp[i] = 100001;
		for (int j = 0; j < n; j++)
		{
			if (i - city[j].people > 0 && dp[i - city[j].people] == 0)
			{
				continue;
			}
			if (i - city[j].people >= 0&&dp[i-city[j].people]<100001)
			{
				dp[i] = dp[i]<(dp[i - city[j].people] + city[j].price)? dp[i] : (dp[i - city[j].people] + city[j].price);
			}
		}
		if (dp[i] >= 100001)
		{
			dp[i] = 0;
		}
	}
	int ans = 100001;
	for (int i = c; i <= c + 100; i++)
	{
		if (dp[i] < ans&&dp[i]!=0)
		{
			ans = dp[i];
		}
	}
	return  ans;
}
int main(void)
{
	cin >> c >> n;
	city.resize(n);
	dp.resize(c + 101);
	for (int i = 0; i < n; i++)
	{
		node new_node;
		cin >> new_node.price >> new_node.people;
		city[i] = new_node;
	}
	cout << find_answer();
	return 0;
}