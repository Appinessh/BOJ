#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n;
	cin>> k;
	vector <int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[k - 1];
	return 0;
}