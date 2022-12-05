#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include<math.h>
int main(void)
{
	long long int s;
	scanf("%lld", &s);
	long long int a;
	a = (long long int) (sqrt(2 * s + 9 / 4) - 3 / 2);
	if (s == a*(a + 3) / 2)
	{
		a = a - 1;
	}
	else if (s < a * (a + 3) / 2)
	{
		a = a - 1;
	}
	printf("%lld", a + 1);
}