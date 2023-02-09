#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
int compare(const void *a,const void*b)
{
    int num1=*(int*)a;
    int num2=*(int*)b;
    if(num1>num2)
    {
        return 1;
    }
    else return -1;
}
int main(void)
{
	int n, upper_bound;
	scanf("%d%d", &n, &upper_bound);
	int* array = (int*)malloc(sizeof(int) * n);
	int* answer = (int*)malloc(sizeof(int) * (upper_bound+1));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	qsort(array,n,sizeof(int),compare);
	for (int i = 0; i <= upper_bound; i++)
	{
		answer[i] = 0;
	}
	for (int i = 1; i <= upper_bound; i++)
	{
		int min = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if (i - array[j] > 0)
			{
				if (answer[i - array[j]] != 0)
				{
					min = min < (answer[i - array[j]] + 1) ? min : (answer[i - array[j]] + 1);
					answer[i] = min;
				}
				else
				{
					continue;
				}
			}
			else if (i == array[j])
			{
				answer[i] = 1;
			}
			else
			{
				
			}
		}
	}
	if (answer[upper_bound] == 0)
	{
		printf("-1");
		free(array);
		free(answer);
		return 0;
	}
	printf("%d", answer[upper_bound]);
	free(array);
	free(answer);
	return 0;
}