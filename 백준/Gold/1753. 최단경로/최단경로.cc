#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node
{
	int end;
	int weight;
	bool operator<(const node& a)const
	{
		return weight > a.weight;
	}
};
vector<vector<node>> graph;
priority_queue <node> pq;
vector<int> visited;
int bfs(int index)
{
	for (int i = 0; i < graph[index].size(); i++)
	{
		node new_node;
		new_node.end = graph[index][i].end;
		new_node.weight = graph[index][i].weight + visited[index];
		if (visited[new_node.end] == 0)
		{
			pq.push(new_node);
			visited[new_node.end] = new_node.weight;
		}
		else if(visited[new_node.end]> new_node.weight)
		{
			pq.push(new_node);
			visited[new_node.end] = new_node.weight;
		}
	}
	if (pq.empty())
	{
		return 0;
	}
	else
	{
		node new_node;
		new_node = pq.top();
		pq.pop();
		bfs(new_node.end);
	}
	return 0;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int vertex, edge;
	cin >> vertex >> edge;
	graph.resize(vertex + 1);
	visited.resize(vertex + 1);
	int start;
	cin >> start;
	for (int i = 0; i < edge; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		node new_node;
		new_node.weight = w;
		new_node.end = v;
		graph[u].push_back(new_node);
	}
	visited[start] = 1;
	bfs(start);
	for (int i = 1; i <= vertex; i++)
	{
		if (visited[i] == 0)
		{
			cout << "INF\n";
		}
		else
		{
			cout << visited[i] - 1 << "\n";
		}
	}
	return 0;
}