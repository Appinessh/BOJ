#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int N, m, M, T, R;
	scanf("%d%d%d%d%d", &N, &m, &M, &T, &R);
	int time = 0;
	int count = 0;
	int mac=m;
	if (M - m < T)
	{
		printf("-1");
		return 0;
	}
	while (1)
	{
		if (count == N)
		{
			break;
		}
		if (mac+T<=M)
		{
			count++;
			mac = mac + T;
		}
		else
		{
			mac = mac - R;
			mac = max(m, mac);
		}
		time++;
	}
	printf("%d", time);
	return 0;
}