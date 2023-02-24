#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef struct node {
	int value;
	int count;
}node;
int main(void)
{
	int n;
	cin >> n;
	vector<node> v(n);
	stack<node> st;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].value;
		v[i].count = 1;
	}
	long long int sum = 0;
	st.push(v[n - 1]);
	int pos = n - 2;
	while (pos >= 0)
	{
		node temp, now;
		temp = st.top();
		now = v[pos];
		if (temp.value > now.value)
		{
			sum++;
			st.push(now);
			pos--;
		}
		else
		{
			while (!st.empty())
			{
				temp = st.top();
				if (temp.value > now.value)
				{
					sum++;
					st.push(now);
					pos--;
					break;
				}
				else if (temp.value == now.value)
				{
					sum = sum + temp.count;
					now.count = temp.count + 1;
					st.pop();
				}
				else
				{
					sum = sum + temp.count;
					st.pop();
				}
			}
			if (st.empty())
			{
				st.push(now);
				pos--;
			}
		}
	}
	cout << sum << endl;
	return 0;
}