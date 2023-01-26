#include "sort.h"

void	select_sort(int *arr, int n)
{
	int	min_i;

	for (int i = 0; i < n - 1; i++)
	{
		min_i = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min_i] > arr[j])
				min_i = j;
		}
		swap(&arr[min_i], &arr[i]);
	}
}