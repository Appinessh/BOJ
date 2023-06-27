#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int x1, y1;
	int x2, y2;
	int x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	int answer_x, answer_y;
	if (x1 == x2)
	{
		answer_x = x3;
	}
	else
	{
		if (x1 == x3)
		{
			answer_x = x2;
		}
		if (x2 == x3)
		{
			answer_x = x1;
		}
	}
	if (y1 == y2)
	{
		answer_y= y3;
	}
	else
	{
		if (y1 == y3)
		{
			answer_y = y2;
		}
		if (y2 == y3)
		{
			answer_y = y1;
		}
	}
	cout << answer_x << " " << answer_y;
	return 0;
}