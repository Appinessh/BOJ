#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int is_it_palin(int n)
{
	int cnt = 0;
	int temp = n;
	vector<int> number;
	while (1)
	{
		number.push_back(temp % 10);
		if (temp / 10 == 0)
		{
			break;
		}
		temp = temp / 10;
		cnt++;
	}
	int index1=cnt, index2 = 0;
	int indicator=1;
	for (int i = 0; i <= cnt / 2; i++)
	{
		if (number[index1 - i] != number[index2 + i])
		{
			indicator = 0;
			break;
		}
	}
	return indicator;
}
vector<int> vec;
int main(void)
{
	int n;
	cin >> n;
	vec.resize(10 * n);
	for (int i = 2; i<10 * n - 1;i++)
	{

		if (vec[i]==0 && i >= n && is_it_palin(i))
		{
			cout << i;
			return 0;
		}
		if (vec[i] == 0)
		{
			for (int j = i + i; j < 10 * n - 1; j += i)
			{
				vec[j] = 1;
			}
		}
	}
}