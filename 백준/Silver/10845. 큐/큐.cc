#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	queue<int> qu;
	for (int i = 0; i < n; i++)
	{

		char str[10];
		cin >> str;
		if (strcmp(str, "push") == 0)
		{
			int input;
			cin >> input;
			qu.push(input);
		}
		else if (strcmp(str, "front") == 0)
		{
			if (qu.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << qu.front() << endl;
			}
		}
		else if (strcmp(str, "back") == 0)
		{
			if (qu.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << qu.back() << endl;
			}
		}
		else if (strcmp(str, "empty") == 0)
		{
			if (qu.empty())
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (strcmp(str, "size") == 0)
		{
			cout << qu.size() << endl;
		}
		else
		{
			if (qu.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << qu.front() << endl;
				qu.pop();
			}
		}
	}
	return 0;
}