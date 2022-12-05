#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char num[333335];
	scanf("%s", &num);
	int i;
	if (num[0] == 48)
	{
		printf("0");
		return 0;
	}
	switch (num[0])
	{
	case 49:
		printf("1");
		break;
	case 50:
		printf("10");
		break;
	case 51:
		printf("11");
		break;
	case 52:
		printf("100");
		break;
	case 53:
		printf("101");
		break;
	case 54:
		printf("110");
		break;
	case 55:
		printf("111");
		break;

	}
	for (i = 1; i < 333335; i++)
	{
		if (num[i] == NULL)
		{
			break;
		}
		switch (num[i])
		{
		case 48:
			printf("000");
			break;
		case 49:
			printf("001");
			break;
		case 50:
			printf("010");
			break;
		case 51:
			printf("011");
			break;
		case 52:
			printf("100");
			break;
		case 53:
			printf("101");
			break;
		case 54:
			printf("110");
			break;
		case 55:
			printf("111");
			break;
		}
	}
	return 0;
}