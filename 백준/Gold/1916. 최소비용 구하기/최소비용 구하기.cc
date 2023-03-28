#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int end;
	int cost;
};
struct compare {
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
bool cmp(node a, node b)
{
	return a.cost < b.cost;
}
vector<vector<node>> adjlist;
vector<int> visited;
priority_queue<int,vector<int>,compare> q;
void dfs(int start)
{
	visited[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		for (int i = 0; i < adjlist[u].size(); i++)
		{
			if (visited[adjlist[u][i].end] == 0)
			{
				visited[adjlist[u][i].end] = visited[u] + adjlist[u][i].cost;
				q.push(adjlist[u][i].end);
			}
			else if (visited[adjlist[u][i].end] > visited[u] + adjlist[u][i].cost)
			{
				visited[adjlist[u][i].end] = visited[u] + adjlist[u][i].cost;
				q.push(adjlist[u][i].end);
			}
			else
			{

			}
		}
	}
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	adjlist.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		node new_node;
		new_node.end = end;
		new_node.cost = cost;
		adjlist[start].push_back(new_node);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(adjlist[i].begin(), adjlist[i].end(),cmp);
	}
	int start, end;
	cin >> start >> end;
	dfs(start);
	cout << visited[end] - 1;
	return 0;
}