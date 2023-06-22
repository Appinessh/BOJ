#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
struct node
{
	long long int width;
	long long int min;
};
vector<long long int> arr;
vector<node> left_side;
vector<node> right_side;
long long int max(long long int a, long long int b, long long int c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
long long int cal(int index1, int index2)
{
	if (index1 == index2)
	{
		return (long long int)arr[index1];
	}
	long long int mid = (index1 + index2) / 2;
	long long int min = 1000000001;
	left_side.resize(0);
	right_side.resize(0);
	for (long long int i = mid; i >= index1; i--)
	{
		if (min > arr[i])
		{
			node new_node;
			new_node.min = arr[i];
			new_node.width = 1;
			left_side.push_back(new_node);
			min = arr[i];
		}
		else
		{
			left_side[left_side.size() - 1].width++;
		}
	}
	min = 1000000001;
	for (long long int i = mid + 1; i <= index2; i++)
	{
		if (min > arr[i])
		{
			node new_node;
			new_node.min = arr[i];
			new_node.width = 1;
			right_side.push_back(new_node);
			min = arr[i];
		}
		else
		{
			right_side[right_side.size() - 1].width++;
		}
	}
	long long int pointer1 = 0;
	long long int width1 = left_side[pointer1].width;
	long long int pointer2 = 0;
	long long int width2 = right_side[pointer2].width;
	long long int answer = 0;
	min = left_side[pointer1].min < right_side[pointer2].min ? left_side[pointer1].min : right_side[pointer2].min;
	answer = answer > min * (width1 + width2) ? answer : min * (width1 + width2);
	while (pointer1 <= left_side.size() - 1 && pointer2 <= right_side.size())
	{
		if (pointer1 == left_side.size() - 1 && pointer2 == right_side.size() - 1)
		{
			break;
		}

		if (pointer1 == left_side.size() - 1)
		{
			pointer2++;
			width2 = width2 + right_side[pointer2].width;
			min = min < right_side[pointer2].min ? min : right_side[pointer2].min;
		}
		else if (pointer2 == right_side.size() - 1)
		{
			pointer1++;
			width1 = width1 + left_side[pointer1].width;
			min = min < left_side[pointer1].min ? min : left_side[pointer1].min;
		}
		else
		{
			if (left_side[pointer1 + 1].min > right_side[pointer2].min)
			{
				pointer1++;
				width1 = width1 + left_side[pointer1].width;
				min = min < left_side[pointer1].min ? min : left_side[pointer1].min;
			}
			else if (left_side[pointer1].min < right_side[pointer2 + 1].min)
			{
				pointer2++;
				width2 = width2 + right_side[pointer2].width;
				min = min < right_side[pointer2].min ? min : right_side[pointer2].min;
			}
			else if (left_side[pointer1 + 1].min > right_side[pointer2 + 1].min)
			{
				pointer1++;
				width1 = width1 + left_side[pointer1].width;
				min = min < left_side[pointer1].min ? min : left_side[pointer1].min;
			}
			else if (left_side[pointer1 + 1].min < right_side[pointer2 + 1].min)
			{
				pointer2++;
				width2 = width2 + right_side[pointer2].width;
				min = min < right_side[pointer2].min ? min : right_side[pointer2].min;
			}
			else
			{
				pointer1++;
				pointer2++;
				width1 = width1 + left_side[pointer1].width;
				width2 = width2 + right_side[pointer2].width;
				min = min < left_side[pointer1].min ? min : left_side[pointer1].min;
				min = min < right_side[pointer2].min ? min : right_side[pointer2].min;
			}
		}
		answer = answer > min * (width1 + width2) ? answer : min * (width1 + width2);
	}
	return max(cal(index1, mid), answer, cal(mid + 1, index2));
}
int main(void)
{
	while (1)
	{
		long long int n;
		long long int answer;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		arr.resize(n);
		for (int i = 0; i < n; i++)
		{
			long long int input;
			cin >> input;
			arr[i] = input;
		}
		answer = cal(0, n - 1);
		cout << answer << "\n";
		arr.resize(0);
	}
	return 0;
}