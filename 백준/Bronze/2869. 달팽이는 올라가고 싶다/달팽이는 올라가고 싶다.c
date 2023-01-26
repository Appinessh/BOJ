#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	int a, b, v;
	scanf("%d%d%d", &a, &b, &v);
	int x = (v - a) / (a - b);
	if ((v - a) % (a - b) == 0)
	{
		printf("%d", x + 1);
		return 0;
	}
	printf("%d", x + 2);
	return 0;
}