#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int NOC[11];
	NOC[1] = 1;
	NOC[2] = 2;
	NOC[3] = 4;
	int i;
	for (i = 4; i < 11; i++)
	{
		NOC[i] = NOC[i - 1] + NOC[i - 2] + NOC[i - 3];
	}
	int T;
	scanf("%d", &T);
	int ans[10];
	for (i = 0; i < T; i++)
	{
		scanf("%d", &ans[i]);
		ans[i] = NOC[ans[i]];
	}
	for (i = 0; i < T; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}