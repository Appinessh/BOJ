#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int top = -1;
void push(int* stack,int val)
{
	top++;
	stack[top] = val;
}
void pop(int* stack)
{
	stack[top] = 0;
	top--;
}
int number_of_pop(int* stack, int new)
{
	int index = top;
	int count = 0;
	while (stack[index] < new&&index>=0)
	{
		count++;
		index--;
	}
	return count;
}
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	int* input = (int*)malloc(sizeof(int) * n);
	int* stack = (int*)malloc(sizeof(int) * n);
	int max = INT_MIN;
	int count=0;
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &input[i]);
		if (top == -1)
		{
			push(stack, input[i]);
			max = input[i];
			continue;
		}
		if (stack[top] < input[i]&&count<k)
		{
			if (number_of_pop(stack, input[i]) <= k - count)
			{
				int index = number_of_pop(stack, input[i]);
				while (index > 0)
				{
					pop(stack);
					count++;
					index--;
				}
				push(stack, input[i]);
			}
			else
			{
				while (count != k)
				{
					pop(stack);
					count++;
				}
				push(stack, input[i]);
			}
		}
		else
		{
			push(stack, input[i]);
		}

	}
	for (int i = 0; i < n - k; i++)
	{
		printf("%d", stack[i]);
	}
	free(stack);
	free(input);
	return 0;
}