#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct matrix {
	long long int a11, a12, a21, a22;
};
matrix power(matrix a)
{
	matrix result;
	result.a11 = a.a11 * a.a11 + a.a12 * a.a21;
	result.a12 = a.a11 * a.a12 + a.a12 * a.a22;
	result.a21 = a.a21 * a.a11 + a.a22 * a.a21;
	result.a22 = a.a21 * a.a12 + a.a22 * a.a22;
	result.a11 = result.a11 % 1000000000;
	result.a12 = result.a12 % 1000000000;
	result.a21 = result.a21 % 1000000000;
	result.a22 = result.a22 % 1000000000;
	return result;
}
matrix multiplication(matrix a, matrix b)
{
	long long int  a11, a12, a21, a22, b11, b12, b21, b22;
	a11 = a.a11;
	a12 = a.a12;
	a21 = a.a21;
	a22 = a.a22;
	b11 = b.a11;
	b12 = b.a12;
	b21 = b.a21;
	b22 = b.a22;
	matrix result;
	result.a11 = a11 * b11 + a12 * b21;
	result.a12 = a11 * b12 + a12 * b22;
	result.a21 = a21 * b11 + a22 * b21;
	result.a22 = a21 * b12 + a22 * b22;
	result.a11 = result.a11 % 1000000000;
	result.a12 = result.a12 % 1000000000;
	result.a21 = result.a21 % 1000000000;
	result.a22 = result.a22 % 1000000000;
	return result;
}
long long int powera(long long int a, long long int b)
{
	long long int result;
	result = 1;
	while (b > 0)
	{
		result = a * result;
		b--;
	}
	return result;
}
int main(void)
{
	long long int a, b;
	long long int result=0;
	cin >> a >> b;
	long long int upper_bound = (long long int)log2(b) + 5;
	vector<matrix> array;
	array.resize(upper_bound);
	for (int i = 1; i < upper_bound; i++)
	{
		matrix newmat;
		if (i == 1)
		{
			newmat.a11 = 2;
			newmat.a12 = 1;
			newmat.a21 = 1;
			newmat.a22 = 1;
		}
		else
		{
			newmat = power(array[i - 1]);
		}
		array[i] = newmat;
	}
	b = b + 2;
	a = a + 1;
	long long int k = b / 2;
	long long int l = (long long int) log2(k) + 1;
	matrix result_a, result_b;
	result_a.a11 = 1;
	result_a.a12 = 0;
	result_a.a21 = 0;
	result_a.a22 = 1;
	result_b.a11 = 1;
	result_b.a12 = 0;
	result_b.a21 = 0;
	result_b.a22 = 1;
	while (k != 0)
	{
		k = k - powera(2, l - 1);
		result_b = multiplication(result_b, array[l]);
		l = (long long int)log2(k) + 1;
	}
	k = a / 2;
	l = (long long int)log2(k) + 1;
	while (k != 0)
	{
		k = k - powera(2, l - 1);
		result_a = multiplication(result_a, array[l]);
		l = (long long int)log2(k) + 1;
	}
	if (b % 2 == 1)
	{
		result = result_b.a11;
	}
	else
	{
		result = result_b.a21;
	}
	if (a % 2 == 1)
	{
		result = result-result_a.a11;
	}
	else
	{
		result = result - result_a.a21;
	}
	result = (result + 1000000000) % 1000000000;
	cout << result;
	return 0;
}