#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	int N;
	scanf("%d", &N);
	int a;
	a = (N - 1) / 3;
	int b;
	b = (int)(sqrt(a));
	b = (b-2)>0?(b - 2):0;
	while (3 * b * (b + 1) + 1 < N)
	{
		b++;
	}
	printf("%d", b + 1);
	return 0;
}