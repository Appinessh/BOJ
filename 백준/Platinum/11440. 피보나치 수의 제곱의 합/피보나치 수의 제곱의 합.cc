#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct matrix {
	long long int a11, a12, a21, a22;
};
long long int n;
long long int constant_mod = 1000000007;
vector<matrix> square(62);
vector<int> multip(62);
long long int power(int a, int b)
{
	long long int result=1;
	int temp = b;
	while (b > 0)
	{
		b--;
		result = result * a;
	}
	return result;
}
matrix mul_mat(matrix a, matrix b)
{
	matrix result;
	result.a11 = (a.a11 * b.a11 + a.a12 * b.a21+constant_mod)%constant_mod;
	result.a12 = (a.a11 * b.a12 + a.a12 * b.a22 + constant_mod) % constant_mod;
	result.a21 = (a.a21 * b.a11 + a.a22 * b.a21 + constant_mod) % constant_mod;
	result.a22 = (a.a21 * b.a12 + a.a22 * b.a22 + constant_mod) % constant_mod;
	return result;
}
void squared(void)
{
	square[0].a11 = 1;
	square[0].a12 = 1;
	square[0].a21 = 1;
	square[0].a22 = 0;
	for (int i = 1; i < 62; i++)
	{
		square[i] = mul_mat(square[i - 1], square[i - 1]);
	}
	return;
}
void get_multip(void)
{
	long long int temp = n-1;
	while (temp != 0)
	{
		int k = int(log2(temp));
		multip[k] = 1;
		temp = temp - power(2, k);
	}
	return;
}
long long int cal(void)
{
	matrix result;
	result.a11 = 1;
	result.a12 = 0;
	result.a21 = 0;
	result.a22 = 1;
	for (int i = 0; i < 62; i++)
	{
		if (multip[i] == 1)
		{
			result = mul_mat(result, square[i]);
		}
	}
	return result.a11 % constant_mod;
}
void calculation(void)
{
	squared();
	get_multip();
	long long int fn = cal()%constant_mod;
	n++;
	multip.resize(0);
	multip.resize(62);
	get_multip();
	long long int fn1 = cal()%constant_mod;
	cout << (fn *fn1 + constant_mod) % constant_mod;
	return;
}
int main(void)
{
	cin >> n;
	calculation();
	return 0;
}