#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int power(int a, int b)
{
	int result = 1;
	while (b > 0)
	{
		result = result * a;
		b--;
	}
	return result;
}
long long int divide_conquer(long long int index1, long long int index2, long long int size)
{
	long long int result=0;
	if (size == 2)
	{
		if (index1 % size == 0&&index2%size==0)
		{
			return 0;
		}
		else if (index1 % size == 0 && index2 % size == 1)
		{
			return 1;
		}
		else if (index1 % size == 1 && index2 % size == 0)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	else
	{
		if (index1 < size / 2 && index2 < size / 2)
		{
			result = result;
		}
		else if (index1 < size / 2 && index2 >= size / 2)
		{
			result = result + size * size / 4;
			index2 = index2 - size / 2;
		}
		else if (index1 >= size / 2 && index2 < size / 2)
		{
			result = result + size * size / 2;
			index1 = index1 - size / 2;
		}
		else
		{
			result = result + 3 * size * size / 4;
			index1 = index1 - size / 2;
			index2 = index2 - size / 2;
		}
		result = result + divide_conquer(index1, index2, size / 2);
	}
	return result;
}
int main(void)
{
	long long int n, r, c;
	cin >> n >> r >> c;
	/*for (int i = 16384; i < power(2, n); i++)
	{
		for (int j = 16384; j < power(2, n); j++)
		{
			cout << divide_conquer(i, j, power(2, n)) << " ";
		}
		cout << "\n";
	}*/
	cout << divide_conquer(r, c, power(2,n));
	return 0;
}