#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int combination(int n, int k)
{
	if (n == k || k == 0)
	{
		return 1;
	}
	else
	{
		return combination(n - 1, k - 1) + combination(n - 1, k);
	}
}
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = combination(n, k);
	printf("%d", ans);
	return 0;
}