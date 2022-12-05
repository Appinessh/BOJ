#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	long long int N, K;
	scanf("%lld%lld", &N, &K);
	long long int c[201][201] = { 0, };
	int i,j;
	for (i = 0; i < 201; i++)
	{
		c[i][1] = 1;
		c[0][i] = 1;
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 2; j <= K; j++)
		{
			c[i][j]=(c[i - 1][j] + c[i][j - 1])%1000000000;
		}
	}
	printf("%lld", c[N][K]);
	return 0;
}