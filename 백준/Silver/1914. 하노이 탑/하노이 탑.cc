#include  <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
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
	string a = to_string(pow(2, k));
	int x = a.find(".");
	a = a.substr(0, x);
	a[a.length() - 1] -= 1;
	cout << a << "\n";
	if (k <= 20)
	{
		move(1, 3, k);
	}
	return 0;
}