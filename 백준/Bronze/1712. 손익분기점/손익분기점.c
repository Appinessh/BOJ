#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (b >= c)
	{
		printf("-1");
		return 0;
	}
	int answer;
	answer = a / (c - b) + 1;
	printf("%d", answer);
	return 0;
}