#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int judge(int i, int a1, int a2, int a3, int a4, int a5)
{
	int count = 0;
	if (i % a1 == 0)
	{
		count++;
	}
	if (i % a2 == 0)
	{
		count++;
	}
	if (i % a3 == 0)
	{
		count++;
	}
	if (i % a4 == 0)
	{
		count++;
	}
	if (i % a5 == 0)
	{
		count++;
	}
	return count;
}
int main(void)
{
	int a1, a2, a3, a4, a5;
	scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
	int i=1;
	while (1)
	{
		if (judge(i, a1, a2, a3, a4, a5) >= 3)
		{
			break;
		}
		i++;
	}
	printf("%d", i);
}