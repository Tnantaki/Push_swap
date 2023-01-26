#include "sort.h"

static void	merge(int *arr, int l, int m, int r)
{
	int	n1 = m - l + 1;// sizeof left array
	int	n2 = r - m;// sizeof right array
	int	left[n1], right[n2];

	for (int i = 0; i < n1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < n2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0, j = 0, k = l;

	for (; i < n1 && j < n2; k++)
	{
		if (left[i] < right[j])
			arr[k] = left[i++];
		else
			arr[k] = right[j++];
	}
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];
}

// recursion
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void merge_sort(int arr[], int n)
{
	mergeSort(arr, 0, n - 1);
}
