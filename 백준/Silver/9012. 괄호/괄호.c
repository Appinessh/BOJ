#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
char stack[100];
int top;
void push(char s)
{
	stack[++top] = s;
}
void pop(void)
{
	stack[top--] = "\0";
}
void result(char *s, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (top == -1)
		{
			push(s[i]);
		}
		else
		{
			if (s[i] == ')' && stack[top] == '(')
			{
				pop();
			}
			else
			{
				push(s[i]);
			}
		}
	}
	if (top == -1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
int main(void)
{
	int n;
	scanf("%d%*c", &n);
	char str[100];
	while (n > 0)
	{
		top = -1;
		n--;
		gets(str);
		result(str, strlen(str));
	}
	return 0;
}