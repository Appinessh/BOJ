#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char s[1000010] = { 0, };
	scanf("%[^\n]", &s);
	int i;
	int start = 1000009;
	for (i = 0; i < 1000010; i++)
	{
		if (s[i] == ' ')
		{
			continue;
		}
		else if (s[i] != 32 && s[i] != 0)
		{
			start = i;
			break;
		}
		else
		{
			break;
		}
	}
	if (start == 1000009)
	{
		printf("0");
		return 0;
	}
	int count = 1;
	for (i = start; i < 1000010; i++)
	{
		if (s[i + 1] == NULL || (s[i] == 32 && s[i + 1] == 32))
		{
			break;
		}
		else if (s[i] == 32)
		{
			count++;
		}
		else
		{
			continue;
		}
	}
	printf("%d", count);
	return 0;
}