#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	char s[1000010];
	char s1;
	scanf("%[^\n]", &s);
	int array[150] = { 0, };
	int i;
	int k=0;
	int index;
	int count = 0;
	for (i = 0; i < 1000010; i++)
	{
		if (s[i] == 0)
		{
			break;
		}
		if (s[i] > 90)
		{
			array[s[i] - 32]++;
			if (max(k, array[s[i]-32]) > k)
			{
				index = s[i]-32;
				k = max(k, array[s[i]-32]);
			}
		}
		else
		{
			array[s[i]]++;
			if (max(k, array[s[i]]) > k)
			{
				index = s[i];
				k = max(k, array[s[i]]);
			}
		}
	}
	for (i = 0; i < 150; i++)
	{
		if (k == array[i])
		{
			count++;
		}
	}
	if (count >= 2)
	{
		printf("?");
	}
	else
	{
		s1 = index;
		printf("%c", s1);
	}
	return 0;
}