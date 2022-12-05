#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char a[10001] = { 0, };
	char b[10001] = { 0, };
	scanf("%s%s", &a,&b);
	int i;
	long long int counta=0;
	long long int countb=0;;
	for (i = 0; i < 10001; i++)
	{
		if (a[i] != 0)
		{
			switch (a[i])
			{
			case 48:
				counta = counta + 0;
				break;
			case 49:
				counta = counta + 1;
				break;
			case 50:
				counta = counta + 2;
				break;
			case 51:
				counta = counta + 3;
				break;
			case 52:
				counta = counta + 4;
				break;
			case 53:
				counta = counta + 5;
				break;
			case 54:
				counta = counta + 6;
				break;
			case 55:
				counta = counta + 7;
				break;
			case 56:
				counta = counta + 8;
				break;
			case 57:
				counta = counta + 9;
				break;
			}
		}
		if (b[i] != 0)
		{
			switch (b[i])
			{
			case 48:
				countb = countb + 0;
				break;
			case 49:
				countb = countb + 1;
				break;
			case 50:
				countb = countb + 2;
				break;
			case 51:
				countb = countb + 3;
				break;
			case 52:
				countb = countb + 4;
				break;
			case 53:
				countb = countb + 5;
				break;
			case 54:
				countb = countb + 6;
				break;
			case 55:
				countb = countb + 7;
				break;
			case 56:
				countb = countb + 8;
				break;
			case 57:
				countb = countb + 9;
				break;
			}
		}
		if (a[i] == 0 && b[i] == 0)
		{
			break;
		}
	}
	long long int k;
	k = counta * countb;
	printf("%lld", k);
}