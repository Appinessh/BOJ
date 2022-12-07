#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int push(int stack[], int top, int value)
{
	top++;
	stack[top] = value;
	return top;
}
int pop(int stack[], int top)
{
	stack[top] = 0;
	top--;
	return top;
}
int empty(int top)
{
	if (top < 0)
	{
		return 1;
	}
	return 0;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array;
	array = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int* stack;
	stack = (int*)malloc(sizeof(int) * n);
	int top = -1;
	int* answer;
	answer = (int*)malloc(sizeof(int) * n);
	for (i = n - 1; i >= 0; i--)
	{
		if (empty(top))
		{
			answer[i] = -1;
			top=push(stack, top, array[i]);
			continue;
		}
		if (stack[top] > array[i])
		{
			answer[i] = stack[top];
			top = push(stack, top, array[i]);
		}
		else
		{
			while (!empty(top)&&stack[top]<=array[i])
			{
				top = pop(stack, top);
			}
			if (empty(top))
			{
				answer[i] = -1;
				top=push(stack, top, array[i]);
				continue;
			}
			answer[i] = stack[top];
			top = push(stack, top, array[i]);
		}

	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", answer[i]);
	}
	free(array);
	free(answer);
	free(stack);
	return 0;
}