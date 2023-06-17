#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
vector<vector<int>> map;
string answer;
int main(void)
{
	string st1, st2;
	cin >> st1 >> st2;
	string ans;
	int n1, n2;
	n1 = st1.length();
	n2 = st2.length();
	map.resize(n1);
	for (int i = 0; i < n1; i++)
	{
		map[i].resize(n2);
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (i >= 1 && j >= 1)
			{
				if (st1[i] == st2[j])
				{
					map[i][j] = map[i - 1][j - 1] + 1;
				}
				else
				{
					map[i][j] = max(map[i - 1][j], map[i][j - 1]);
				}
			}
			else if (i == 0 && j != 0)
			{
				if (map[i][j - 1] != 0)
				{
					map[i][j] = map[i][j - 1];
				}
				else
				{
					if (st1[i] == st2[j])
					{
						map[i][j] = 1;
					}
				}
			}
			else if (i != 0 && j == 0)
			{
				if (map[i - 1][j] != 0)
				{
					map[i][j] = map[i - 1][j];
				}
				else
				{
					if (st1[i] == st2[j])
					{
						map[i][j] = 1;
					}
				}
			}
			else
			{
				if (st1[i] == st2[j])
				{
					map[i][j] = 1;
				}
				else
				{
					map[i][j] = 0;
				}
			}
		}
	}
	int index1, index2;
	index1 = n1 - 1;
	index2 = n2 - 1;
	int indicator = 1;
	while ((index1 != 0 || index2 != 0) || indicator != 0)
	{
		if (map[index1][index2] == 0)
		{
			break;
		}
		if (index1 != 0 && index2 != 0)
		{
			if (st1[index1] == st2[index2])
			{
				answer.push_back(st1[index1]);
				index1--;
				index2--;
			}
			else
			{
				if (map[index1 - 1][index2] > map[index1][index2 - 1])
				{
					index1--;
				}
				else if (map[index1 - 1][index2] < map[index1][index2 - 1])
				{
					index2--;
				}
				else
				{
					if (index1 > index2)
					{
						index1--;
					}
					else
					{
						index2--;
					}
				}
			}
		}
		else if (index1 == 0 && index2 != 0)
		{
			if (st1[index1] == st2[index2]&&map[index1][index2]!=map[index1][index2-1])
			{
				answer.push_back(st1[index1]);
				index2--;
			}
			else
			{
				index2--;
			}
		}
		else if (index2 == 0 && index1 != 0)
		{

			if (st1[index1] == st2[index2]&&map[index1][index2]!=map[index1-1][index2])
			{
				answer.push_back(st1[index1]);

				index1--;
			}
			else
			{
				index1--;
			}
		}
		else
		{
			if (st1[index1] == st2[index2])
			{
				answer.push_back(st1[index1]);
			}
			indicator = 0;
		}
	}
	cout << map[n1 - 1][n2 - 1] << endl;
	reverse(answer.begin(), answer.end());
	cout << answer << endl;
	return 0;
}