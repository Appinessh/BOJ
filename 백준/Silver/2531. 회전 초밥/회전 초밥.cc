#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, d, k, c;
vector<int> sushi_cnt(30001);
vector<int> sushi(30001);
int main(void)
{
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
	{
		cin >> sushi[i];
	}
	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		if (sushi_cnt[sushi[i]] == 0)
		{
			cnt++;
		}
		sushi_cnt[sushi[i]]++;
	}
	if (sushi_cnt[c] == 0)
	{
		cnt++;
	}
	sushi_cnt[c]++;
	int max = 0;
	max = cnt > max ? cnt : max;
	int front, back;
	front = 0;
	back = k - 1;
	while (front <= N - 2)
	{
		front++;
		back++;
		if (back >= N)
		{
			back = back % N;
		}
		sushi_cnt[sushi[front - 1]]--;
		if (sushi_cnt[sushi[front - 1]] == 0)
		{
			cnt--;
		}
		if (sushi_cnt[sushi[back]] == 0)
		{
			cnt++;
		}
		sushi_cnt[sushi[back]]++;
		max = cnt > max ? cnt : max;
	}
	cout << max;
	return 0;
}