#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int min(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i, j;
	int tri[500][500] = { 0, };
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			scanf("%d", &tri[i][j]);
		}
	}
	for (i = n - 1; i >0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			tri[i - 1][j] = min(tri[i][j], tri[i][j + 1]) + tri[i - 1][j];
		}
	}
	printf("%d", tri[0][0]);
	return 0;
}