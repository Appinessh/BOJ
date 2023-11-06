#include  <iostream>
#include <vector>
#include  <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;
vector<vector<int>> map;
typedef struct location {
	int index1;
	int index2;
};
vector<location> house;
vector<location> chicken;
vector<vector<location>> index_favorite_chicken;
vector<int> index_can_visit;
int number_house;
int number_chicken;
int n, m;
int ans;
int distance(location loc1, location loc2)
{
	return abs(loc1.index1 - loc2.index1) + abs(loc1.index2 - loc2.index2);
}
bool compare(location loc1, location loc2)
{
	return loc1.index2 < loc2.index2;
}
void get_favorite(void)
{
	for (int i = 0; i < number_house; i++)
	{
		for (int j = 0; j < number_chicken; j++)
		{
			location new_loc;
			new_loc.index1 = j;
			new_loc.index2 = distance(house[i], chicken[j]);
			index_favorite_chicken[i][j]=new_loc;
		}
	}
	for (int i = 0; i < number_house; i++)
	{
		sort(index_favorite_chicken[i].begin(), index_favorite_chicken[i].end(), compare);
	}
}
int calculation(void)
{
	int result = 0;
	for (int i = 0; i < number_house; i++)
	{
		for (int j = 0; j < number_chicken; j++)
		{
			if (find(index_can_visit.begin(),index_can_visit.end(), index_favorite_chicken[i][j].index1)==index_can_visit.end())
			{
				continue;
			}
			else
			{
				result = result + index_favorite_chicken[i][j].index2;
				break;
			}
		}
	}
	return result;
}
void combination(int depth)
{
	if (index_can_visit.size() == m)
	{
		int temp;
		temp = calculation();
		ans = ans < temp ? ans : temp;
		return;
	}
	for (int i = depth; i < number_chicken; i++)
	{
		index_can_visit.push_back(i);
		combination(i + 1);
		index_can_visit.pop_back();
	}
	return;
}
int main(void)
{
	number_house = 0;
	number_chicken = 0;
	cin >> n >> m;
	map.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				number_house++;
				location new_home;
				new_home.index1 = i;
				new_home.index2 = j;
				house.push_back(new_home);
			}
			else if (map[i][j] == 2)
			{
				number_chicken++;
				location new_chicken;
				new_chicken.index1 = i;
				new_chicken.index2 = j;
				chicken.push_back(new_chicken);
			}
		}
	}
	index_favorite_chicken.resize(number_house);
	for (int i = 0; i < number_house; i++)
	{
		index_favorite_chicken[i].resize(number_chicken);
	}
	get_favorite();
	ans = INT_MAX;
	combination(0);
	cout << ans;
	return 0;
}