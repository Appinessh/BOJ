#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arry;
vector<int> list;
int n;
void update(int number)
{
	if (size(list) == 0)
	{
		list.push_back(number);
	}
	else if (number > list[size(list) - 1])
	{
		list.push_back(number);
	}
	else if (number == list[size(list) - 1])
	{

	}
	else
	{
		int left_index = 0;
		int right_index = size(list) - 1;
		int mid_index;
		while (left_index<right_index)
		{
			mid_index = (left_index + right_index) / 2;
			if (list[mid_index] < number)
			{
				left_index = mid_index;
			}
			else if (list[mid_index] == number)
			{
				left_index = mid_index;
				right_index = mid_index;
				break;
			}
			else
			{
				right_index = mid_index;
			}
			if (left_index + 1 == right_index)
			{
				break;
			}
		}
		if (number == list[left_index] || number == list[right_index])
		{

		}
		else
		{
			if (number < list[left_index])
			{
				list[left_index] = number;
			}
			else
			{
				list[right_index] = number;
			}
		}
	}
}
int main(void)
{
	cin >> n;
	arry.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arry[i];
		update(arry[i]);
	}
	cout << size(list);
	return 0;
}