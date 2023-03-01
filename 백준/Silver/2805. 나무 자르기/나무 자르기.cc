#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int calcu(vector<int> tree, int height)
{
	long long int sum = 0;
	for (int i = 0; i < tree.size(); i++)
	{
		if (tree[i] <= height)
		{

		}
		else
		{
			sum = sum + tree[i] - height;
		}
	}
	return sum;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	cin >> m;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	int max = *max_element(h.begin(), h.end());
	int min = 0;
	int mid = (max + min) / 2;
	while (min<max&&min<mid)
	{
		if (calcu(h, mid) > m)
		{
			min = mid;
			mid = (max + min) / 2;
		}
		else if (calcu(h, mid) == m)
		{

			break;
		}
		else
		{
			max = mid;
			mid = (max + min) / 2;
		}
	}
	cout << mid;
	return 0;
}