#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct item {
	int value;
	int index;

	item(int value, int index):value(value),index(index){}
};
struct compare {
	bool operator()(item item1, item item2)
	{
		return item1.value > item2.value;
	}
};
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l;
	cin >> n;
	cin >> l;
	vector <int> answer(n);
	priority_queue<item, vector<item>, compare> pq;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		item temp(a,i);
		pq.push(temp);
		item k = pq.top();
		while (k.index < i - l + 1)
		{
			pq.pop();
			k = pq.top();
		}
		answer[i] = pq.top().value;
	}
	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}