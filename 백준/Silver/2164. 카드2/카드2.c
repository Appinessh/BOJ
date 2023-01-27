#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int top, bottom;
int list[1000000];
void push(int a)
{
    list[++top] = a;
}
int pop(void)
{
    int a;
    a = list[bottom];
    list[bottom] = 0;
    bottom++;
    return a;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int i;
    bottom = 0;
    top = n - 1;
    for (i = 0; i < n; i++)
    {
        list[i] = i+1;
    }
    int a;
    while (top != bottom)
    {
        pop();
        a = pop();
        push(a);
    }
    printf("%d", list[top]);
    return 0;
}