#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <list>
using namespace std;
vector<vector<int>> linked_list;
int main(void)
{
	int n;
	cin >> n;
	vector<int> arr;
	vector<int> dp;
	dp.resize(n);
	arr.resize(n);
	linked_list.resize(n);
	for (int i = 0; i < n; i++)
	{
		int input;
		int max=1;
		int ind=-1;
		cin >> input;
		arr[i] = input;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				max =max> (dp[j] + 1)?max:(dp[j]+1);
				if (max == dp[j] + 1)
				{
					ind = j;
				}
			}
		}
		dp[i] = max;
		if (ind != -1)
		{
			for (int j = 0; j < linked_list[ind].size(); j++)
			{
				linked_list[i].push_back(linked_list[ind][j]);
			}
		}
		linked_list[i].push_back(arr[i]);
	}
	int index;
	int maxi=INT_MIN;
	for (int i = 0; i < n; i++)
	{
		maxi = maxi > dp[i] ? maxi : dp[i];
		if (maxi == dp[i])
		{
			maxi = dp[i];
			index = i;
		}

	}
	cout << maxi << endl;
	for (int i = 0; i < linked_list[index].size(); i++)
	{
		cout << linked_list[index][i]<<" ";
	}
	return 0;
}