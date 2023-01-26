#include "sort.h"

void	printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void	swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int	get_max(int *arr, int n)
{
	int	max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

int	get_min(int *arr, int n)
{
	int	min = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return (min);
}