#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
float M(float a, float b)
{
	return a > b ? a : b;
}
int main(void)
{
	float n;
	float max = INT_MIN;
	scanf("%f", &n);
	int i;
	float sum=0;
	float a;
	for (i = 0; i < n; i++)
	{
		scanf("%f", &a);
		sum = sum + a;
		max = M(max, a);
	}
	float result;
	result = sum * 100 / (n * max);
	printf("%f", result);
}