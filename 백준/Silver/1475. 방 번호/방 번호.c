#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include<math.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	if (n == 0)
	{
		printf("1");
		return 0;
	}
	int a[10] = { 0, };
	while (n!=0)
	{
		a[n % 10]++;
		n = (n - n % 10) / 10;
	}
	int k = a[6] + a[9];
	if (k % 2 == 0)
	{
		a[6] = k / 2;
		a[9] = k / 2;
	}
	else
	{
		a[6] = k / 2+1;
		a[9] = k / 2+1;
	}
	int M = INT_MIN;
	int i;
	for (i = 0; i < 10; i++)
	{
		M = max(M, a[i]);
	}
	printf("%d", M);
	return 0;
}