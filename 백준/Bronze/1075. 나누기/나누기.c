#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	int c;
	int ans;
	int i=1;
	c = a % b;
	if ((a - c) / 100 != a / 100)
	{
		ans = a + b - c;
	}
	else
	{
		ans = a - c;
		while (1)
		{
			ans = ans - b;
			if (ans / 100 != a / 100)
			{
				ans = ans + b;
				break;
			}
		}
	}
	if ((ans / 10)%10 != 0)
	{
		ans = ans % 100;
		printf("%d", ans);
	}
	else
	{
		ans = ans % 10;
		printf("0%d", ans);
	}
	return 0;
}