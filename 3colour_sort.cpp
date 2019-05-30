// 3colour_sort.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include<stdlib.h>

void print(int *a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void color_swap(int *a,int n)
{
	int i, sum = 0, count_two = 0, l = n - 1;
	for (i = 0; i < n; i++)
	{
		sum += a[i];
		if (a[i] == 2)
			count_two += 1;
	}
	int sum_0_1 = (sum-2 * count_two );
	while (count_two > 0)
	{
		a[l--] = 2;
		count_two--;
	}
	while (sum_0_1 > 0)
	{
		a[l--] = 1;
		sum_0_1--;
	}
	while (l >= 0)
		a[l--] = 0;
	print(a, n);
}

void testswap()
{
	int n;
	scanf("%d", &n);
	int *a=(int *)malloc(n*sizeof(int));
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	color_swap(a, n);
}

int main()
{
	testswap();
	return 0;
}

