#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> map;
vector<int> divide_conquer(int index1, int index2, int size)
{
	vector<int> result(3);
	if (size == 1)
	{
		if (map[index1][index2] == -1)
		{
			result[0] = 1;
		}
		else if (map[index1][index2] == 0)
		{
			result[1] = 1;
		}
		else
		{
			result[2] = 1;
		}
		return result;
	}
	else
	{
		vector<int> temp00 = divide_conquer(index1, index2, size / 3);
		vector<int> temp01 = divide_conquer(index1, index2 + size / 3, size / 3);
		vector<int> temp02 = divide_conquer(index1, index2 + 2 * size / 3, size / 3);
		vector<int> temp10 = divide_conquer(index1 + size / 3, index2, size / 3);
		vector<int> temp11 = divide_conquer(index1 + size / 3, index2 + size / 3, size / 3);
		vector<int> temp12 = divide_conquer(index1 + size / 3, index2 + 2 * size / 3, size / 3);
		vector<int> temp20 = divide_conquer(index1 + 2 * size / 3, index2, size / 3);
		vector<int> temp21 = divide_conquer(index1 + 2 * size / 3, index2 + size / 3, size / 3);
		vector<int> temp22 = divide_conquer(index1 + 2 * size / 3, index2 + 2 * size / 3, size / 3);
		result[0] = temp00[0] + temp01[0] + temp02[0] + temp10[0] + temp11[0] + temp12[0] + temp20[0] + temp21[0] + temp22[0];
		result[1] = temp00[1] + temp01[1] + temp02[1] + temp10[1] + temp11[1] + temp12[1] + temp20[1] + temp21[1] + temp22[1];
		result[2] = temp00[2] + temp01[2] + temp02[2] + temp10[2] + temp11[2] + temp12[2] + temp20[2] + temp21[2] + temp22[2];
		if (temp00[0] == 1 && temp00[1] == 0 && temp00[2] == 0 && temp01[0] == 1 && temp01[1] == 0 && temp01[2] == 0 && temp02[0] == 1 && temp02[1] == 0 && temp02[2] == 0 && temp10[0] == 1 && temp10[1] == 0 && temp10[2] == 0 && temp11[0] == 1 && temp11[1] == 0 && temp11[2] == 0 && temp12[0] == 1 && temp12[1] == 0 && temp12[2] == 0 && temp20[0] == 1 && temp20[1] == 0 && temp20[2] == 0 && temp21[0] == 1 && temp21[1] == 0 && temp21[2] == 0 && temp22[0] == 1 && temp22[1] == 0 && temp22[2] == 0)
		{
			result[0] = 1;
		}
		if (temp00[0] == 0 && temp00[1] == 1 && temp00[2] == 0 && temp01[0] == 0 && temp01[1] == 1 && temp01[2] == 0 && temp02[0] == 0 && temp02[1] == 1 && temp02[2] == 0 && temp10[0] == 0 && temp10[1] == 1 && temp10[2] == 0 && temp11[0] == 0 && temp11[1] == 1 && temp11[2] == 0 && temp12[0] == 0 && temp12[1] == 1 && temp12[2] == 0 && temp20[0] == 0 && temp20[1] == 1 && temp20[2] == 0 && temp21[0] == 0 && temp21[1] == 1 && temp21[2] == 0 && temp22[0] == 0 && temp22[1] == 1 && temp22[2] == 0)
		{
			result[1] = 1;
		}
		if (temp00[0] == 0 && temp00[1] == 0 && temp00[2] == 1 && temp01[0] == 0 && temp01[1] == 0 && temp01[2] == 1 && temp02[0] == 0 && temp02[1] == 0 && temp02[2] == 1 && temp10[0] == 0 && temp10[1] == 0 && temp10[2] == 1 && temp11[0] == 0 && temp11[1] == 0 && temp11[2] == 1 && temp12[0] == 0 && temp12[1] == 0 && temp12[2] == 1 && temp20[0] == 0 && temp20[1] == 0 && temp20[2] == 1 && temp21[0] == 0 && temp21[1] == 0 && temp21[2] == 1 && temp22[0] == 0 && temp22[1] == 0 && temp22[2] == 1)
		{
			result[2] = 1;
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
	vector<int> result(3);
	result=divide_conquer(0, 0, n);
	cout << result[0] << "\n" << result[1] << "\n" << result[2];
	return 0;
}