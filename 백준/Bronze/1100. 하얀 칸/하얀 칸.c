#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char s[10][10];
	int count = 0;
	int i, j;
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			scanf("%c", &s[i][j]);
			if ((i + j) % 2 == 0 && s[i][j] == 'F')
			{
				count++;
			}
		}
		getchar();
	}
	printf("%d", count);
}