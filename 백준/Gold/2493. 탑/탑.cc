#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef struct node{
	int height;
	int index;
}node;
int main()
{
	int n;
	cin >> n;
	vector<node> v(n);
	vector<int> answer(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].height;
		v[i].index = i + 1;
	}
	stack<node> st;
	answer[0] = 0;
	st.push(v[0]);
	int pos = 1;
	while (pos <= n - 1)
	{
		node temp, now;
		temp = st.top();
		now = v[pos];
		if (temp.height >= now.height)
		{
			answer[pos] = temp.index;
			st.push(now);
			pos++;
		}
		else
		{
			while (!st.empty())
			{
				temp = st.top();
				if (temp.height >= now.height)
				{
					answer[pos] = temp.index;
					st.push(now);
					pos++;
					break;
				}
				else
				{
					st.pop();
				}
			}
			if (st.empty())
			{
				answer[pos] = 0;
				st.push(now);
				pos++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}