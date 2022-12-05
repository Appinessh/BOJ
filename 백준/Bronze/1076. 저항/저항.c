#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main(void)
{
	char s1[10] = { 0, };
	char s2[10] = { 0, };
	char s3[10] = { 0, };
	int s[3];
	int i;
	scanf("%s%s%s", &s1, &s2, &s3);
	if (!strcmp(s1,"black"))
	{
		s[0] = 0;
	}
	else if (!strcmp(s1, "brown"))
	{
		s[0] = 1;
	}
	else if (!strcmp(s1, "red"))
	{
		s[0] = 2;
	}
	else if (!strcmp(s1, "orange"))
	{
		s[0] = 3;
	}
	else if (!strcmp(s1, "yellow"))
	{
		s[0] = 4;
	}
	else if (!strcmp(s1, "green"))
	{
		s[0] = 5;
	}
	else if (!strcmp(s1, "blue"))
	{
		s[0] = 6;
	}
	else if (!strcmp(s1, "violet"))
	{
		s[0] = 7;
	}
	else if (!strcmp(s1, "grey"))
	{
		s[0] = 8;
	}
	else if (!strcmp(s1, "white"))
	{
		s[0] = 9;
	}
	//
	if (!strcmp(s2, "black"))
	{
		s[1] = 0;
	}
	else if (!strcmp(s2, "brown"))
	{
		s[1] = 1;
	}
	else if (!strcmp(s2, "red"))
	{
		s[1] = 2;
	}
	else if (!strcmp(s2, "orange"))
	{
		s[1] = 3;
	}
	else if (!strcmp(s2, "yellow"))
	{
		s[1] = 4;
	}
	else if (!strcmp(s2, "green"))
	{
		s[1] = 5;
	}
	else if (!strcmp(s2, "blue"))
	{
		s[1] = 6;
	}
	else if (!strcmp(s2, "violet"))
	{
		s[1] = 7;
	}
	else if (!strcmp(s2, "grey"))
	{
		s[1] = 8;
	}
	else if (!strcmp(s2, "white"))
	{
		s[1] = 9;
	}
	//
	if (!strcmp(s3, "black"))
	{
		s[2] = 0;
	}
	else if (!strcmp(s3, "brown"))
	{
		s[2] = 1;
	}
	else if (!strcmp(s3, "red"))
	{
		s[2] = 2;
	}
	else if (!strcmp(s3, "orange"))
	{
		s[2] = 3;
	}
	else if (!strcmp(s3, "yellow"))
	{
		s[2] = 4;
	}
	else if (!strcmp(s3, "green"))
	{
		s[2] = 5;
	}
	else if (!strcmp(s3, "blue"))
	{
		s[2] = 6;
	}
	else if (!strcmp(s3, "violet"))
	{
		s[2] = 7;
	}
	else if (!strcmp(s3, "grey"))
	{
		s[2] = 8;
	}
	else if (!strcmp(s3, "white"))
	{
		s[2] = 9;
	}
	int a;
	a = 10 * s[0] + s[1];
	if (a == 0)
	{
		printf("0");
		return 0;
	}
	printf("%d", a);
	for (i = 0; i < s[2]; i++)
	{
		printf("0");
	}
	return 0;
}