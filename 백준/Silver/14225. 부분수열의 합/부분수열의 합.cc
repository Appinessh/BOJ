#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int sum;
int n;
vector<int> number(20);
set<int> list;
int calculation(int index)
{
	if (index == n)
	{
		list.insert(sum);
		return 0;
	}
	sum = sum + number[index];
	calculation(index + 1);
	sum = sum - number[index];
	calculation(index + 1);
	return 0;
}
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}
	sum = 0;
	calculation(0);
	int counting = 1;
	while (list.find(counting) != list.end())
	{
		counting++;
	}
	cout << counting;
	return 0;
}