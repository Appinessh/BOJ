#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sequence[100000];
int stack[100001] = { 0, };
int index_sequence;
int index_stack;
int print[200000];
int index_print;
void push(int stack[], int i, int top, int print[],int index_print)
{
	top++;
	stack[top] = i;
	print[index_print] = 1;
}
void pop(int stack[], int top,int print[], int index_print)
{
	stack[top] = 0;
	top--;
	print[index_print] = -1;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	index_sequence=0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &sequence[i]);
	}
	index_stack = 0;
	i = 1;
	index_print = 0;
	int indicator=0;
	while (index_sequence < n)
	{
		while (stack[index_stack] < sequence[index_sequence])
		{
			push(stack, i, index_stack,print,index_print);
			i++;
			index_stack++;
			index_print++;
		}
		if (sequence[index_sequence] == stack[index_stack])
		{
			pop(stack, index_stack,print,index_print);
			index_stack--;
			index_sequence++;
			index_print++;
		}
		else
		{
			indicator = 1;
			break;
		}
	}
	if (indicator == 1)
	{
		printf("NO");
		return 0;
	}
	for (i = 0; i < index_print; i++)
	{
		if (print[i] == 1)
		{
			printf("+\n");
		}
		else
		{
			printf("-\n");
		}
	}
	return 0;
}