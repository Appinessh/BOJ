#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	char s[150][31];
	int i;
	int array[130] = {0,};
	int k = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s", &s[i]);
		array[s[i][0]]++;
		k = max(k, array[s[i][0]]);
	}
	if (k < 5)
	{
		printf("PREDAJA");
		return 0;
	}
	char ans;
	for (i = 0; i < 130; i++)
	{
		if (array[i] >= 5)
		{
			ans = i;
			printf("%c", ans);
		}
	}
	return 0;
}