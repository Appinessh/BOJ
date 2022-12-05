#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int first, N, count;
	scanf("%d", &first);
	N = first;
	count = 0;
	int c;
	while (1)
	{
		count++;
		c = N / 10 + N % 10;
		N = N % 10 * 10 + c % 10;
		if (N == first)
		{
			break;
		}
	}
	printf("%d", count);
}