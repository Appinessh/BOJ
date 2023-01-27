#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int stack[2000000] = { 0, };
int top;
int bottom;
void push(int a)
{
	stack[++top] = a;
	if (bottom == -1)
	{
		bottom++;
	}
}
void pop(void)
{
	if (empty())
	{
		printf("-1\n");
	}
  else if(empty()==0&&top==bottom)
  {
    printf("%d\n", stack[bottom]);
		stack[bottom++] = 0;
    top=-1;
    bottom=-1;
  }
	else
	{
		printf("%d\n", stack[bottom]);
		stack[bottom++] = 0;
	}

}
int empty(void)
{
	if (top == bottom && stack[top] == 0)
	{
		return 1;
	}
	return 0;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	char str[10];
	int a;
	top = -1;
	bottom = -1;
	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &a);
			push(a);
		}
		else if (strcmp(str, "front") == 0)
		{
			if (empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", stack[bottom]);
			}
		}
		else if (strcmp(str, "back") == 0)
		{
			if (empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", stack[top]);
			}
		}
		else if (strcmp(str, "pop") == 0)
		{
			pop();
		}
		else if (strcmp(str, "size") == 0)
		{
			if (empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", top - bottom + 1);
			}
		}
		else // empty
		{
			if (empty())
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}

		}
	}
}