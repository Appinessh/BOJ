#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>> map;
vector<vector<int>> color;
vector<vector<int>> direction = { {-1,0},{1,0},{0,-1},{0,1} };
int search(int s,int x, int y)
{
	if (s == 0||map[x][y]!=0)
	{
		return 0;
	}
	s--;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map.size(); j++)
		{
			if (map[i][j] == 0)
			{
				continue;
			}
			for (int k = 0; k < 4; k++)
			{
				if (color[i][j] == 1)
				{
					continue;
				}
				if ((i + direction[k][0] >= 0) && (i + direction[k][0] < map.size()) && (j + direction[k][1] >= 0) && (j + direction[k][1] < map.size()))
				{

					if (map[i + direction[k][0]][j + direction[k][1]] == 0 && color[i + direction[k][0]][j + direction[k][1]] == 0)
					{
						map[i + direction[k][0]][j + direction[k][1]] = map[i][j];
						color[i + direction[k][0]][j + direction[k][1]] = 1;

					}
					else if (map[i + direction[k][0]][j + direction[k][1]] != 0 && color[i + direction[k][0]][j + direction[k][1]] != 0)
					{
						if (map[i + direction[k][0]][j + direction[k][1]] > map[i][j])
						{
							map[i + direction[k][0]][j + direction[k][1]] = map[i][j];
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	/*cout << "\n\nmap\n\n" << endl;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map.size(); j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\ncolor\n\n" << endl;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map.size(); j++)
		{
			cout <<color[i][j] << " ";
		}
		cout << "\n";
	}*/
	color.resize(0);
	color.resize(map.size());
	for (int i = 0; i < map.size(); i++)
	{
		color[i].resize(map.size());
	}
	search(s, x, y);
	return 0;
}
int main(void)
{
	int n, k;
	int s, x, y;
	cin >> n >> k;
	map.resize(n);
	color.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(n);
		color[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}
	cin >> s >> x >> y;
	x--;
	y--;
	search(s, x, y);
	cout << map[x][y];
	return 0;
}