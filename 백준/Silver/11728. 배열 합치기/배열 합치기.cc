#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n;
	cin >> k;
	vector<int> v(n + k);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]<<" ";
	}
	return 0;
}