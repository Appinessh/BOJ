#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct matrix {
	int a11, a12, a21, a22;
};
vector<matrix> squared(32);
matrix result;
vector<int> multip(32);
int n;
void square(void)
{
	for (int i = 1; i <= 31; i++)
	{
		squared[i].a11 = squared[i - 1].a11 * squared[i - 1].a11 + squared[i - 1].a12 * squared[i - 1].a21;
		squared[i].a12 = squared[i - 1].a11 * squared[i - 1].a12 + squared[i - 1].a12 * squared[i - 1].a22;
		squared[i].a21 = squared[i - 1].a21 * squared[i - 1].a11 + squared[i - 1].a22 * squared[i - 1].a21;
		squared[i].a22 = squared[i - 1].a21 * squared[i - 1].a12 + squared[i - 1].a22 * squared[i - 1].a22;
		squared[i].a11 = (squared[i].a11+1000) % 1000;
		squared[i].a12 = (squared[i].a12+1000) % 1000;
		squared[i].a21 = (squared[i].a21+1000) % 1000;
		squared[i].a22 = (squared[i].a22+1000) % 1000;
	}
}
matrix mul(matrix a, matrix b)
{
	matrix res;
	res.a11 = a.a11 * b.a11 + a.a12 * b.a21;
	res.a12 = a.a11 * b.a12 + a.a12 * b.a22;
	res.a21 = a.a21 * b.a11 + a.a22 * b.a21;
	res.a22 = a.a21 * b.a12 + a.a22 * b.a22;
	res.a11 = (res.a11+1000) % 1000;
	res.a12 = (res.a12+1000) % 1000;
	res.a21 = (res.a21+1000) % 1000;
	res.a22 = (res.a22+1000) % 1000;
	return res;
}
void multiplication(void)
{
	for (int i = 0; i < 32; i++)
	{
		if (multip[i]==1)
		{
			result = mul(result, squared[i]);
		}
	}
}
void get_multip(void)
{
	int temp = n-1;
	while (temp != 0)
	{
		int k = int(log2(temp));
		multip[k] = 1;
		temp = temp- pow(2, k);
	}
}
int main(void)
{
	squared[0].a11 = 6;
	squared[0].a12 = -4;
	squared[0].a21 = 1;
	squared[0].a22 = 0;
	square();
	//for (int i = 0; i < 32; i++)
	//{
	//	cout << i << "\n";
	//	cout << squared[i].a11 << " " << squared[i].a12 << "\n";
	//	cout << squared[i].a21 << " " << squared[i].a22 << "\n";
	//}
	int test_case;
	int cnt = 0;
	cin >> test_case;
	while (test_case > cnt)
	{
		int answer;
		cnt++;
		cin >> n;
		result.a11 = 1;
		result.a12 = 0;
		result.a21 = 0;
		result.a22 = 1;
		multip.resize(0);
		multip.resize(32);
		get_multip();
		multiplication();
		answer = result.a21 * 28+result.a22*6;
		//cout << answer << " answer\n";
		answer--;
		answer=(answer+1000) % 1000;
		printf("Case #%d: %03d\n", cnt, answer);
		//for (int i = 0; i < 32; i++)
		//{
		//	cout << "multip[" << i << "]    " << multip[i]<<"\n";
		//}
		//cout << "\n";
	}
	return 0;
}