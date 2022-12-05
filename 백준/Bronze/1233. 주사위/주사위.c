#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int main(void)
{
	int s1,s2,s3;
	scanf("%d%d%d", &s1, &s2, &s3);
	int ss12[81] = { 0, };
	int ss123[121] = { 0, };
	int i, j;
	int index;
	for (i = 1; i <= s1; i++)
	{
		for (j = 1; j <= s2; j++)
		{
			ss12[i + j]++;
		}
	}
	for (i = 1; i <= s3; i++)
	{
		for (j = 2; j <= s1 + s2; j++)
		{
			ss123[i + j] = ss123[i + j] + ss12[j];
		}
	}
	for (i = 3; i <= s1 + s2 + s3; i++)
	{
		if (ss123[i] - ss123[i - 1] > 0 && ss123[i + 1] - ss123[i] <= 0)
		{
			break;
		}
	}
	printf("%d", i);
	return 0;
}