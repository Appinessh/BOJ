#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> map;
vector<int> divide_conquer(int index1, int index2, int size)
{
	vector<int> result(2);
	if (size == 1)
	{
		if (map[index1][index2] == 1)
		{
			result[1] = 1;
		}
		else
		{
			result[0] = 1;
		}
		return result;
	}
	else
	{
		vector<int> temp1 = divide_conquer(index1, index2, size / 2);
		vector<int> temp2 = divide_conquer(index1 + size / 2, index2, size / 2);
		vector<int> temp3 = divide_conquer(index1, index2 + size / 2, size / 2);
		vector<int> temp4 = divide_conquer(index1 + size / 2, index2 + size / 2, size / 2);
		result[0] = temp1[0] + temp2[0] + temp3[0] + temp4[0];
		result[1] = temp1[1] + temp2[1] + temp3[1] + temp4[1];
		if (temp1[0] == 1 && temp2[0] == 1 && temp3[0] == 1 && temp4[0] == 1&&temp1[1]==0&&temp2[1]==0&&temp3[1]==0&&temp4[1]==0)
		{
			result[0] = 1;
		}
		if (temp1[1] == 1 && temp2[1] == 1 && temp3[1] == 1 && temp4[1] == 1&&temp1[0]==0&&temp2[0]==0&&temp3[0]==0&&temp4[0]==0)
		{
			result[1] = 1;
		}
		return result;
	}
}
int main(void)
{
	int n;
	cin >> n;
	map.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	vector<int> answer= divide_conquer(0, 0, n);
	cout << answer[0] << "\n";
	cout << answer[1];
	return 0;
}