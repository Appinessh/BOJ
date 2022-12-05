#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int x, y,w,h;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	int a, b, c;
	a = x < w - x ? x : w - x;
	b = y < h - y ? y : h - y;
	c = a < b ? a : b;
	printf("%d", c);
}