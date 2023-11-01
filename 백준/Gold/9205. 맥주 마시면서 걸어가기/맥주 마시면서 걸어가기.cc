#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct node {
	int index1;
	int index2;
};
vector<vector<int>> adj_list;
int n;
int indicator;
vector<node> location;
vector<int> vist;
int distance(int index1, int index2)
{
	return abs(location[index1].index1 - location[index2].index1) + abs(location[index1].index2 - location[index2].index2);
}
void dfs(int node_index)
{
	if (vist[n+1]==1||indicator==1)
	{
		indicator = 1;
		return ;
	}
	for (int i = 0;adj_list[node_index].size()>i;i++)
	{
		if (indicator == 1)
		{
			return;
		}
		if (vist[adj_list[node_index][i]]==0)
		{
			vist[adj_list[node_index][i]] = 1;
			dfs(adj_list[node_index][i]);
		}
	}
	return;
}
void make_adjlist(int index)
{
	if (index == 0)
	{
		return;
	}
	for (int i = 0; i < index; i++)
	{
		if (distance(i, index) <= 1000)
		{
			adj_list[i].push_back(index);
			adj_list[index].push_back(i);
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	cin >> test_case;
	while (test_case > 0)
	{
		test_case--;
		cin >> n;
		vist.resize(0);
		location.resize(0);
		adj_list.resize(0);
		vist.resize(n + 2);
		location.resize(n + 2);
		adj_list.resize(n + 2);
		indicator = 0;
		node new_node;
		for (int i = 0; i <= n + 1; i++)
		{
			cin >> new_node.index1 >> new_node.index2;
			location[i] = new_node;
			make_adjlist(i);
		}
		vist[0] = 1;
		dfs(0);
		if (indicator == 1)
		{
			cout << "happy\n";
		}
		else
		{
			cout << "sad\n";
		}
	}
	return 0;
}