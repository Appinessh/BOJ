#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int F, S, G, U, D;
vector<int> visited;
queue <int> q;
void bfs(void)
{
	if (q.empty()||visited[G]!=0)
	{
		return ;
	}
	int current = q.front();
	q.pop();
	if (current == G)
	{
		return ;
	}
	else
	{
		if (current + U <= F&&visited[current+U]==0)
		{
			visited[current + U] = visited[current] + 1;
			q.push(current + U);
		}
		if (current - D >= 1 && visited[current - D] == 0)
		{
			visited[current - D] = visited[current] + 1;
			q.push(current - D);
		}
	}
	bfs();
	return;
}
int main(void)
{
	cin >> F >> S >> G >> U >> D;
	visited.resize(F + 1);
	visited[0] = 1;
	visited[S] = 1;
	q.push(S);
	bfs();
	if (visited[G] == 0)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << visited[G] - 1;
	}
	return 0;
}