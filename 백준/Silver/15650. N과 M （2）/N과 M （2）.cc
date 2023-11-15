#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, m;
vector<int> lst;
vector<int> sorted_lst;
vector<int> ans;
void get_ans(int depth)
{
	if (ans.size() == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = depth; i < sorted_lst.size(); i++)
	{
		ans.push_back(sorted_lst[i]);
		get_ans(i+1);
		ans.pop_back();
	}
	return;
}
int main(void)
{
	cin >> n >> m;
	lst.resize(n);
	set<int> s;
	set<int>::iterator sit;
	for (int i = 0; i < n; i++)
	{
		lst[i]=i+1;
		s.insert(lst[i]);
	}
	for (sit=s.begin();sit!=s.end();sit++)
	{
		sorted_lst.push_back(*sit);
	}
	sort(sorted_lst.begin(), sorted_lst.end());
	get_ans(0);
	return 0;
}