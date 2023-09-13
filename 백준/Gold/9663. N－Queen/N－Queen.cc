#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int cnt;
vector<vector<int>> map;
bool checker(int index1, int index2)
{
	for (int i = 0; i < index1; i++)
	{
		if (map[i][index2] != 0)
		{
			return false;
		}
		if (index1 + index2 - i >= 0 &&index1 + index2 - i < N && map[i][index1 + index2 - i] != 0)
		{
			return false;
		}
		if (index2 - index1 + i >= 0 && index2 - index1 + i < N && map[i][index2 - index1 + i] != 0)
		{
			return false;
		}
	}
	return true;
}
void backtracking(int current_number)
{
	if (current_number == N+1)
	{
		cnt++;
		return;
	}
	for (int j = 0; j < N; j++)
	{
		if (checker(current_number-1,j))
		{
			map[current_number - 1][j] = current_number;
			backtracking(current_number + 1);
			map[current_number - 1][j] = 0;
		}
	}
	return;
}
int main(void)
{
	cin >> N;
	map.resize(N);
	for (int i = 0; i < N; i++)
	{
		map[i].resize(N);
	}
	cnt = 0;
	backtracking(1);
	cout << cnt;
	return 0;
}