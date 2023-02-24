#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(10);
	int cnt = 1;
	while (n!= 0)
	{
		v[cnt - 1] = (n % (int)pow(10, cnt))/(int)pow(10,cnt-1);
		n = n - n % (int)pow(10, cnt);
		cnt++;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < cnt-1; i++)
	{
		cout << v[i];
	}
	return 0;
}