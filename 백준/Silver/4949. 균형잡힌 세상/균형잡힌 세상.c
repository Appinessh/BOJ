#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int top;
char stack[100];
void push(char s)
{
	stack[++top] = s;
}
void pop(void)
{
	stack[top--] = '\0';
}
void result(char* s, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']')
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
				else if (s[i] == ']' && stack[top] == '[')
				{
					pop();
				}
				else
				{
					push(s[i]);
				}
			}
		}
	}
	if (top == -1)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}
int main(void)
{
	char str[100];
	while (1)
	{
		top = -1;
		gets(str);
		if (strcmp(str, ".") == 0)
		{
			break;
		}
		result(str, strlen(str));
	}
}