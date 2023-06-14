#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
	long long int order;
	long long int val;
};
vector<node> arrayy;
int add(long long int n, int p, int q)
{
	if (n <= 0)
	{
		return 0;
	}
	int indicator1 = 0;
	int indicator2 = 0;
	long long int alp, bet;
	alp = n / p;
	bet = n / q;
	for (int i = 0; i < arrayy.size(); i++)
	{
		if (arrayy[i].order == n / p)
		{
			indicator1 = 1;
		}
		if (arrayy[i].order == n / q)
		{
			indicator2 = 1;
		}
		if (indicator1 * indicator2 == 1)
		{
			break;
		}
	}
	if (indicator1 == 0)
	{
		node newone;
		newone.order = alp;
		newone.val = 0;
		arrayy.push_back(newone);
		add(alp, p, q);
	}
	if (indicator2 == 0&&alp!=bet)
	{
		node newone;
		newone.order = bet;
		newone.val = 0;
		arrayy.push_back(newone);
		add(bet, p, q);
	}
	return 0;
}
bool cmp(const node& node1, const node& node2)
{
	if (node1.order < node2.order)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main(void)
{
	long long int n, p, q;
	cin >> n >> p >> q;
	node newone;
	newone.order = n;
	newone.val = 0;
	arrayy.push_back(newone);
	add(n, p, q);
	sort(arrayy.begin(), arrayy.end(), cmp);
	for (int i = 0; i < arrayy.size(); i++)
	{
		if (arrayy[i].order == 0)
		{
			arrayy[i].val = 1;
		}
		else
		{
			int indicator1, indicator2;
			for (int j = 0; j < i; j++)
			{
				if (arrayy[j].order == arrayy[i].order / p)
				{
					indicator1 = j;
				}
				if (arrayy[j].order == arrayy[i].order / q)
				{
					indicator2 = j;
				}
			}
			arrayy[i].val = arrayy[indicator1].val + arrayy[indicator2].val;
		}
	}
	cout << arrayy[arrayy.size() - 1].val << endl;
	return 0;
}