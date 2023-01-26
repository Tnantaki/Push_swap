#include "sort.h"

void countSort(int arr[], int n, int exp)
{
	int	output[n]; // output array
	int	count[10] = {0}; 
	int	i;

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void	radix_sort(int *arr, int n)
{
	int max = get_max(arr, n);

	for (int exp = 1; max / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}