#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct item {
	int mass;
	int value;

	item(int mass, int value):mass(mass),value(value){}
};
struct compare_mass {
	bool operator()(item item1, item item2)
	{
		return item1.mass > item2.mass;
	}
};
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n;
	cin >> k;
	priority_queue<item, vector<item>, compare_mass> pq;
	vector<int> bag(k);
	priority_queue<int> jew;
	for (int i = 0; i < n; i++)
	{
		int mass, value;
		cin >> mass;
		cin >> value;
		item temp(mass, value);
		pq.push(temp);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> bag[i];
	}
	sort(bag.begin(), bag.end());
	int last_index = 0;
	long long int answer = 0;
	while (last_index!=k&&(!jew.empty()||!pq.empty()))
	{
		if (!pq.empty())
		{
			while (!pq.empty()&&pq.top().mass <= bag[last_index] )
			{
				int ne = pq.top().value;
				pq.pop();
				jew.push(ne);
			}
		}
		if (jew.empty())
		{

		}
		else
		{
			answer = answer + jew.top();
			jew.pop();
		}
		last_index++;
	}
	cout << answer;
	return 0;
}