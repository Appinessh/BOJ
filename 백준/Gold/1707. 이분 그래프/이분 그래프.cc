#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
struct node {
	int vertex;
	int color;
};
int find(vector<int> visit)
{
	int result = -1;
	for (int i = 1; i < visit.size(); i++)
	{
		if (visit[i] == 0)
		{
			result = i;
			return result;
		}
	}
	return result;
}
int solution(void)
{
	int vertex, edge;
	cin >> vertex >> edge;
	vector<vector<int>> adjlist;
	vector<int> visited;
	visited.resize(vertex + 1);
	adjlist.resize(vertex + 1);
	for (int i = 0; i < edge; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		adjlist[node1].push_back(node2);
		adjlist[node2].push_back(node1);
	}
	while (1)
	{
		int index=find(visited);
		if (index == -1)
		{
			break;
		}
		visited[index] = 1;
		queue<node> q;
		node start;
		start.vertex = index;
		start.color = 1;
		q.push(start);
		while (!q.empty())
		{
			node temp = q.front();
			q.pop();
			int new_color;
			if (temp.color == 1)
			{
				new_color = 2;
			}
			else
			{
				new_color = 1;
			}
			for (int i = 0; i < adjlist[temp.vertex].size(); i++)
			{
				if (visited[adjlist[temp.vertex][i]] == 0)
				{
					visited[adjlist[temp.vertex][i]] = new_color;
					node new_node;
					new_node.vertex = adjlist[temp.vertex][i];
					new_node.color = new_color;
					q.push(new_node);
				}
				else if (visited[adjlist[temp.vertex][i]] == new_color)
				{
					continue;
				}
				else
				{
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
	return 0;
}
int main(void)
{
	int test_case;
	cin >> test_case;
	int cnt=0;
	while (cnt < test_case)
	{
		cnt++;
		solution();
	}
}