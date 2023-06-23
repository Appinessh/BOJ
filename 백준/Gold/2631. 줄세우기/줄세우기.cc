#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	vector<int> arr1;
	vector<int> arr2;
	vector<vector<int>> map;
	cin >> n;
	arr1.resize(n);
	arr2.resize(n);
	map.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(n);
		cin >> arr1[i];
		arr2[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
			{
				if (arr1[i] == arr2[j])
				{
					map[i][j] = 1;
				}
				else
				{
					map[i][j] = 0;
				}
			}
			else if (i == 0 && j != 0)
			{
				if (map[i][j - 1] == 1)
				{
					map[i][j] = 1;
				}
				else if(arr1[i]==arr2[j])
				{
					map[i][j] = 1;
				}
				else
				{
					map[i][j] = 0;
				}
			}
			else if (i != 0 && j == 0)
			{
				if (map[i - 1][j] == 1)
				{
					map[i][j] = 1;
				}
				else if (arr1[i] == arr2[j])
				{
					map[i][j] = 1;
				}
				else
				{
					map[i][j] = 0;
				}
			}
			else if (arr1[i] == arr2[j])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
			{
				map[i][j] = map[i][j - 1] > map[i - 1][j] ? map[i][j - 1] : map[i - 1][j];
			}
		}
	}
	cout << n - map[n - 1][n - 1];
	return 0;
}