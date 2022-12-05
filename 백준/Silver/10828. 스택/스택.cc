#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void push(int list[], int top, int input)
{
	top=top+1;
	list[top] = input;
}
int pop(int list[], int top)
{
	int temp;
	temp = list[top];
	top = top - 1;
	list[top + 1] = 0;
	return temp;
}
int empty(int top)
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}
int size(int top)
{
	return top + 1;
}
int toop(int list[], int top)
{
	if (top == -1)
	{
		return -1;
	}
	return list[top];
}
int main(void)
{
	int n;
	scanf("%d", &n);
	char order[10];
	int stack[10000] = { 0, };
	int answer[10000] = { 0, };
	int i;
	int top = -1;
	int temp;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s", order);
		if (strcmp(order,"push")==0)
		{
			scanf("%d", &temp);
			push(stack, top, temp);
			top++;
		}
		else if (strcmp(order,"pop")==0)
		{
			if (top == -1)
			{
				answer[count] = -1;
				count++;
			}
			else
			{
				answer[count] = pop(stack, top);
				top--;
				count++;
			}
		}
		else if (strcmp(order, "size") == 0)
		{
			answer[count] = size(top);
			count++;
		}
		else if (strcmp(order, "empty") == 0)
		{
			answer[count] = empty(top);
			count++;
		}
		else //top
		{
			answer[count] = toop(stack, top);
			count++;
		}
	}
	for (i = 0; i < count; i++)
	{
		printf("%d\n", answer[i]);
	}
	return 0;
}