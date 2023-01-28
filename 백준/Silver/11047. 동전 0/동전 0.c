#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	int i;
	int* list = (int*)malloc(sizeof(int) * n);
	int a;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a > k)
		{
			break;
		}
		list[i] = a;
	}
	int count = 0;
	int j;
	int index = 2;
	int max = list[i - 1];
	int x;
	while (k!=0)
	{
		x = k / max;
		count = count + x;
		k = k % max;
		max = list[i - index];
		index++;
	}
	printf("%d", count);
	return 0;
}