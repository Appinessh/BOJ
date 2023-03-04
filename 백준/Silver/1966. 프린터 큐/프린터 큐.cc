#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int func(void)
{
	int number_files, index;
	cin >> number_files;
	cin >> index;
	queue<int> q;
	priority_queue<int>pq;
	for (int i = 0; i < number_files; i++)
	{
		int a;
		cin >> a;
		q.push(a);
		pq.push(a);
	}
	int tracking_index = index;
	int count = 0;
	while (1)
	{
		if (tracking_index == 0)
		{
			if (q.front() == pq.top())
			{
				count++;
				break;
			}
			else
			{
				int a = q.front();
				q.pop();
				q.push(a);
				tracking_index = q.size() - 1;
			}
		}
		else
		{
			if (q.front() ==pq.top())
			{
				count++;
				q.pop();
				pq.pop();
				tracking_index--;
			}
			else
			{
				int a;
				a = q.front();
				q.pop();
				q.push(a);
				tracking_index--;
			}
		}
	}
	return count;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		cout << func()<<endl;
	}
	return 0;
}