#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int array[1001][1001] = { 0, };
	int i, j;
	int n, k;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n - k + 1; i++)
	{
		array[i][0] = 1;
	}
	for (i = 0; i < k + 1; i++)
	{
		array[i][i] = 1;
	}
	if (n >= 2 * k)
	{
		for (i = 2; i <= k; i++)
		{
			for (j = 1; j < i; j++)
			{
				array[i][j] = (array[i - 1][j - 1] + array[i - 1][j])%10007;
			}
		}
		for (i = k + 1; i <= n - k; i++)
		{
			for (j = 1; j <= k; j++)
			{
				array[i][j]= (array[i - 1][j - 1] + array[i - 1][j])%10007;
			}
		}
		for (i = n - k + 1; i <= n; i++)
		{
			for (j = i - n + k; j <= k; j++)
			{
				array[i][j] = (array[i - 1][j - 1] + array[i - 1][j])%10007;
			}
		}
	}
	else
	{
		for (i = 2; i <=n-k; i++)
		{
			for (j = 1; j < i; j++)
			{
				array[i][j] = (array[i - 1][j - 1] + array[i - 1][j])%10007;
			}
		}
		for (i = n - k + 1; i <= k; i++)
		{
			for (j = i - n + k; j < i; j++)
			{
				array[i][j] = (array[i - 1][j - 1] + array[i - 1][j]) % 10007;
			}
		}
		for (i = k + 1; i <= n; i++)
		{
			for (j = i - n + k; j <= k; j++)
			{
				array[i][j] = (array[i - 1][j - 1] + array[i - 1][j]) % 10007;
			}
		}
	}
	printf("%d", array[n][k]);
	return 0;
}