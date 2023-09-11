#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector <int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	int max = -1;
	do {
		int calculation = 0;
		for (int i=0;i<n-1;i++)
		{
			calculation = calculation + abs(vec[i] - vec[i + 1]);
		}
		max = max > calculation ? max : calculation;
	} while (next_permutation(vec.begin(), vec.end()));
	cout << max;
	return 0;
}