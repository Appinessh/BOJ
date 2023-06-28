#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct node
{
	long long int sum;
	long long int min;
};
vector<long long int> arr;
vector<node> left_side;
vector<node> right_side;
long long int maximum_3(long long int a, long long int b, long long int c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
long long int divide_conquer(int index1, int index2)
{
	if (index1 == index2)
	{
		return arr[index1] * arr[index1];
	}
	int mid = (index1 + index2) / 2;
	left_side.resize(0);
	right_side.resize(0);
	long long int min = INT_MAX;
	for (int i = mid; i >= index1; i--)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			node new_node;
			new_node.sum = arr[i];
			new_node.min = arr[i];
			left_side.push_back(new_node);
		}
		else
		{
			left_side[left_side.size() - 1].sum = left_side[left_side.size() - 1].sum + arr[i];
		}
	}
	min = INT_MAX;
	for (int i = mid + 1; i <= index2; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			node new_node;
			new_node.sum = arr[i];
			new_node.min = arr[i];
			right_side.push_back(new_node);
		}
		else
		{
			right_side[right_side.size() - 1].sum = right_side[right_side.size() - 1].sum + arr[i];
		}
	}
	long long int result = -1;
	int pointer1 = 0;
	int pointer2 = 0;
	min = left_side[pointer1].min < right_side[pointer2].min ? left_side[pointer1].min : right_side[pointer2].min;
	long long int sum = left_side[pointer1].sum + right_side[pointer2].sum;
	result = sum * min;
	while (pointer1 <= left_side.size() - 1 && right_side.size() - 1 >= pointer2)
	{
		if (pointer1 == left_side.size() - 1 && right_side.size() - 1 == pointer2)
		{
			break;
		}
		else if (pointer1 == left_side.size() - 1)
		{
			pointer2++;
			min = min < right_side[pointer2].min ? min : right_side[pointer2].min;
			sum = sum + right_side[pointer2].sum;
		}
		else if (pointer2 == right_side.size() - 1)
		{
			pointer1++;
			min = min < left_side[pointer1].min ? min : left_side[pointer1].min;
			sum = sum + left_side[pointer1].sum;
		}
		else if (left_side[pointer1 + 1].min > right_side[pointer2].min)
		{
			pointer1++;
			sum = sum + left_side[pointer1].sum;
		}
		else if (left_side[pointer1].min < right_side[pointer2 + 1].min)
		{
			pointer2++;
			sum = sum + right_side[pointer2].sum;
		}
		else if (left_side[pointer1 + 1].min > right_side[pointer2 + 1].min)
		{
			pointer1++;
			min = min < left_side[pointer1].min ? min : left_side[pointer1].min;
			sum = sum + left_side[pointer1].sum;
		}
		else if (left_side[pointer1 + 1].min < right_side[pointer2 + 1].min)
		{
			pointer2++;
			min = min < right_side[pointer2].min ? min : right_side[pointer2].min;
			sum = sum + right_side[pointer2].sum;
		}
		else
		{
			pointer1++;
			pointer2++;
			min = left_side[pointer1].min < right_side[pointer2].min ? left_side[pointer1].min : right_side[pointer2].min;
			sum = sum + left_side[pointer1].sum + right_side[pointer2].sum;
		}
		result = result > min * sum ? result : min * sum;
	}
	return maximum_3(divide_conquer(index1, mid), divide_conquer(mid + 1, index2), result);
}
int main(void)
{
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << divide_conquer(0, n - 1);
	return 0;
}
