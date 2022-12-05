#include <stdio.h>
int main(void)
{

		int a;
		int N;
		int L;
		int k;
		int sum;
		int fact = 100;
		int i;
		scanf("%d %d", &N, &L);
		for (k = L; k <= 100; k++)
		{

			for (a = 0; a <= N / k ; a++)
			{
				sum = k * a + k * (k - 1) / 2;
				if (sum == N)
				{

					fact = 1;
					break;
				}
			}
			if (fact == 1)
			{
				break;
			}
		}
		if (k <= 100)
		{
			for (i = 0; i <= k - 1; i++)
			{
				printf("%d ", a + i);
			}
		}
		else
		{
			printf("-1");
		}
	
	return 0;

}