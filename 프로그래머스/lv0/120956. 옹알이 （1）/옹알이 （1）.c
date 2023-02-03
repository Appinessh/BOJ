#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    char *test;
    int indi[4]={0,};
    int sal=0;
    for(int i=0;i<babbling_len;i++)
    {
        test=babbling[i];
        indi[0]=0;indi[1]=0;indi[2]=0;indi[3]=0;
        int j=0;
        sal=0;
        while(j<strlen(test))
        {
            if(test[j]=='a'&&test[j+1]=='y'&&test[j+2]=='a'&&indi[0]==0)
            {
                j=j+3;
                indi[0]=1;
            }
            else if(test[j]=='y'&&test[j+1]=='e'&&indi[1]==0)
            {
                j=j+2;
                indi[1]=1;
            }
            else if(test[j]=='w'&&test[j+1]=='o'&&test[j+2]=='o'&&indi[2]==0)
            {
                j=j+3;
                indi[2]=1;
            }
            else if(test[j]=='m'&&test[j+1]=='a'&&indi[3]==0)
            {
                j=j+2;
                indi[3]=1;
            }
            else
            {
                sal=-1;
                break;
            }
        }
        if(sal!=-1)
        {
            answer++;
        }
    }
    return answer;
}