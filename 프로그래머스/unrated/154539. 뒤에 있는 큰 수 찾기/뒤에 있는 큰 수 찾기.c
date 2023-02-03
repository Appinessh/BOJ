#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int top=-1;
void push(int*stack, int top, int val)
{
    stack[++top]=val;
}
void pop(int*stack, int top)
{
    stack[top--]=0;
}
// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*numbers_len);
    int* stack=(int*)malloc(sizeof(int)*numbers_len);
    int i;
    for(i=0;i<numbers_len;i++)
    {
        if(top==-1)
        {
            push(stack,top,numbers[numbers_len-1-i]);
            top++;
            answer[numbers_len-1-i]=-1;
        }
        else if(stack[top]>numbers[numbers_len-1-i])
        {
            answer[numbers_len-1-i]=stack[top];
            push(stack,top,numbers[numbers_len-1-i]);
            top++;
        }
        else
        {
            while(stack[top]<=numbers[numbers_len-1-i]&&top!=-1)
            {
                pop(stack,top);
                top--;
            }
            if(top==-1)
            {
                answer[numbers_len-1-i]=-1;
            }
            else
            {
                answer[numbers_len-1-i]=stack[top];
            }
            push(stack,top,numbers[numbers_len-1-i]);
            top++;
        }
    }
    return answer;
}