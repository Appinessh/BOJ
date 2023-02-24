#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		cout<<binary_search(v.begin(),v.end(), a)<<" ";
	}
	return 0;
}