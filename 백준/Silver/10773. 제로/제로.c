#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int push(int list[], int n, int top)
{
	top++;
	list[top] = n;
	return top;
}
int pop(int list[], int top)
{
	if (top == -1)
	{
		return 0;
	}
	list[top] = 0;
	top--;
	return top;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int list[100000];
	int i;
	int k;
	int top=-1;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		if (k != 0)
		{
			top=push(list,k,top);
			
		}
		else
		{
			top=pop(list,top);
		}
	}
	int answer=0;
	for (i = 0; i <= top; i++)
	{
		answer = answer + list[i];
	}
	printf("%d", answer);
	return 0;
}