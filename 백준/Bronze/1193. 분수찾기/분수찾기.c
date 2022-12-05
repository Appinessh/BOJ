#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int x;
	scanf("%d", &x);
	int n = 1;
	int k;
	int up, down;
	while (1)
	{
		if (x - n*(n+1)/2 <= 0)
		{
			break;
		}
		else
		{
			n++;
		}
	}
	if (n % 2 == 0)
	{
		k = x - (n - 1) * n / 2;
		up = k;
		down = n + 1 - up;
	}
	else
	{
		k = x - (n - 1) * n / 2;
		down = k;
		up = n + 1 - down;
	}
	printf("%d/%d", up, down);
	return 0;
}