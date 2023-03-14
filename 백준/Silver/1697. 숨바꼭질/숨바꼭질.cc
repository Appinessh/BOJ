#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <int> visited(100001,0);
queue <int> q;
vector<int> index(int start)
{
	vector<int> answer(3);
	answer[0] = start - 1;
	answer[1] = start + 1;
	answer[2] = 2 * start;
	return answer;
}
int cnt = 1;
int bfs(int start, int destination)
{
	visited[start] = cnt;
	q.push(start);
	vector<int> coordinates;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		cnt = visited[u];
		coordinates = index(u);
		for (int i = 0; i < 3; i++)
		{
			if (coordinates[i] >= 0 && coordinates[i] <= 100000)
			{
				if (visited[coordinates[i]] == 0)
				{
					visited[coordinates[i]] = cnt+1;
					q.push(coordinates[i]);
				}
			}
			if (visited[destination] != 0)
			{
				return 0;
			}
		}
	}
}
int main(void)
{
	int start, destination;
	cin >> start >> destination;
	bfs(start, destination);
	if (start == destination)
	{
		cout << "0";
		return 0;
	}
	cout << cnt;
	return 0;
}