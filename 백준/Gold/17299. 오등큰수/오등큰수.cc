#include  <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> vec(n);
	vector<int> answer(n);
	vector<int> count(1000001,0);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		count[vec[i]]++;
	}
	answer[n - 1] = -1;
	stack<int> st;
	st.push(vec[n - 1]);
	int pos = n - 2;
	while (pos >= 0)
	{
		int temp, now;
		now = vec[pos];
		temp = st.top();
		if (count[temp] > count[now])
		{
			answer[pos] = temp;
			st.push(now);
			pos--;
		}
		else
		{
			while (!st.empty())
			{
				temp = st.top();
				if (count[temp] > count[now])
				{
					answer[pos] = st.top();
					break;
				}
				else
				{
					st.pop();
				}
			}
			if (st.empty())
			{
				answer[pos] = -1;
			}
			st.push(now);
			pos--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}