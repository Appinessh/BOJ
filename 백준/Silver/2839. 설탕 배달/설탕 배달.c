#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	int a;
	scanf("%d", &a);
	int r1, r2;
	r1 = a / 5;
	a = a - 5 * r1;
	while (a % 3 != 0)
	{
		r1 = r1 - 1;
		a = a + 5;
	}
	r2 = a / 3;
	if (r1 < 0 || r2 < 0)
	{
		printf("-1");
		return 0;
	}
	int answer;
	answer = r1 + r2;
	printf("%d", answer);
	return 0;
}