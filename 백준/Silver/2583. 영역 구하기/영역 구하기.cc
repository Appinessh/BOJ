#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> direction = { {-1,0},{0,-1},{1,0},{0,1} };
int m, n;
int area;
struct coordinates {
	int index1;
	int index2;
};
vector<int> result;
coordinates find_coordinates(void)
{
	coordinates new_one;
	new_one.index1 = -1;
	new_one.index2 = -1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0)
			{
				new_one.index1 = i;
				new_one.index2 = j;
				return new_one;
			}
		}
	}
	return new_one;
}
void dfs(int index1, int index2)
{
	map[index1][index2] = -1;
	area++;
	//cout << index1 << " " << index2<<" "<<map[index1][index2];
	for (int i = 0; i < 4; i++)
	{
		if (index1 + direction[i][0] >= 0 && index2 + direction[i][1] >= 0 && index1 + direction[i][0] <m && index2 + direction[i][1] < n)
		{
			if (map[index1 + direction[i][0]][index2 + direction[i][1]] == 0)
			{
				dfs(index1 + direction[i][0], index2 + direction[i][1]);
			}
		}
	}
}
int main(void)
{
	cin >> m >> n;
	map.resize(m);
	for (int i = 0; i < m; i++)
	{
		map[i].resize(n);
	}
	int k;
	cin >> k;
	while (k > 0)
	{
		k--;
		int index_x1, index_y1, index_x2, index_y2;
		cin >> index_y1 >> index_x1 >> index_y2 >> index_x2;
		for (int i = index_x1; i < index_x2; i++)
		{
			for (int j = index_y1; j < index_y2; j++)
			{
				map[i][j] = -1;
			}
		}
	}
	coordinates start = find_coordinates();
	while (start.index1 != -1)
	{
		//cout << start.index1 << " " << start.index2;
		//cout << map[start.index1][start.index2];
		area = 0;
		dfs(start.index1, start.index2);
		result.push_back(area);
		start = find_coordinates();
	}
	sort(result.begin(), result.end());
	int siz = result.size();
	cout << siz << "\n";
	for (int i = 0; i < siz; i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}