#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<math.h>
void searching(long long int a[], int array[], int n)
{
	int i;
	int count = 0;
	int j;
	int b;
	for (b = 0; b < n; b++)
	{
		count = 0;
		for (i = b + 1; i < n; i++)
		{
			if (i == b + 1)
			{
				count++;
				array[i]++;
				j = b + 1;
				continue;
			}
			if ((j-b)*(a[i]-a[b])>(i-b)*(a[j]-a[b]))
			{
				//printf("%d\n%d\n", (j - b) * (a[i] - a[b]), (i - b) * (a[j] - a[b]));
				count++;
				array[i]++;
				j = i;
			}

		}
		array[b] = array[b]+count;
	}
}
int main(void) {
	long long int a[50] = { 0, };
	int array[50] = { 0, };
	int k;
	int i;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		scanf("%d", &a[i]);

	}
	searching(a, array, k);
	int max=0;
	int index;
	for (i = 0; i < k; i++)
	{
		if (max < array[i])
		{
			max = array[i];
			index = i;
		}
		//printf("array[%d]=%d\n", i, array[i]);
	}
	//printf("\n");
	//printf("array[%d]=%d",index, max);
	printf("%d", max);
	return 0;
}