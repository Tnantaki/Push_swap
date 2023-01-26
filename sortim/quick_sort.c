#include "sort.h"
//quick sort take the pivot index and put them to the right position
//and separate to side, side of greater than pivot and side of less than

int	partition(int arr[], int low, int high)
{
	int	pivot = arr[high];
	int	i = low;
	int	j = low;

	for (; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			if (i < j)
				swap(&arr[i], &arr[j]);
			i++;
		}
	}
	if (i < j)
		swap(&arr[i], &arr[j]);
	return (i);// return (pivot index)
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);// put pivot in the right index

		quickSort(arr, low, pi - 1);// side of less than pivot
		quickSort(arr, pi + 1, high);// side of greater than pivot
	}
}

void	quick_sort(int *arr, int n)
{
	quickSort(arr, 0, n - 1);
}