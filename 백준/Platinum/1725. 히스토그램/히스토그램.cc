#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
struct node
{
	int width;
	int min;
};
vector<int> arr;
vector<node> left_side;
vector<node> right_side;
int max(int a, int b, int c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
int cal(int index1, int index2)
{
	if (index1 == index2)
	{
		return arr[index1];
	}
	int mid = (index1 + index2) / 2;
	int min = 1000000001;
	left_side.resize(0);
	right_side.resize(0);
	for (int i = mid; i >= index1; i--)
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
	for (int i = mid + 1; i <= index2; i++)
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
	int pointer1 = 0;
	int width1 = left_side[pointer1].width;
	int pointer2 = 0;
	int width2 = right_side[pointer2].width;
	int answer=0;
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
			min=min< left_side[pointer1].min ? min : left_side[pointer1].min;
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
	int n;
	int answer;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
	}
	answer = cal(0, n - 1);
	cout << answer << endl;
	return 0;
}