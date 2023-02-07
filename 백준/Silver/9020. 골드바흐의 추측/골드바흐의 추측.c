#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct listnode* listpointer;
typedef struct listnode {
	int data;
	listpointer link_forward;
	listpointer link_backward;
}listnode;
listpointer create(int val, listpointer last_node, listpointer tail)
{
	listpointer node;
	node = (listpointer)malloc(sizeof(listnode));
	node->data = val;
	last_node->link_forward = node;
	node->link_backward = last_node;
	node->link_forward = tail;
	tail->link_backward = node;
	return node;
}
listpointer lispo[2];
void create_wholething(int n)
{
	listpointer head, tail, last, first, search;
	head = (listpointer)malloc(sizeof(listnode));
	tail = (listpointer)malloc(sizeof(listnode));
	last = (listpointer)malloc(sizeof(listnode));
	first = (listpointer)malloc(sizeof(listnode));
	search = (listpointer)malloc(sizeof(listnode));
	head->link_forward = tail;
	head->link_backward = NULL;
	tail->link_forward = NULL;
	tail->link_backward = head;
	last = head;
	for (int i = 2; i <= n; i++)
	{
		last = create(i, last, tail);
	}

	first = head->link_forward;
	search = first->link_forward;

	while (first->link_forward != tail)
	{
		if (search->data % first->data == 0 && search != tail)
		{
			listpointer temp;
			temp = (listpointer)malloc(sizeof(listnode));
			temp = search;
			search = search->link_forward;
			temp->link_backward->link_forward = search;
			search->link_backward = temp->link_backward;
			free(temp);
		}
		else if (search->link_forward != tail && search != tail)
		{
			search = search->link_forward;
		}
		else
		{
			first = first->link_forward;
			search = first->link_forward;
		}
	}
	lispo[0] = head;
	lispo[1] = tail;
}

int solution(int n,listpointer head, listpointer tail)
{
	listpointer first, last;
	first = (listpointer)malloc(sizeof(listnode));
	last = (listpointer)malloc(sizeof(listnode));
	first = head->link_forward;
	last = tail->link_backward;
	int sum;
	int index1, index2;
	while (first != last)
	{
		sum = first->data + last->data;
		if (sum == n)
		{
			index1 = first->data;
			index2 = last->data;
			last = last->link_backward;
		}
		else if (sum > n)
		{
			last = last->link_backward;
		}
		else
		{
			first = first->link_forward;
		}
	}
	if (first->data + last->data == n)
	{
		index1 = first->data;
		index2 = index1;
	}
	printf("%d %d\n", index1, index2);
	return 0;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int)*n);
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&array[i]);
		if (max < array[i])
		{
			max = array[i];
		}
	}
	create_wholething(max);
	for (int i = 0; i < n; i++)
	{
		solution(array[i],lispo[0],lispo[1]);
	}
	return 0;
}