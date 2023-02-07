#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct listnode* listpointer;
typedef struct listnode{
	int data;
	listpointer link;
}listnode;
listpointer create(int val)
{
	listpointer node;
	node = (listpointer)malloc(sizeof(listnode));
	node->data = val;
	node->link = NULL;
	return node;
}
int count;
int delete(int val, listpointer head, int k)
{
	listpointer temp,last;
	int value;
	temp = head->link;
	last = head;
	while (temp != NULL)
	{
		if (temp->data % val == 0)
		{
			value = temp->data;
			last->link = temp->link;
			temp = last->link;
			count++;
			if (count == k)
			{
				return value;
			}
		}
		else
		{
			last = temp;
			temp = temp->link;
		}

	}
	return 0;
}
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	listpointer head,next;
	head = (listpointer)malloc(sizeof(listnode));
	next = (listpointer)malloc(sizeof(listnode));
	head->data = 0;
	head->link = NULL;
	for (int i = 2; i <= n; i++)
	{
		listpointer new_node;
		new_node = create(i);
		if (head->link == NULL)
		{
			head->link = new_node;
			next = new_node;
		}
		else
		{
			next->link = new_node;
			next = new_node;
		}
	}
	int val;
	int answer;
	count = 0;
	while (1)
	{
		val = head->link->data;
		answer = delete(val, head, k);
		if (answer != 0)
		{
			break;
		}
	}
	printf("%d", answer);
	return 0;
}