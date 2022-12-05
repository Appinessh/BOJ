#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	int a[100000][2];
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i][0], &a[i][1]);
		a[i][0] = a[i][0] % 10;
	}
	for (i = 0; i < n; i++)
	{
		switch (a[i][0])
		{
		case 1:
			printf("1\n");
			break;
		case 2:
			if (a[i][1] % 4 == 1)
			{
				printf("2\n");
				break;
			}
			else if (a[i][1] % 4 == 2)
			{
				printf("4\n");
				break;
			}
			else if (a[i][1] % 4 == 3)
			{
				printf("8\n");
				break;
			}
			else
			{
				printf("6\n");
				break;
			}
		case 3:
			if (a[i][1] % 4 == 1)
			{
				printf("3\n");
				break;
			}
			else if (a[i][1] % 4 == 2)
			{
				printf("9\n");
				break;
			}
			else if (a[i][1] % 4 == 3)
			{
				printf("7\n");
				break;
			}
			else
			{
				printf("1\n");
				break;
			}
		case 4:
			if (a[i][1] % 4 == 1)
			{
				printf("4\n");
				break;
			}
			else if (a[i][1] % 4 == 2)
			{
				printf("6\n");
				break;
			}
			else if (a[i][1] % 4 == 3)
			{
				printf("4\n");
				break;
			}
			else
			{
				printf("6\n");
				break;
			}
		case 5:
			printf("5\n");
			break;
		case 6:
			printf("6\n");
			break;
		case 7:
			if (a[i][1] % 4 == 1)
			{
				printf("7\n");
				break;
			}
			else if (a[i][1] % 4 == 2)
			{
				printf("9\n");
				break;
			}
			else if (a[i][1] % 4 == 3)
			{
				printf("3\n");
				break;
			}
			else
			{
				printf("1\n");
				break;
			}
		case 8:
			if (a[i][1] % 4 == 1)
			{
				printf("8\n");
				break;
			}
			else if (a[i][1] % 4 == 2)
			{
				printf("4\n");
				break;
			}
			else if (a[i][1] % 4 == 3)
			{
				printf("2\n");
				break;
			}
			else
			{
				printf("6\n");
				break;
			}
		case 9:
			if (a[i][1] % 4 == 1)
			{
				printf("9\n");
				break;
			}
			else if (a[i][1] % 4 == 2)
			{
				printf("1\n");
				break;
			}
			else if (a[i][1] % 4 == 3)
			{
				printf("9\n");
				break;
			}
			else
			{
				printf("1\n");
				break;
			}
		case 0:
			printf("10\n");
			break;
        default :
            break;
		}
	}
	return 0;
}