#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int move(int start, int end, int height)
{
	if (height == 1)
	{
		cout << start << " " << end << "\n";
		return 0;
	}
	int stopover;
	vector<int> direction(4);
	direction[start]++;
	direction[end]++;
	for (int i = 1; i <= 3; i++)
	{
		if (direction[i] == 0)
		{
			stopover = i;
			break;
		}
	}
	move(start, stopover, height - 1);
	cout << start << " " << end << "\n";
	move(stopover, end, height - 1);
	return 0;
}
int main(void)
{
	int k;
	cin >> k;
	int answer = 1;
	if (k == 1)
	{
		cout << 1 << "\n";
	}
	else
	{
		for (int i = 2; i <= k; i++)
		{
			answer = 2 * answer + 1;
		}
		cout << answer << "\n";
	}
	move(1, 3, k);
	return 0;
}