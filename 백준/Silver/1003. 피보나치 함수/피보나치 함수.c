#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int i;
    int k;
    int array[10000][2];
    int a0[41];
    int a1[41];
    a0[0] = 1;
    a0[1] = 0;
    a1[0] = 0;
    a1[1] = 1;
    for (i = 2; i <= 40; i++)
    {
        a0[i] = a0[i - 1] + a0[i - 2];
        a1[i] = a1[i - 1] + a1[i - 2];
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        array[i][0] = a0[k];
        array[i][1] = a1[k];
    }
    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", array[i][0], array[i][1]);
    }
    return 0;
}