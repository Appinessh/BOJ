#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void)
{
	vector<int> arr;
	vector<int> answer(2);
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int pointer1 = 0;
	int pointer2 = n - 1;
	answer[0] = arr[pointer1];
	answer[1] = arr[pointer2];
	while (pointer2-pointer1>0)
	{
		if (arr[pointer1] + arr[pointer2] > 0)
		{
			pointer2--;
			if (pointer1 == pointer2)
			{
				break;
			}
			if (abs(answer[0] + answer[1]) > abs(arr[pointer1] + arr[pointer2]))
			{
				answer[0] = arr[pointer1];
				answer[1] = arr[pointer2];
			}
		}
		else if (arr[pointer1] + arr[pointer2] < 0)
		{
			pointer1++;
			if (pointer1 == pointer2)
			{
				break;
			}
			if (abs(answer[0] + answer[1]) > abs(arr[pointer1] + arr[pointer2]))
			{
				answer[0] = arr[pointer1];
				answer[1] = arr[pointer2];
			}
		}
		else
		{
			break;
		}
	}
	cout << answer[0] << " " << answer[1];
	return 0;
}