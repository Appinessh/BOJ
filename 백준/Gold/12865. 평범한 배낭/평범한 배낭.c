#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct item {
	int weight;
	int value;
}item;
int compare(const void* a, const void* b)
{
	item num1 = *(item*)a;
	item num2 = *(item*)b;
	if (num1.weight > num2.weight)
	{
		return 1;
	}
	else if(num1.weight == num2.weight)
	{
		if (num1.value > num2.value)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return -1;
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int upper_bound;
	scanf("%d", &upper_bound);
	item* array = (item*)malloc(sizeof(item) * (n+1));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &array[i].weight, &array[i].value);
	}
	qsort(array, n, sizeof(item), compare);
	int** answer = (int**)malloc(sizeof(int*) * (upper_bound + 1));
	for (int i = 0; i <= upper_bound; i++)
	{
		answer[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	for (int i = 0; i <= upper_bound; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				answer[i][j] = 0;
			}
			else
			{
				if (i - array[j].weight < 0)
				{
					answer[i][j] = answer[i][j - 1];
					continue;
				}
				answer[i][j] = (answer[i - array[j].weight][j - 1] + array[j].value) > (answer[i][j - 1]) ? (answer[i - array[j].weight][j - 1] + array[j].value) : (answer[i][j - 1]);
			}
		}
	}
	printf("%d", answer[upper_bound][n]);
	free(array);
	free(answer);
	return 0;
}