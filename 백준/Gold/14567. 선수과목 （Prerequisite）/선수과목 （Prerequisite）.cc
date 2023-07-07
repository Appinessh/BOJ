#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> number_subject;
vector<vector<int>> pre_requisite;
int main(void)
{
	int n, m;
	cin >> n >> m;
	number_subject.resize(n);
	pre_requisite.resize(n);
	for (int i = 0; i < n; i++)
	{
		pre_requisite[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		int index1, index2;
		cin >> index1 >> index2;
		pre_requisite[index1-1][index2-1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			number_subject[i] = 1;
		}
		else
		{
			int max = 0;
			for (int k = 0; k < i; k++)
			{
				if (pre_requisite[k][i] == 1)
				{
					max = max > number_subject[k] ? max : number_subject[k];
				}
			}
			max++;
			number_subject[i] = max;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << number_subject[i] << " ";
	}
	return 0;
}