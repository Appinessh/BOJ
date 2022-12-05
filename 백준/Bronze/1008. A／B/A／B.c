#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	double a, b;
	scanf("%lf%lf", &a, &b);
	double c;
	c = a / b;
	printf("%.9lf", c);
}