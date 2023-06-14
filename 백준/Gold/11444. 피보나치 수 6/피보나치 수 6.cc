#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
struct matrix {
	long long int a11, a12, a21, a22;
};
long long int powera(long long int a, long long int b)
{
	long long int result;
	result = 1;
	while (b > 0)
	{
		result = result * a;
		b--;
	}
	return result;
}
matrix power(matrix a)
{
	long long int a11, a12, a21, a22;
	a11 = a.a11;
	a12 = a.a12;
	a21 = a.a21;
	a22 = a.a22;
	matrix result;
	result.a11 = a11 * a11 + a12 * a21;
	result.a12 = a11 * a12 + a12 * a22;
	result.a21 = a11 * a21 + a21 * a22;
	result.a22 = a12 * a21 + a22 * a22;
	result.a11 = result.a11 % 1000000007;
	result.a12 = result.a12 % 1000000007;
	result.a21 = result.a21 % 1000000007;
	result.a22 = result.a22 % 1000000007;
	return result;
}
matrix multiplication(matrix a, matrix b)
{
	long long int a11, a12, a21, a22;
	a11 = a.a11;
	a12 = a.a12;
	a21 = a.a21;
	a22 = a.a22;
	long long int b11, b12, b21, b22;
	b11 = b.a11;
	b12 = b.a12;
	b21 = b.a21;
	b22 = b.a22;
	matrix result;
	result.a11 = a11 * b11 + a12 * b21;
	result.a12 = a11 * b12 + a12 * b22;
	result.a21 = b11 * a21 + b21 * a22;
	result.a22 = b12 * a21 + b22 * a22;
	result.a11 = result.a11 % 1000000007;
	result.a12 = result.a12 % 1000000007;
	result.a21 = result.a21 % 1000000007;
	result.a22 = result.a22 % 1000000007;
	return result;
}
vector <int> cnt;
int main(void)
{
	long long int n;
	cin >> n;
	long long int a;
	a = (long long int)(log2(n) + 5);
	vector<matrix> array;
	array.resize(a);
	for (int i = 1; i < a; i++)
	{
		matrix new_matrix;
		if (i == 1)
		{
			new_matrix.a11 = 2;
			new_matrix.a12 = 1;
			new_matrix.a21 = 1;
			new_matrix.a22 = 1;
		}
		else
		{
			new_matrix = power(array[i - 1]);
		}
		array[i] = new_matrix;
	}
	cnt.resize(a);
	long long int k = n / 2;
	long long int l = (long long int)(log2(k))+1;
	matrix result;
	result.a11 = 1;
	result.a12 = 0;
	result.a21 = 0;
	result.a22 = 1;
	while (k != 0)
	{
		k = k - powera(2, l - 1);
		result = multiplication(result, array[l]);
		l = (long long int)(log2(k)) + 1;
	}
	if (n % 2 == 0)
	{
		cout << (result.a21 + 1000000007) % 1000000007;
	}
	else
	{
		cout << (result.a11 + 1000000007) % 1000000007;
	}
	return 0;
}