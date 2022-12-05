#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int min3(int a, int b, int c)
{
	int ans;
	ans = a < b ? a : b;
	ans = ans < c ? ans : c;
	return ans;
}
int min2(int a, int b)
{
	int ans;
	ans = a < b ? a : b;
	return ans;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int ans;
	int min[1000000];
	int i;
	min[2] = 1;
	min[3] = 1;
	for (i = 4; i < n + 1; i++)
	{
		if (i % 6 == 0)
		{
			min[i] = min3(min[i - 1] + 1, min[i / 3] + 1, min[i / 2] + 1);
		}
		else if (i % 3 == 0)
		{
			min[i] = min2(min[i - 1] + 1, min[i / 3] + 1);
		}
		else if (i % 2 == 0)
		{
			min[i] = min2(min[i - 1] + 1, min[i / 2] + 1);
		}
		else
		{
			min[i] = min[i - 1] + 1;
		}
	}
	printf("%d", min[n]);
	return 0;
}