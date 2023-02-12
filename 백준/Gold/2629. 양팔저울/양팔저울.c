#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int* input = (int*)malloc(sizeof(int) * n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
		sum = sum + input[i];
	}
	int** dp = (int**)malloc(sizeof(int*) * (sum + 1));
	int* answer = (int*)malloc(sizeof(int) * (sum + 1));
	for (int i = 0; i <= sum; i++)
	{
		dp[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	for (int i = 0; i <= sum; i++)
	{
		answer[i] = 0;
	}
	int upper_bound = 0;
	for (int j = 0; j < n; j++)
	{
		upper_bound = upper_bound + input[j];
		dp[input[j]][j] = 1;
		for (int i = 1; i <= upper_bound; i++)
		{
			if (answer[i] == 1)
			{
				dp[i + input[j]][j] = 1;
				if (i - input[j] > 0)
				{
					dp[i - input[j]][j] = 1;
				}
				else
				{
					dp[input[j] - i][j] = 1;
				}
			}
		}
		for (int i = 1; i <= upper_bound; i++)
		{
			if (dp[i][j] == 1)
			{
				answer[i] = 1;
			}
		}
	}
	int test_case;
	scanf("%d", &test_case);
	int* weight = (int*)malloc(sizeof(int) * test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < test_case; i++)
	{
		if (weight[i]>sum)
		{
			printf("N\n");
		}
		else if (answer[weight[i]] == 1)
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}
	free(weight);
	free(dp);
	free(answer);
	return 0;
}