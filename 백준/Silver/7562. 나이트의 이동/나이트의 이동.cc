#include <iostream>
#include <vector>
#include <algorithm>
#include  <queue>
using namespace std;
struct coordinates {
	int x;
	int y;
};
vector<vector<int>> direction = { {-2,-1},{-1,-2},{2,-1},{1,-2},{2,1},{1,2},{-2,1},{-1,2} };
vector<vector<int>> map;
queue<coordinates> q;
int bfs(coordinates destination)
{
	coordinates top;
	top = q.front();
	q.pop();
	for (int i = 0; i < 8; i++)
	{
		if (top.x + direction[i][0] >= 0 && top.x + direction[i][0] < map.size() && top.y + direction[i][1] >= 0 && top.y + direction[i][1] < map[0].size())
		{
			if (map[top.x + direction[i][0]][top.y + direction[i][1]] == 0)
			{
				coordinates new_one;
				new_one.x = top.x + direction[i][0];
				new_one.y = top.y + direction[i][1];
				map[top.x + direction[i][0]][top.y + direction[i][1]] = map[top.x][top.y] + 1;
				if (top.x + direction[i][0] == destination.x && top.y + direction[i][1] == destination.y)
				{
					return 0;
				}
				q.push(new_one);
			}
		}
	}
	return bfs(destination);
}
int main(void)
{
	int test_case;
	cin >> test_case;
	while (test_case > 0)
	{
		test_case--;
		int size;
		coordinates start, end;
		cin >> size >> start.x >> start.y >> end.x >> end.y;
		map.resize(0);
		map.resize(size);
		for (int i = 0; i < size; i++)
		{
			map[i].resize(size);
		}
		map[start.x][start.y] = 1;
		if (start.x == end.x && start.y == end.y)
		{
			cout << 0 << "\n";
			continue;
		}
		q.push(start);
		bfs(end);
		cout << map[end.x][end.y] - 1 << "\n";
		while (!q.empty())
		{
			q.pop();
		}
	}
	return 0;
}