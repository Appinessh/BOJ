#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long int power(long long int a, long long int b)
{
	long long int result;
	result = 1;
	while (b > 0)
	{
		result = result * a;
		b--;
	}
	return result;
}
vector<vector<vector<int>>> multiplication;
vector<vector<int>> answer;
vector<vector<int>> temp;
vector<int> cnt;
int main(void)
{
	int n;
	long long int b;
	cin >> n >> b;
	multiplication.resize(n);
	answer.resize(n);
	temp.resize(n);
	for (int i = 0; i < n; i++)
	{
		multiplication[i].resize(n);
		answer[i].resize(n);
		temp[i].resize(n);
	}
	long long int height = (long long int)log2(b)+3;
	cnt.resize(height + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0 ; j<n;j++)
		{
			multiplication[i][j].resize(height+1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> multiplication[i][j][0];
		}
	}
	for (int k = 1; k < height + 1; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int result = 0;
				for (int index = 0; index < n; index++)
				{
					result = result + multiplication[i][index][k - 1] * multiplication[index][j][k - 1];
				}
				result = result % 1000;
				multiplication[i][j][k] = result;
			}
		}
	}
	while (b != 0)
	{
		cnt[(int)log2(b)] = 1;
		b = b - power(2, (int)log2(b));
	}
	for (int i = 0; i < n; i++)
	{
		answer[i][i] = 1;
		temp[i][i] = 1;
	}
	for (int k = 0; k < height + 1; k++)
	{
		if (cnt[k] == 1)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					temp[i][j] = 0;
					for (int index = 0; index < n; index++)
					{
						temp[i][j] = temp[i][j] + answer[i][index] * multiplication[index][j][k];
					}

				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					answer[i][j] = temp[i][j]%1000;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}