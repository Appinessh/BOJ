#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ja(int a)
{
	int count = 1;
	while (1)
	{
		a = a / 10;
		if (a != 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
int main(void)
{
	int n;
	int a1[5] = { 0, };
	int a2[5] = { 0, };
	int i; 
	int ans[100000] = {0,};
	int count = 0;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		int a = ja(n);
		for (i = 0; i < a; i++)
		{
			a1[i] = n % 10;
			a2[a - 1 - i] = n % 10;
			n = n / 10;
		}
		for (i = 0; i < a; i++)
		{
			if (a1[i] != a2[i])
			{
				ans[count] = 1;
				break;
			}
			if (i == a - 1)
			{
				ans[count] = 2;
				break;
			}
		}
		count++;
	}
	i = 0;
	while (1)
	{
		if (ans[i] == 0)
		{
			break;
		}
		else if (ans[i] == 1)
		{
			printf("no");
		}
		else
		{
			printf("yes");
		}
		printf("\n");
		i++;
	}
}