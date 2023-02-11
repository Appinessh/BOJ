#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int pos(int index)
{
	int temp = index;
	temp = temp % 2;
	temp++;
	return temp;
}
int main(void)
{
	int T, W;
	scanf("%d%d", &T, &W);
	int* input = (int*)malloc(sizeof(int) * T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &input[i]);
	}
	int** dp = (int**)malloc(sizeof(int*) * (W + 1));
	for (int i = 0; i < W + 1; i++)
	{
		dp[i] = (int*)malloc(sizeof(int) * T);
	}
	for (int i = 0; i <= W; i++)
	{
		for (int j = 0; j < T; j++)
		{
			int position = pos(i);
			if (j == 0)
			{
				if (position == input[j])
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = 0;
				}
				continue;
			}
			if (i == 0)
			{
				if (position == input[j])
				{
					dp[i][j] = dp[i][j - 1] + 1;
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
				}
				continue;
			}
			if (position == input[j])
			{
				dp[i][j] = (dp[i - 1][j - 1] + 1) > (dp[i][j - 1] + 1) ? (dp[i - 1][j - 1] + 1) : (dp[i][j - 1] + 1);
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1]) > (dp[i][j - 1]) ? (dp[i - 1][j - 1]) : (dp[i][j - 1]);
			}
		}
	}
	int answer = INT_MIN;
	for (int i = 0; i <= W; i++)
	{
		answer = answer > dp[i][T - 1] ? answer : dp[i][T - 1];
	}
	printf("%d", answer);
	free(input);
	free(dp);
	return 0;
}