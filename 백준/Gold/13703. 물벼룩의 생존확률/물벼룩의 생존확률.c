#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
unsigned long long int s[64][64] = { 0, };
unsigned long long int pow(int a, int b)
{
	int i = 1;
	unsigned long long int k = 1;
	for (i = 1; i <= b; i++)
	{
		k = k * a;
	}
	return k;
}
int main(void)
{
	int n, k;
	scanf("%d %d", &k, &n);
	int i, j = 0;
	if (k > n)
	{
		printf("%llu", (unsigned long long int)pow(2, n));
		return 0;
	}
	else if (k == n)
	{
		unsigned long long int c;
		c = pow(2, n) - 1;
		printf("%llu", c);
		return 0;
	}
	for (i = 0; i <= n; i++)
	{
		s[i][i] = 1;
		s[i][0] = pow(2,i);
		//printf("s[%d][%d]=%lld", i, i, s[i][i]);
	}
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= n - i + 1; j++)
		{
			s[i + j - 1][j] =  s[i + j - 2][j - 1] +  s[i + j - 2][j + 1];
		}
	}
	unsigned long long int ans = pow(2,n);
	ans = ans - s[n][k];
	printf("%llu", ans);
	return 0;
}