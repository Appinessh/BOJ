#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <math.h>
int dist(int x1, int y1, int x2, int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i,j;
	int event[1002][2];
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &event[i][0], &event[i][1]);
	}
	event[0][0] = 1;
	event[0][1] = 1;
	event[m+1][0] = n;
	event[m+1][1] = n;
	int distance[1002][1002];
	for (i = 0; i <= m + 1; i++)
	{
		for (j = 0; j <= m+1; j++)
		{
			distance[i][j] = dist(event[i][0], event[i][1], event[j][0], event[j][1]);
			//printf("%d ", distance[i][j]);
		}
		//printf("\n");
	}
	
	int trackingdistance[1000][2][1001] = { 0, };
	int trackingcar[1000][2][1001];
	trackingdistance[0][0][1] = distance[m + 1][1];
	//printf("trackingdistance[0][0][1]=%d\n", trackingdistance[0][0][1]);
	trackingcar[0][0][1] = 2;
	trackingdistance[0][1][1] = distance[0][1];
	//printf("trackingdistance[0][1][1]=%d\n", trackingdistance[0][1][1]);
	trackingcar[0][1][1] = 1;
	for (j =2 ; j <= m; j++)
	{
		trackingdistance[0][0][j] = trackingdistance[0][0][j - 1] + distance[j - 1][j];
		trackingcar[0][0][j] = 2;
		trackingdistance[0][1][j] = trackingdistance[0][1][j - 1] + distance[j - 1][j];
		trackingcar[0][1][j] = 1;
	}
	for (j = 2; j <= m; j++)
	{
		for (i = 1; i < j - 1; i++)
		{
			trackingdistance[i][0][j] = trackingdistance[i][0][j - 1] + distance[j - 1][j];
			trackingcar[i][0][j] = 2;
			trackingdistance[i][1][j] = trackingdistance[i][1][j - 1] + distance[j - 1][j];
			trackingcar[i][1][j] = 1;
		}
		int index=0;
		trackingdistance[j - 1][0][j] = trackingdistance[0][1][j - 1] + distance[m + 1][j];//
		for (i = 1; i <= j - 2; i++)
		{
			trackingdistance[j - 1][0][j] = min(trackingdistance[j - 1][0][j], trackingdistance[i][1][j - 1] + distance[i][j]);
			if (trackingdistance[j - 1][0][j] == trackingdistance[i][1][j - 1] + distance[i][j])
			{
				index = i;
			}
		}
		for (i = 1; i < j; i++)
		{
			trackingcar[j - 1][0][i] = trackingcar[index][1][i];
		}
		trackingcar[j - 1][0][j] = 2;

		index = 0;
		trackingdistance[j - 1][1][j] = trackingdistance[0][0][j - 1] + distance[0][j];
		for (i = 1; i <= j - 2; i++)
		{
			trackingdistance[j - 1][1][j] = min(trackingdistance[j - 1][1][j], trackingdistance[i][0][j - 1] + distance[i][j]);
			if (trackingdistance[j - 1][1][j] == trackingdistance[i][0][j - 1] + distance[i][j])
			{
				index = i;
			}
		}
		for (i = 1; i <= j - 1; i++)
		{
			trackingcar[j - 1][1][i] = trackingcar[index][0][i];
		}
		trackingcar[j - 1][1][j] = 1;
	}
	int index1, index2;
	int minimum = INT_MAX;
	for (i = 0; i <= m - 1; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			minimum = min(minimum, trackingdistance[i][j][m]);
			if (minimum == trackingdistance[i][j][m])
			{
				index1 = i;
				index2 = j;
			}
		}
	}
	printf("%d\n", trackingdistance[index1][index2][m]);
	for (i = 1; i <= m; i++)
	{
		printf("%d\n",trackingcar[index1][index2][i]);
	}
	//printf("\n\n");
	for (i = 1; i <= m; i++)
	{
		for (j = 0; j <= m - 1; j++)
		{
			//printf("%d %d\n", trackingdistance[j][0][i], trackingdistance[j][1][i]);
		}
		//printf("\n\n\n");
	}
	return 0;
}