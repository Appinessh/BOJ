#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	if (n % 2 != 0)
	{
		printf("0");
		return 0;
	}
	n = n / 2;
	int NOC[16], dp[16];
	NOC[1] = 3;
	dp[1] = 3;
	int i;
	for (i = 2; i < n + 1; i++)
	{
		NOC[i] = 2;
		dp[i] = 0;
	}
	for (i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i] = dp[i] + dp[i - j] * NOC[j];
		}
		dp[i] = dp[i] + NOC[i];
	}

	printf("%d\n",dp[n]);
	return 0;
}